#include <stdio.h>
#include <unistd.h>  // usleep()
#include <time.h>

// KEY: get time, get nano second, get nanosecond
int main() {
    long nano = 1E9;
    struct timespec start_time, end_time;

    // Get the start time
    clock_gettime(CLOCK_REALTIME, &start_time);

    usleep(1000);

    // Get the end time
    clock_gettime(CLOCK_REALTIME, &end_time);

    printf("start_time.tv_sec  %09ld\n", start_time.tv_sec);
    printf("start_time.tv_nsec %09ld\n", start_time.tv_nsec);
    printf("end_time.tv_sec  %09ld\n", end_time.tv_sec);
    printf("end_time.tv_nsec %09ld\n", end_time.tv_nsec);

    // Calculate the elapsed time
    long seconds = end_time.tv_sec - start_time.tv_sec;
    long nanoseconds = end_time.tv_nsec - start_time.tv_nsec;

    // Print the elapsed time
    printf("Elapsed time: %ld %09ld seconds\n", seconds, nanoseconds);
    printf("Elapsed time: %ld %09f seconds\n", seconds, (double)nanoseconds/nano);
    return 0;
}

