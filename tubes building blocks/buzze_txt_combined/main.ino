void celebration()
{
  int progress=0;
  while(true)
  {
    static bool buzzer_target=1;
    static bool lcd_part_1=1;
    if (buzzerTone(freqGoal, 8, 100))
    {
      if (buzzer_target)
      {
        progress++;
        buzzer_target=0;
      }
    }
    if (runningTxt(goalMessage, 0, 500))
    {
      if (lcd_part_1)
      {
        progress++;
        lcd_part_1=0;
      }
    }
    if (progress==2)
    {
      buzzer_target=1;
      lcd_part_1=1;
      break;
    }
  }
}


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  buzzerInit();
  celebration();
}

void loop() {
  // put your main code here, to run repeatedly:

}
