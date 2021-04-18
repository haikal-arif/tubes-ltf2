const char goalMessage[] PROGMEM = {"GOAL!!!!!!!!!!!!"};
const char goalEmoji[] PROGMEM = {"(^_^)===b"}

void printString()

void goalCelebration()
{
  while(true)
  {
    if(millis()-lcd_control_millis>lcd_interval)
    {
      static byte i = 0;
      switch(i):
      {
        case i<
      }
      lcd.setCursor(LCD_COL-1-i, 1);
    lcd.print(msg);
    }
  }
}
