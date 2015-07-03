#define ver "0_3_3"

#define buffersize 12

#define cooling 3
#define coolingin A0
#define heatsink A1

unsigned long ellapsedtime = 0;
unsigned long starttime = 0;

unsigned long internaltime = 1234567;

bool coolingstate = false;

float settemperature = 0;

float coolingtemperature = 0;
float heatsinktemperature = 0;

float exposure = 0;


void setup()
{
  Serial.begin(9600);
  Serial.println("AltoEspectro - Start");
  starttime = millis();
}

void loop()
{

  char msg[buffersize] ;

  Serial.readBytesUntil(62, msg, buffersize);

  AS//  Serial.print(msg);Serial.print('\t');
  //  Serial.println(msg[3]);

  //AS+A <INIT>
  if (msg[3] == 65)
  {
    Serial.print("OK "); Serial.println(ver);
  }
  //DEBUG
  //AS+B <Set Time>
  //SET INTERNAL TIME
  if (msg[3] == 66)
  {
    Serial.print("OK ");
    Serial.println(msg[5] + msg[6] + msg[7] + msg[8] + msg[9] + msg[10] + msg[11]);
    internaltime = (long)(msg[5] + msg[6] + msg[7] + msg[8] + msg[9] + msg[10] + msg[11]);
    Serial.println(internaltime);
  }
  //DEBUG
  //AS*C <Exposure Time>
  //GET SAMPLE DATA
  if (msg[3] == 67)
  {
    Serial.print("OK ");
    Serial.print(internaltime);
    Serial.print(' ');
    gettemperature();
    Serial.print(' ');
    Serial.print(exposure);
    Serial.print(' ');
    getexposure();
    Serial.println();
  }
  //AS*D
  //GET TEMPERATURE
  if (msg[3] == 68)
  {
    Serial.print("OK ");
    Serial.print(internaltime);
    Serial.print(' ');
    gettemperature();
    Serial.println();
  }

  //DEBUG
  //AS*E <ooling temperature>
  //SET TEMPERATURE
  if (msg[3] == 69)
  {
    Serial.print("OK ");
    coolingtemperature = (float)(msg[5] + msg[6] + msg[7] + msg[8] + msg[9] + msg[10] + msg[11]);
    Serial.print(coolingtemperature);
    Serial.println();
  }
  //AS*F <status>
  //SET COOLING ON/OFF
  if (msg[3] == 70)
  {
    Serial.print("OK");
    Serial.print(" ");
    Serial.print("STATUS: ");
    if (msg[5] == 79 && msg[6] == 78)
    {
      setcooling(true);
      coolingstate = true;
      Serial.println("ON");
    }
    if (msg[5] == 79 && msg[6] == 70 && msg[7] == 70)
    {
      setcooling(false);
      coolingstate = false;
      Serial.println("OFF");
    }
  }

  //AS*G
  //GET COOLING STATUS
  if (msg[3] == 71)
  {
    Serial.print("OK ");
    getcooling();
    Serial.println();
  }
  // Clear the Buffer
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
    //    Serial.println(internaltime);
  }

}

void getexposure()
{
  Serial.print("data0 data1 .... dataN");
}

void gettemperature()
{
  Serial.print(coolingtemperature);
  Serial.print(' ');
  Serial.print(heatsinktemperature);
}

void setcooling(bool state)
{
  digitalWrite(cooling, state);
  coolingstate = state;
}

void getcooling()
{
  Serial.print("COOLING: ");
  if (coolingstate)
  {
    Serial.print("ON");
  }
  if (!coolingstate)
  {
    Serial.print("OFF");
  }
}
