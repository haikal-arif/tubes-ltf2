#include <LiquidCrystal_I2C.h>

#define LCD_ADDR 0x27
#define LCD_ROW 2
#define LCD_COL 16

const char goalMessage[] PROGMEM = {"GOAL!!!!!!!!!!!!"};
const char missMessage[] PROGMEM = {"You Missed!"};

// initialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);

void lcdPrint(const char* msg, int col, int row)
{
  for(int i = 0; i<strlen_P(msg); i++)
  {
    lcd.setCursor(col+i, row);
    lcd.print((char) pgm_read_byte_near(msg+i));
  }
}

byte runningTxt(const char* msg, int row, int itv)
{
  static unsigned long text_millis=0;
  static int k=0;
  
  if (millis()-text_millis>itv)
  {
    lcdPrint(msg, 15-k, row);
    k++;
    text_millis=millis();
  }
  
  if (k>=15)
  {
    k=0;
    lcd.clear();
    return true;
  }
  return false;
}
