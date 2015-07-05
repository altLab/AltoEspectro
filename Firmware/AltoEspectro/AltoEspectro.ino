/*
 *
When pin 4 of the ILX544A
- is connected to the 5V VCC the Sensor works in Store and Wipe Mode
- is connected to the ground the Sensor works in Store and Hold Mode
ADC
usualy the Atmega takes 13 adc Clock pulses to make a readout.
with a prescaler of 128 the adc clock is running at 125  Khz at this clock each readout takes 104uS
with a prescaler of 16  the adc clock is running at 1000 KHz the readout takes 13  uS
with a prescaler of 8   the adc clock is running at 2000 Khz the readout takes 6.5 uS

*/

#define FOSC 16000000

#ifndef F_CPU
#define F_CPU 1600000UL
#endif

#define Mode 0          //Default Mode 0 = Text; Mode 1 = binary

#define ROG  PORTB0     //Port used for the Release of Gate - pin8 in Arduino Uno
#define CLK  PORTB1     //Port used for the clock - Pin9 in Arduino Uno
#define SH PORTB2       //Port used for the Store and Hold - pin10
#define COOLING PORTB3  //Port used for the digital IO for the Peltier Circuit

#define FAN PORTD6      //Port used for the PWM Controling of the Fan

#define BAUD 9600
//#define USART_BAUDARATE 38400
#define UBRR_VALUE (FOSC/(16*BAUD))-1


#define VER "0_3_3"

//ILX544A signal sequence
#define dsignal1 12
#define opticalblack 18
#define dsignal2 2

#define pixelcount 2048
//uint16_t pixelcount = 2048;

#define dsignal3 12
#define clockdelay 1   //the time that the pulse is keept Low or High in microseconds

long exposure = 0;

//timestamp global variable used to timestamp the exposures
unsigned long timestamp = 0;

#define ADC_CCD 0
#define ADC_peltier 1
#define ADC_heatsink 2

float peltiertemp = 0;
float heatsinktemp = 0;

//ROG and ClK Pulse typical is 5000 nS or 5 uS
//432Khz delay = 1uS
//262Khz delay = 2uS
//171Khz delay = 3uS
//127Khz delay = 4uS
//100Khz delay = 5uS

//Counters for the Cycles
uint8_t start_counter = 0;
uint8_t dsignal1_counter = 0;
uint8_t opticalblack_counter = 0;
uint8_t dsignal2_counter = 0;
uint16_t pixelcount_counter = 0;
uint8_t dsignal3_counter = 0;

#define buffersize 12
char value[4];


uint16_t sensorValue = 0;

uint16_t counter = 0;

char data;
char command[buffersize];

unsigned long ellapsedtime = 0;
unsigned long starttime = 0;


#include <SoftwareSerial.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include <HardwareSerial.h>
#include <inttypes.h>
#include <util/setbaud.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <avr/pgmspace.h>

#include "commands.h"


void InitADC()
{
  //analog Ref on Pin 20 = 4.89V for USB power

  // TODO Constant to correct value

  //select VRef = AVCC
  ADMUX |= (1 << REFS0);
  //set the Prescaler to 8 and enable ADC with a prescaler of 8 the
  //adc frequency will be at 2 000 000 Hz
  /*
  Division Factor 2 2 4 8 16 32 64 128
  adsps2          0 0 0 0  1  1  1  1
  adsps1          0 0 1 1  0  0  1  1
  adsps0          0 1 0 1  0  1  0  1
  */
  ADCSRA |= (1 << ADEN) | (0 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

}

uint16_t ReadADC(uint8_t ADCchannel)
{
  ADCchannel &= 0b00000111; //and op with 7
  //select ADC channel with safety mask
  ADMUX = (ADMUX & 0xF8) | ADCchannel;
  //single conversion mode
  ADCSRA |= (1 << ADSC);
  // wait until ADC conversion is complete
  while ( ADCSRA & (1 << ADSC) );
  return (ADC);
}

void USART_Init( unsigned int baud )
{
  //Disable power consumption Mode by setting PRUSART Register to 0
  (0 << PRUSART0);
  UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
  UBRR0L = (unsigned char) UBRR_VALUE;
  /* Setting the XCKn port pin as output, enables master
  mode. */
  //XCK0_DDR |= (1<<XCK0);
  /* Set MSPI mode of operation and SPI data mode 0. */
  UCSR0C = (0 << UMSEL01) | (1 << UMSEL00) | (0 << UCPHA0) | (0 << UCPOL0);
  /* Enable receiver and transmitter. */
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  /* Enable frame format */
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);
  /* Set baud rate. */
  /* IMPORTANT: The Baud Rate must be set after the
  transmitter is enabled */
  UBRR0 = baud;
}


void USART_Transmit(char data)
{
  /* Wait for empty transmit buffer */
  while ( !( UCSR0A & (1 << UDRE0)) )
    ;
  /* Put data into buffer, sends the data */
  UDR0 = data;
}

unsigned char USART_Receive(void)
{
  while (!(UCSR0A) & (1 << RXC0));
  return UDR0;
}



void USART_Transmit_S(char *str)
{
  while (*str)
  {
    USART_Transmit(*str);
    str++;
  }
}

void USART_Transmit_uint16(uint16_t value16)
{
  char char1 = value16 & 0xFF;
  char char2 = value16 >> 8;
  USART_Transmit(char1);
  USART_Transmit(char2);

}

void senddata(uint16_t _sensorValue)
{

  // itoa(_sensorValue,value,4);  //Convert the sensor value to a char array
  sprintf(value, "%u", _sensorValue); // format it to be printed as a str
  USART_Transmit_S(value);
  USART_Transmit_S("\r\n");
}

void getexposure()
{

  //Initial Release of Gate
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 0
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 0
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (0 << CLK)  ; // 1
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 2
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 3
  _delay_us(clockdelay);
  PORTB = (0 <<  ROG) | (1 << CLK)  ; // 4
  _delay_us(clockdelay);
  PORTB = (0 <<  ROG) | (1 << CLK)  ; // 5
  _delay_us(clockdelay);
  PORTB = (0 <<  ROG) | (1 << CLK)  ; // 6
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 7
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 8
  _delay_us(clockdelay);
  PORTB = (1 <<  ROG) | (1 << CLK)  ; // 9
  _delay_us(clockdelay);

  //Process the dummy Signalare 12 clock cycles
  do
  {
    PORTB = (1 <<  ROG) | (0 << CLK)  ; // 7
    _delay_us(clockdelay);
    PORTB = (1 <<  ROG) | (1 << CLK)  ; // 7
    dsignal1_counter++;
  } while (dsignal1_counter < dsignal1);

  //process optical black pixels 18 clock cycles
  do
  {
    PORTB = (1 <<  ROG) | (0 << CLK)  ; // 7
    _delay_us(clockdelay);
    PORTB = (1 <<  ROG) | (1 << CLK)  ; // 7
    _delay_us(clockdelay);
    opticalblack_counter++;
  } while (opticalblack_counter < opticalblack);


  //process two extra dummy signals
  do {
    PORTB = (1 <<  ROG) | (0 << CLK)  ; // 7
    _delay_us(clockdelay);
    PORTB = (1 <<  ROG) | (1 << CLK)  ; // 7
    _delay_us(clockdelay);
    dsignal2_counter++;
  } while (dsignal2_counter < dsignal2);


  //process 2048 signals
  //don't forget that the ADC takes 13uS to process the Analog to digital conversion
  // or not
  do {
    PORTB = (1 <<  ROG) | (0 << CLK)  ;
    sensorValue = ReadADC(0);
    //Prototype function to send bytes instead of chars
    //      USART_Transmit_uint16(sensorValue);
    //Prototype function to send chars
    senddata(0);
    _delay_us(clockdelay);

    PORTB = (1 <<  ROG) | (1 << CLK)  ;
    sensorValue = ReadADC(0);
    //Prototype function to send bytes instead of chars
    //      USART_Transmit_uint16(sensorValue);
    //Prototype function to send chars
    senddata(sensorValue);
    _delay_us(clockdelay);

    pixelcount_counter++;
  } while (pixelcount_counter < pixelcount);


  //process two extra dummy signals
  do {
    PORTB = (1 <<  ROG) | (0 << CLK)  ; // 7
    _delay_us(clockdelay);
    PORTB = (1 <<  ROG) | (1 << CLK)  ; // 7
    _delay_us(clockdelay);

    dsignal3_counter++;
  } while (dsignal3_counter < dsignal3);



  dsignal1_counter = 0;
  opticalblack_counter = 0;
  dsignal2_counter = 0;
  pixelcount_counter = 0;
  dsignal3_counter = 0;


}


uint16_t sensortemp() {
  //var
  uint16_t temp = 0;
  temp = ReadADC(1);
  return temp;
}

void updateTemp()
{
  peltiertemp = ReadADC(ADC_peltier);
  heatsinktemp = ReadADC(ADC_heatsink);
}

void processtextmodecommand(char* data)
{
  switch (data[3])
  {
    case INIT_T:
      USART_Transmit_S(NACK);
      USART_Transmit(SPACE);
      USART_Transmit_S(VER);
      USART_Transmit(CR);
      break;

    case SET_TIMESTAMP_T:
      USART_Transmit_S(NACK);
      USART_Transmit(SPACE);
      USART_Transmit(SET_TIMESTAMP_T);
      USART_Transmit_S(data);
      break;

    case GET_SPECTRUMSAMPLE_T:
      USART_Transmit_S("#1");
      getexposure();
      USART_Transmit_S("#2");
      break;
    default:
      break;
  }
}

void processbinmodecommand(char* data)
{
  switch (data[3])
  {
    case INIT_B:
      USART_Transmit_S(NACK);
      USART_Transmit_S(VER);
      USART_Transmit_S("\r\n");
      break;

    case SET_TIMESTAMP_B:
      USART_Transmit_S("B");
      USART_Transmit_S(data);
      break;

    case GET_SPECTRUMSAMPLE_B:
      USART_Transmit_S("#1");
      getexposure();
      USART_Transmit_S("#2");
      break;
    default:
      break;
  }
}

void processcommand(char* _data)
{
  if (!Mode)
  {
    processtextmodecommand(_data);
  }
  if (Mode)
  {
    processbinmodecommand(_data);
  }
}

int main(void)
{

  //define port B for output
  DDRB = 0x1f;

  //define port C for input - Analog Reads
  DDRC = 0x00;

  USART_Init(UBRR_VALUE);
  InitADC();
  USART_Transmit_S("ADC Inited\r\n");

  starttime = millis();


  // put your main code here, to run repeatedly: the loop void in Arduino Code
  while (1)
  {
    updateTemp();
    //get command data until end of command reached
    unsigned int buffer_counter = 0;

    while (data != COMMAND_END)
    {
      data = USART_Receive();
      command[buffer_counter] = data;
      buffer_counter++;
    }

    processcommand(command);
    USART_Transmit_S(command);

    //    _delay_ms(1000);

    //Initialization the USART data buffer
    buffer_counter = 0;
    //clean the array of data
    while (buffer_counter <= buffersize)
    {
      command[buffer_counter] = 0;
      buffer_counter++;
    }
    //Initialization End of USART data Buffer
  }

  //evaluation start ellapsedtime case true for ellapsedtime update internal time
  ellapsedtime = millis() - starttime;

  ellapsedtime = ellapsedtime / 100;

  if (ellapsedtime >= 1)
  {
    timestamp = timestamp + ellapsedtime;
    starttime = millis();
  }
  //evaluation End ellapsedtime case true for ellapsedtime update internal time
}
