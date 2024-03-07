#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 200
#define BUF_SIZE 100


// KEY: fork, pipe, process, getpid
// gcc myfile.c -o main
int main () {
   printf("Hello World C!");
   pid_t pid;
   int i = 0;
   char buf[BUF_SIZE];
   fork();
   pid = getpid();
   for(int i = 0; i < MAX_COUNT; i++){
       sprintf(buf, "This line is from pid=%d i=%d\n", pid, i);
       write(1, buf, strlen(buf));
   }

   return(0);
}
