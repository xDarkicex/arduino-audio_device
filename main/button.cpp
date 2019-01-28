#include <Arduino.h>
#include "button.h"

// pin volatage is currently 3.3v
#define BUTTON_PIN A0
int button_value = 0;
int last_button = 0;
int button_pressed = 0;
// int last_raw_button = 0;
int raw_button = 0;
void update_button()
{
  raw_button = analogRead(BUTTON_PIN);
  if (50 >= raw_button) 
    button_value = BUTTON_1;
  else if (200 >= raw_button) 
    button_value = BUTTON_2;
  else if (400 >= raw_button)
    button_value = BUTTON_3;
  else if (600 >= raw_button)
    button_value = BUTTON_4;
  else if (800 >= raw_button)
    button_value = BUTTON_5;
  else 
    button_value = BUTTON_OFF;
  
  if(BUTTON_OFF == button_value)
    button_pressed = last_button;
  last_button = button_value;

}
