#define ldrPin A6

void setup(){
  Serial.begin(BAUD);

  Serial.println(TITLE);
  
  buzzerSetup();
  ledSetup();
  lcdSetup();
}

void loop(){
  int ldrStatus = analogRead(ldrPin);

  if (ldrStatus <= 400){
    lcdGoal();
    ledGoal();
    buzzerGoal();
    lcdText();
    
    digitalWrite(LED1,HIGH);
    delay(300);
    digitalWrite(LED2,HIGH);
    digitalWrite(LED1,LOW);
    delay(300);
    digitalWrite(LED2,LOW);
    digitalWrite(LED3,HIGH);
    delay(300);
    digitalWrite(LED3,LOW);
    
    Serial.println("Gol");
    
  else{
    lcdMiss();
    buzzerMiss();
    Serial.println("Tidak gol");
  }
  }
}
