#include <Arduino.h>
#include "button.h"
#include "lcd.h"
#include "audio.h"
unsigned int playlist_counter = 0;
// unsigned int action_button;
void job_menu(job_t * self, unsigned long time) 
{
  self->last_time = time + 30;
  update_button();
  if (BUTTON_OFF != last_button) 
  {
    switch (last_button)
    {
      case BUTTON_1: set_lcd(0, "Button one");
      break;
      case BUTTON_2: set_lcd(1, "Button two");
      self->last_time = time +800;
       if (playlist_counter < (LIBRARY_LENGTH - 1))
      {
        playlist_counter++;
      } 
      else
      {
       playlist_counter = 0;
      }
      Serial.println(String(playlist_counter));
      set_lcd(0, String(p_library[playlist_counter].name));
      break;
      case BUTTON_3: set_lcd(1, "Button three");
      self->last_time = time +800;
       if (playlist_counter >= (LIBRARY_LENGTH - 1))
      {
        playlist_counter--;
      } 
      else
      {
       playlist_counter = (LIBRARY_LENGTH - 1);
      }
      set_lcd(0, String(p_library[playlist_counter].name));
      Serial.println(String(playlist_counter));
      break;
      case BUTTON_4: set_lcd(0, "Button four");
      break;
      case BUTTON_5: 
      self->last_time = time +800;
      if (set_track(playlist_counter))
      {
        Serial.println("error"+String(playlist_counter));
      }
      break;
    }
    // // set_lcd(0, p_library[playlist_counter].name);
    // if (last_button == BUTTON_2)
    // {
    //   self->last_time = time + 250;
    //   if (playlist_counter >= playlist_max)
    //   {
    //     playlist_counter = (playlist_counter % playlist_max);
    //   }
    //   set_lcd(0, String(p_library[playlist_counter].name));
    //   set_lcd(1, "");
    //   playlist_counter++;
    // }
    // if (last_button == BUTTON_3)
    // {
    //   self->last_time = time + 250;
    //   if (playlist_counter == 0)
    //   {
    //     playlist_counter = LIBRARY_LENGTH - 1;
    //   }
    //   set_lcd(0, String(p_library[playlist_counter].name));
    //   set_lcd(1, "");
    //   playlist_counter--;
    // }
    // if (last_button == BUTTON_5)
    // {
    //  self->last_time = time + 250;
    //  Serial.println(String(playlist_counter));
    // }
  }
}