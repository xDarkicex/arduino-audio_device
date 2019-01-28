#include <Arduino.h>
#include "job.h"
#include "button.h"
#include "audio.h"
#include "lcd.h"
#include "led.h"
#include "menu.h"

job_t jobs[] = {
  {&job_led},
  {&job_lcd},
  {&job_menu},
  {&job_audio} 
};

const unsigned int jobs_length = sizeof(jobs) / sizeof(job_t);
void jobs_loop() 
{
  unsigned long int current_time = millis();
  for (unsigned short int index = 0; index < jobs_length; index++) 
  {
    if (current_time > jobs[index].last_time) 
    {
      jobs[index].callback(&(jobs[index]), current_time);
    }
  }
}
