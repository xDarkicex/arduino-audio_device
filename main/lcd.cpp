#include <Arduino.h>
#include <LiquidCrystal.h>
#include "job.h"
#include "button.h"
#include "lcd.h"
#include "audio.h"
#define LCD_EN 2
#define LCD_RS 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7
String lcd_buf[2]={"",""};
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4,LCD_D5, LCD_D6, LCD_D7);

// set size of the lcd screen
void init_lcd()
{
  lcd.begin(16,2);
  set_lcd(0, "| AUDIO PLAYER |");
  set_lcd(1, "| version: 1.0 |");
}

void job_lcd(job_t * self, unsigned long time) 
{
  self->last_time = time + 500;
  lcd.clear();
  for (int index= 0; 2 > index; index++) 
  {
    String current_text = lcd_buf[index];
    if (current_text.length() > 16)
    {
      int whereverweare = time/1000%(current_text.length()+3);
      String sub_text = current_text + F(" | ") + current_text;
      sub_text.remove(0,whereverweare);
      sub_text.remove(16);
      lcd.setCursor(0,index);
      lcd.print(sub_text);
    } 
    else 
    {
      lcd.setCursor(0,index);
      lcd.print(current_text);
    }

    
  }

}



void set_lcd(int row, String text) 
{
 lcd_buf[row] = text;
}