#define ver "0_3_3"
#define buffersize 8


unsigned long ellapsedtime = 0;
unsigned long starttime = 0;
unsigned long internaltime = 201257639;



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
    case 'A':
      Serial.print('A'); Serial.print(' '); Serial.println(ver);
      break;
    case 'B':
      Serial.print('B');

      Serial.print(' ');
      Serial.print(msg[3]); Serial.print(msg[4]); Serial.print(msg[5]); Serial.println(msg[6]);
      break;
    case 'C':
      Serial.println('C');
      Serial.print(msg[3]); Serial.print(msg[4]); Serial.print(msg[5]); Serial.println(msg[6]);
      getexposure();
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
  Serial.println(internaltime);
  Serial.println("<dara></data>");
}
