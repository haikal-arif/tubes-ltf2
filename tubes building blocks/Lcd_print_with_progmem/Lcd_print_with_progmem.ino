#include <LiquidCrystal_I2C.h>
const char goalMessage[] PROGMEM = {"GOAL!!!!!!!!!!!!"};

#define LCD_ADDR 0x27
#define LCD_COL 2
#define LCD_ROW 16

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


void setup() {
  // set up the LCD's number of columns and rows:
  lcd.init();
  lcd.backlight();
  // Print a message to the LCD.
  lcd.print("hello, world!");
  delay(1000);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  runningTxt(goalMessage, 0,500);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
 
