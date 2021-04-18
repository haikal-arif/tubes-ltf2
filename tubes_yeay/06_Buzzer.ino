#define buzzerPin 3

int freqGoal[] = {727, 1019, 1432, 727, 1019, 1432, 1432, 1432};
int freqMiss[] = {656, 400, 400, 512, 278, 278, 278};

void buzzerSetup(){
  pinMode(buzzerPin, OUTPUT);
}

void buzzerGoal(){
  for (int i=0; i<9; i++){
    tone(buzzerPin, freqGoal[i]);
    delay(100);
  }
  noTone(buzzerPin);

  Serial.println("Buzzer untuk gol");
}

void buzzerMiss(){
  for (int i=0; i<4; i++){
    tone(buzzerPin, freqMiss[i]);
    delay(300);
  }
  noTone(buzzerPin);

  Serial.println("Buzzer tidak gol");
}
