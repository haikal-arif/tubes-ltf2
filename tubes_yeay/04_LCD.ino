#define LCD_ADDR 0x27
#define LCD_ROW 2
#define LCD_COL 16

#include <LiquidCrystal_I2C.h>

// buat obyek lcd
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COL, LCD_ROW);

void lcdSetup(){
  lcd.init();
  lcd.backlight();
}

void lcdGoal(){
  char msg[] = "GOAL!!!!!!!!!!!!";
  char emoji[] = "(^_^)===b";
  char len = strlen(msg);
  lcd.clear();
  for (int i=0; i<len; i++){
    lcd.setCursor(LCD_COL-1-i, 1);
    lcd.print(msg);
    delay(200);
  }
  
  for (int i=0; i<3; i++){
    delay(500);
    lcd.clear();
    delay(500);
    for (int j=0; j<2; j++){
      lcd.setCursor(0,j);
      lcd.print(msg);
    }
  }
  
  for (int i=0; i<3; i++){
    delay(500);
    lcd.clear();
    delay(500);
    for (int j=0; j<2; j++){
      lcd.setCursor(4,j);
      lcd.print(emoji);
    }
  }
}

void lcdMiss(){
  char msg_p1[] = "You missed";
  char msg_p2[] = "the ball";
  char msg2[] = "TRY AGAIN!";
  char emoji[] = "(T_T)===p";
  
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print(msg_p1);
  lcd.setCursor(4,1);
  lcd.print(msg_p2);
  delay(4000);
  
  for (int i=0; i<3; i++){
    delay(500);
    lcd.clear();
    delay(500);
    for (int j=0; j<2; j++){
      lcd.setCursor(3,j);
      lcd.print(msg2);
    }
  }
  
  for (int i=0; i<3; i++){
    delay(500);
    lcd.clear();
    delay(500);
    for (int j=0; j<2; j++){
      lcd.setCursor(4,j);
      lcd.print(emoji);
    }
  }
}
