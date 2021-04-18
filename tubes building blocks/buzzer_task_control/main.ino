void setup()
{
  buzzerInit();
  tone(BUZZER_PIN, 1000);
}

void loop()
{
  buzzerTone(freqGoal, 8, 200);
}
