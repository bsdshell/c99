//  $b/c99/pipe_sleep.c
//  gcc myfile.c -o main
//  cpp_compile.sh pipe_sleep.c
//
//                          +-> FILE* stream
//                          |
// Pipe associates with a stream which can be read or written
//                          |
//                          +-> like a buffer
// int mypipe[2];
// pipe(mypipe)
//
//         mypipe[1]           mypipe[0]
//             |                    |
//             v                    v
// write -> stdout [    ] -> read stdin 
//             |                    |
//             v                    v
//         mypipe[1]           mypipe[0]
//             |                    |
//             v                    v
//     write to stream       read from stream
//                |                       |
//                v                       v
//           like a buffer          like a buffer
//  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "AronLib.h" 

// Read char from a pipe
// FILE is a struct
// SEE: $b/publicfile/c99_stdio.h
// fd : file descriptor
void read_from_pipe(int fd){
    FILE *stream;
    int c;
    stream = fdopen(fd, "r");
    long n = 1000000;
    while((c = fgetc(stream)) != EOF){
        printf("\tc=%c\n", c);
        printf("\tChild process reading one char / per second ...\n");
        usleep(1*n);
    }
    fclose(stream);
}

void write_to_pipe(int fd){
    FILE *stream;
    int c;
    stream = fdopen(fd, "w");

    fprintf(stream, "Hello World\n");
    fprintf(stream, "Good Byte\n");
    fclose(stream);
}

int pipeTwo(char* pipe_out, char* pipe_in){
    int fd[2];
    if(pipe(fd)){
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }
}

int main () {
    pid_t pid;
    int fd[2];

    if(pipe(fd)){
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    printf("\tfd[0] = %d\n", fd[0]);  // => Why it is 3
    printf("\tfd[1] = %d\n", fd[1]);  // => Why it is 4

    pid = fork();

    pp("\tAfter fork() ... \n");

    if(pid == (pid_t) 0){
        printf("\tChild process pid=%d\n", pid);
    }else if(pid > (pid_t) 0){
        printf("\tParent process pid=%d\n", pid);
    }else {
        fprintf(stderr, "fork() failed\n");
    }


    if(pid == (pid_t) 0){
        // Child process
        // close the write end 
        close(fd[1]);
        printf("\tChild process pid=%d => Reading from pipe\n", pid);
        read_from_pipe(fd[0]);
        return EXIT_SUCCESS;
    }else if(pid < (pid_t)0){
        // fork() failed
        fprintf(stderr, "fork() failed\n");
    }else{
        // This is parent process
        close(fd[0]);

        long n = 1000000;
        printf("\tParent process pid=%d => Sleeping now 2 seconds ...\n", pid);
        printf("\tAfter 2 sec, write string to pipe\n");
        usleep(2*n);

        write_to_pipe(fd[1]);

        return EXIT_SUCCESS;
    }

   return(0);
}
