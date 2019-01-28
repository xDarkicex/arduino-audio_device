
#ifndef JOB_H
#define JOB_H 1
struct job_t {
  void (*callback)(job_t * job, unsigned long time);
  unsigned long last_time;
};
void jobs_loop();

#endif
