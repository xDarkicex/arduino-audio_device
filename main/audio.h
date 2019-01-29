#ifndef AUDIO_H
#define AUDIO_H 1
#define LIBRARY_LENGTH 2
#include "job.h"
struct note_t {
  int key;
  int duration;
};
struct music_t {
  String name;
  note_t *track_A;
  note_t *track_B;
  int length_A;
  int length_B;
};
struct tract_data_t {
  String name;
  unsigned int track_length;
  unsigned int play_head;
};

extern int raw_audio_value;
void job_audio(job_t * self, unsigned long time);
// test
extern music_t * p_library;
int set_track(int track_index);

void calculate_track();
#endif