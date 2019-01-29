#include <Arduino.h>
#include "audio.h"
#include "job.h"
#include "lcd.h"
#include "led.h"
#include "notes.h"
#include "button.h"
#define AUDIO_PIN_1 9
#define AUDIO_PIN_2 10
#define AUDIO_PAUSE 0
int raw_audio_value;
unsigned long int start_time = 0;
float run_time = 0;
music_t * current_track;

note_t mario_overworld[] = {
  {NOTE_E5, 250},
  {AUDIO_PAUSE, 10},
  {NOTE_E5, 250},
  {AUDIO_PAUSE, 120},
  {NOTE_E5, 120},
  {AUDIO_PAUSE, 120},
  {NOTE_C5, 120},
  {NOTE_E5, 250},
  {NOTE_G5, 250},
  {AUDIO_PAUSE, 320},
  {NOTE_G4, 250},
  {AUDIO_PAUSE, 320}
};
note_t pokemon_wild_A[] = {
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  {NOTE_G5, 83},
  {NOTE_FS5, 83},
  {NOTE_F5, 83},
  {NOTE_F6, 83},
  // End of intro
  };

note_t pokemon_wild_B[] = {
  {NOTE_CS4, 166},
  {NOTE_CS4, 83},
  {NOTE_C4, 83},
  {NOTE_D4, 166},
  {NOTE_D4, 83},
  {NOTE_C4, 83},
  {NOTE_DS4, 166},
  {NOTE_DS4, 83},
  {NOTE_C4, 83},
  {NOTE_E4, 166},
  {NOTE_E4, 83},
  {NOTE_C4, 83},
  {NOTE_F4, 166},
  {NOTE_F4, 83},
  {NOTE_C4, 83},
  {NOTE_FS4, 166},
  {NOTE_FS4, 83},
  {NOTE_C4, 83},
  {NOTE_E4, 166},
  {NOTE_E4, 83},
  {NOTE_C4, 83},
  {NOTE_AS3, 166},
  {NOTE_A3, 166},

};

music_t library[LIBRARY_LENGTH] = {
{"Mario Overworld Theme", mario_overworld, 0, 11},
{"Pokemon Wild Battle", pokemon_wild_A, pokemon_wild_B, 31, 22},
};

#define PAUSE_STATE 0
#define PLAY_STATE 1
#define REWIND_STATE 2
#define FASTFORWARD_STATE 3
#define SLOW_STATE 4
music_t * p_library = library;
int current_state = 0;
void job_audio(job_t * self, unsigned long time)
{
  if (PLAY_STATE == current_state) 
  {
    if (start_time == 0) 
    {
      start_time = time;
    }
    unsigned long play_head = time - start_time;
    int frequency = 0;
    unsigned long track_head = 0;
    
    for (int index = 0; current_track->length_A > index; index++) 
    { 
      track_head += current_track->track_A[index].duration;
      if (track_head > play_head) {
        frequency += current_track->track_A[index].key;
        break;
      }
    }
    track_head = 0;
    int has_track_B = 0;
    //current_track.track
    for (int index = 0; current_track->length_B > index; index++) 
    { 
      track_head += current_track->track_B[index].duration;
      if (track_head > play_head) {
        if (AUDIO_PAUSE != current_track->track_B[index].key)
        {
          has_track_B = 1;
          frequency += current_track->track_B[index].key;
        }
        break;
      }
    }
    if (has_track_B)
    {
      frequency /= 2; 
    }
    if (AUDIO_PAUSE != frequency)
    {
      tone(AUDIO_PIN_1,frequency,10);
    }
  } 
  
}
int track_A_length;
int track_B_length;

// set play state and play head
void audio_play() 
{
  current_state = PLAY_STATE;
}

int set_track(int track_index) 
{
  if (track_index >= LIBRARY_LENGTH) 
  {
    return 0;
  }
  current_track = &(library[track_index]);

  start_time = 0;
  noTone(AUDIO_PIN_1);
  calculate_track();
  set_lcd(1, String(run_time));
  audio_play();
  noTone(AUDIO_PIN_1);
  
}

void calculate_track() 
{
  float temp_runtime = 0;
  for (int index = 0; index <= current_track->length_A; index++)
  {

    temp_runtime += current_track->track_A[index].duration;
    
  }
 
  run_time = (temp_runtime / 1000);
  
  Serial.println(run_time);
}

void audio_pause() 
{
  current_state = PAUSE_STATE;
}