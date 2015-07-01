#define ver "0_3_3"

#define buffersize 8


unsigned long ellapsedtime = 0;
unsigned long starttime = 0;
unsigned long internaltime = 12345678;
bool coolingState = false;


char msg[buffersize] ;

void setup()
{
  Serial.begin(9600);
  starttime = millis();
}

void loop()
{

  Serial.readBytesUntil(62, msg, buffersize);

  switch (msg[1])
  {
    // INIT
    case 'A':
      Serial.print('A'); Serial.print(' '); Serial.println(ver);
      break;
    //SET TIMESTAMP
    case 'B':
      Serial.print('B');
      Serial.print(' ');
      Serial.print(msg[3]); Serial.print(msg[4]); Serial.print(msg[5]); Serial.println(msg[6]);
      break;
    //GET SPECTRUM SAMPLE
    case 'C':
      Serial.println('C');
      Serial.print(msg[3]); Serial.print(msg[4]); Serial.print(msg[5]); Serial.println(msg[6]);
      getexposure();
      break;
    //GET TEMPERATURE SAMPLE
    case 'D':
      gettemperature();
      break;
    //SET TEMPERATURE
    case 'E':
      settemperature(value);
      break;
    //SET COOLING ON/OFF
    case 'F':
      //get data from buffer
      setcooling(_state);
      break;
    default:
      break;
  }

  for (int i = 0 ; i < buffersize; i++)
  {
    msg[i] = 0;
  }

  ellapsedtime = millis() - starttime;

  ellapsedtime = ellapsedtime / 100;

  if (ellapsedtime >= 1)
  {
    internaltime = internaltime + ellapsedtime;
    starttime = millis();

  }

}

void getexposure()
{
  Serial.print("Exposure Time");
  Serial.print(internaltime);
  Serial.println("<dara></data>");
}

void gettemperature()
{
  Serial.print("");
  Serial.print();
  Serial.println("");
}

void setcooling(bool state)
{
  pinMode(Cooling, State);
}
