#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "gsl/gsl_poly.h"
// gcc myfile.c -o main


int main () {
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = 0;
  clock_settime(CLOCK_PROCESS_CPUTIME_ID, &ts);

  printf("%lld.%.9ld", (long long)ts.tv_sec, ts.tv_nsec);
  printf("ts.tv_sec=%lld.", (long long)ts.tv_sec);
  printf("ts.tv_nsec=%.9ld", (long long)ts.tv_nsec);

  clock_settime(CLOCK_PROCESS_CPUTIME_ID, &ts);
   return(0);
}
