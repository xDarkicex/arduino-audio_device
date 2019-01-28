#include <Arduino.h>
#include "job.h"
#include "button.h"

#define LED_PIN 13
void job_led(job_t * self, unsigned long time) 
{
  if (BUTTON_OFF == button_value) 
  {
    digitalWrite(LED_PIN, LOW);
  } else 
  {
    digitalWrite(LED_PIN, HIGH);
  }
}