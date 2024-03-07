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
// KEY: pipe
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

int pipeTwo(char* pipe_write, char* pipe_read){
    int fd[2];
    if(pipe(fd)){
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    char cmd0[100];
    char cmd1[100];
    sprintf(cmd1, "%s %d", pipe_write, fd[1]); 
    sprintf(cmd0, "%s %d", pipe_read,  fd[0]); 
    
    printf("cmd0=%s\n", cmd0);
    printf("cmd1=%s\n", cmd1);
    system(cmd1);
    system(cmd0);
}

int main () {
    pid_t pid;
    int fd[2];

    if(pipe(fd)){
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    char c1[] = "./write_to_pipe";
    char c0[] = "./read_from_pipe";
    pipeTwo(c1, c0);

   return(0);
}
