#include <stdio.h>
#include <time.h>

int main() {
    struct timespec res;
    if (clock_getres(CLOCK_REALTIME, &res) == 0) {
        printf("Resolution of CLOCK_REALTIME: %ld seconds, %ld nanoseconds\n",
               res.tv_sec, res.tv_nsec);
    } else {
        perror("clock_getres");
        return 1;
    }
    return 0;
}
