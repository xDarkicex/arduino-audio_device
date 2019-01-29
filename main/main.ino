#include "lcd.h"
#include "job.h"
#include "audio.h"
#include "led.h"

#define BAUD_RATE 9600

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  delay(100);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(BAUD_RATE);
  Serial.println(F("initializing"));
  init_lcd();
  init_RGB();
}

// the loop function runs over and over again forever
void loop() {
  jobs_loop();

 }
