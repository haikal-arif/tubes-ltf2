const char goalMessage[] PROGMEM = {"GOAL!!!!!!!!!!!!"};
const char missMessage[] PROGMEM = {"You Missed!"};

void printMsg(const char* msg)
{
  for(int i = 0; i<strlen_P(msg);i++)
  {
    Serial.print((char) pgm_read_byte_near(msg+i));
  }
  Serial.println();
}

void runningTxt(const char* msg, int interval)
{
  static unsigned long control_millis = 0;
  static int k=0;
  if (millis()-constrol_millis>interval)
  {
    printMsg(msg+k);
    k++;
    control_millis = millis();
  }
  if(k==strlen_P(msg))
  {
    k=0;
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  runningTxt(goalMessage, 200);
}
