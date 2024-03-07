#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// KEY: read from pipe
// gcc myfile.c -o main
int main() {
    const int bufsize = 1024;
    char buf[bufsize];
    while(1){
        fgets(buf, sizeof buf, stdin);
        if (buf[strlen(buf)-1] == '\n') {
            // read full line
            printf("%s", buf);
        } else {
            printf("line was truncated => %s\n", buf);
            // line was truncated
        }
    }
    return 0;
}
