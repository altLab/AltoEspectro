// The frequency of the PWM signal on most pins is approximately 
// 490 Hz. On the Uno and similar boards, pins 5 and 6 have 
// a frequency of approximately 980 Hz. Pins 3 and 11 on the Leonardo also run at 980 Hz.

const int fanOutput = 6;
const int PWM = 127; // 127 para o PWM = 50 % do Ciclo

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

analogWrite(fanOutput,PWM);
}
