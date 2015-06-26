/*

*/

//Read interval in milliseconds
#define readInterval 500

//Temperature Sensors 1 and 2
const int analogin = A0;
const int analogin1 = A1;

//Temperature sensors ADU_K's for INTERNAL 1V1 Reference
// ADU_K = 1.1V / 1023 = 0.00107 Volt or 1,07 mV
const float ADU_K = 0.00107;

//Global variables for temperature reading
unsigned int input = 0;
unsigned int input1 = 0;

//Temperature sensors ADC_K's used to calibrate
//the output temperature according to the specific sensor used
float ADC_K = 1.06231;
float ADC_K1 = 1.06974;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //with the next instruction we set the internal Reference of the Atmega
  analogReference(INTERNAL);
}

void loop() {
  // put your main code here, to run repeatedly:

  //this two measures are discarded since usually they give bad readings
  input = readADC(analogin);
  input1 = readADC(analogin1);


  float temp = ((input * ADU_K) / ADC_K - 0.6) * 100;
  float temp1 = ((input1 * ADU_K) / ADC_K1 - 0.6) * 100;

  //Comment the next three lines to use the processing sketch
  //to visualize in real time the temperature reading output
  //  Serial.print("ADU -1 :");
  //  Serial.print(input);
  //  Serial.print(" Temp: ");
  Serial.print(temp, 1);

  Serial.print(" ");
  //Comment the next three lines to use the processing sketch
  //to visualize in real time the temperature reading output
  //  Serial.print("ADU -2 :");
  //  Serial.print(input1);
  //  Serial.print(" Temp1: ");
  Serial.println(temp1, 1);
  delay(readInterval);

  /*
    for (int i = 0; i < 255; i++)
    {
      Serial.println(i);
      analogWrite(analogout, i);
      delay(100);
    }
  */


}

//this function is responsible for making the mean
//of the readouts and reduce the noise obtained from the ADC
int  readADC(int sensor)
{

  unsigned int readout = analogRead(sensor);

  unsigned int data;

  for (int i = 0; i < 33; i++)
  {
    data = data  + analogRead(sensor);
  }

  data = data / 33 ;

}
