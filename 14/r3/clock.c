#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
struct timeval ut1, ut2;
struct timeval st1, st2;
struct rusage val;

void startClock() {
  getrusage(RUSAGE_SELF, &val);
  ut1 = val.ru_utime;
  st1 = val.ru_stime;
}
void stopClock() {
  getrusage(RUSAGE_SELF, &val);
  ut2 = val.ru_utime;
  st2 = val.ru_stime;
}
void printClock() {
  // printf("user time = %lf [s]\n", (ut2.tv_sec-ut1.tv_sec)+(ut2.tv_usec-ut1.tv_usec)*1.0E-6);
  // printf("sys  time = %lf [s]\n", (st2.tv_sec-st1.tv_sec)+(st2.tv_usec-st1.tv_usec)*1.0E-6);
  printf("%lf\n", (ut2.tv_sec-ut1.tv_sec)+(ut2.tv_usec-ut1.tv_usec)*1.0E-6);
}