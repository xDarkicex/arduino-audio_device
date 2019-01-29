#include <Arduino.h>
#include <FastLED.h>
#include "job.h"
#include "button.h"


//rgb led pin
#define RGB_PIN_1 10
#define RGB_PIN_2 11
#define RGB_PIN_3 12
#define RGB_PIN_4 13
#define RGB_1 0
#define RGB_2 1
#define RGB_3 2
#define RGB_4 3
#define RGB_BRIGHTNESS 40
#define NUM_RGB 4
#define RGB_DELAY 1000
CRGB leds[NUM_RGB];
void init_RGB() {
  FastLED.addLeds<NEOPIXEL, RGB_PIN_1>(leds, NUM_RGB);
  FastLED.addLeds<NEOPIXEL, RGB_PIN_2>(leds, NUM_RGB);
  FastLED.addLeds<NEOPIXEL, RGB_PIN_3>(leds, NUM_RGB);
  FastLED.addLeds<NEOPIXEL, RGB_PIN_4>(leds, NUM_RGB);
  FastLED.setBrightness(RGB_BRIGHTNESS);
  
}
// set_RGB takes int red int blue int green not using currently
void set_RGB(int red, int blue, int green) 
{
  leds[RGB_1].setRGB(red, blue, green);
}
void job_led(job_t * self, unsigned long time) 
{
  int value_1 = (time/10)%255;
  int rand_R = (random(0,255) * time) %255;
  int rand_G = (random(0,255) * time) %255;
  int rand_B = (random(0,255) * time) %255;
  // why are all rgb_leds linked to rgb_1?
  leds[RGB_1] = CRGB(rand_R,rand_G,rand_B);
  // set_RGB(255,255,255);
  // Serial.println(String(rand_R) +" " + String(rand_B) + " "+ String(rand_G));
  FastLED.show();
  self->last_time = time + RGB_DELAY;

}
