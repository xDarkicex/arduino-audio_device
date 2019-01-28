#include "job.h"

void init_lcd();

void job_lcd(job_t * self, unsigned long time);
void set_lcd(int row, String text);