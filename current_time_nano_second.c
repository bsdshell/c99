#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/time.h>

// FROM: chatGPT
// DATE: Fri  3 May 11:42:19 2024 
// KEY: get current time, get time, nano second, time now
//
// gcc current_time_nano_second.c -o current_time_nano_second
//
//
/*
 *
  struct timeval {
      time_t      tv_sec;     // seconds
      suseconds_t tv_usec;    // microseconds
  }
 *
 *
 */
uint64_t get_current_time_ns() {
    struct timeval tv;
    unsigned long nano = 1E9;
    gettimeofday(&tv, NULL);
    return ((uint64_t)tv.tv_sec * nano) + ((uint64_t)tv.tv_usec * 1000);
}

uint64_t time_second(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)tv.tv_sec;
}

uint64_t time_micro() {
    struct timeval tv;
    unsigned long micro = 1E6;
    gettimeofday(&tv, NULL);
    return ((uint64_t)tv.tv_sec * micro) + ((uint64_t)tv.tv_usec);
}

uint64_t time_nano() {
    struct timeval tv;
    unsigned long nano = 1E9;
    gettimeofday(&tv, NULL);
    return ((uint64_t)tv.tv_sec * nano) + ((uint64_t)tv.tv_usec * 1000);
}


int main() {
    uint64_t current_time_ns = get_current_time_ns();
    printf("Current time in nanoseconds: %llu\n", current_time_ns);
    printf("Current time in seconds: %llu\n", time_second());
    printf("Current time in microseconds: %llu\n", time_micro());
    printf("Current time in nanoseconds: %llu\n", time_nano());
    return 0;
}

