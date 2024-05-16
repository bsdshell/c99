#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <mach/mach_time.h>

uint64_t get_nanoseconds() {
    // Get the current time in ticks
    uint64_t ticks = mach_absolute_time();

    // Get the timebase information
    mach_timebase_info_data_t info;
    mach_timebase_info(&info);

    // Convert ticks to nanoseconds
    uint64_t nanoseconds = ticks * info.numer / info.denom;

    return nanoseconds;
}

int main() {
    const long nano = 1E9L;
    uint64_t current_time_ns = get_nanoseconds();
    printf("Current time in nanoseconds: %llu\n", current_time_ns);
    printf("Current time in seconds: %llu\n", current_time_ns/nano);
    return 0;
}

