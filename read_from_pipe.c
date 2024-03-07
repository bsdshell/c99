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


int main (int argc, char* argv[]) {
  if(argc == 2){
    int fd[2];

	/*
    if(pipe(fd)){
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }
	*/

	int wd = atoi(argv[1]);
	read_from_pipe(wd);
  }
  return(0);
}
