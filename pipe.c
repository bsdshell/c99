#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

// Read char from a pipe
void read_from_pipe(int file){
    FILE *stream;
    int c;
    stream = fdopen(file, "r");
    while((c = fgetc(stream)) != EOF){
        putchar(c);
    }
    fclose(stream);
}

void write_to_pipe(int file){
    FILE *stream;
    int c;
    stream = fdopen(file, "w");
    fprintf(stream, "Hello World\n");
    fprintf(stream, "Good Byte\n");
    fclose(stream);
}

// gcc myfile.c -o main
//
// pipe(mypipe)
//
//         mypipe[1]           mypipe[0]
//             |                    |
//             v                    v
//            "w"                  "r"
// write -> stdout [    ] -> read stdin 
//             |                    |
//             v                    v
//         mypipe[1]           mypipe[0]
int main () {
    pid_t pid;
    int mypipe[2];
    if(pipe(mypipe)){
        fprintf(stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }

    printf("mypipe[0] = %d\n", mypipe[0]);  // => 3
    printf("mypipe[1] = %d\n", mypipe[1]);  // => 4

    pid = fork();
    if(pid == (pid_t) 0){
        // Child process
        // close the write end 
        close(mypipe[1]);
        read_from_pipe(mypipe[0]);
        return EXIT_SUCCESS;
    }else if(pid < (pid_t)0){
        // fork() failed
        fprintf(stderr, "fork() failed\n");
    }else{
        // This is parent process
        close(mypipe[0]);
        write_to_pipe(mypipe[1]);
        return EXIT_SUCCESS;
    }

   return(0);
}
