#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <AronCLibNew.h>


// gcc myfile.c -o main
int main(int argc, char**argv) {
    int i;
    /**
    for (i=1; i<argc; i++) {
        printf("export ENV%d=%s\n", i, argv[i]);
    }
    */
    for(int j = 0; j < 3; j++){
        printf("export kk%d=%d\n", j, j);
    }

    int strLen = 500;
    int len = 10;
    char* fname = "/tmp/x.x";
    char** pt = readFileToBuffer(fname, &len);

    printf("len=%d\n",len);
    for(int k = 0; k < len; k++){
        printf("export ee%d=\"%s\"\n", k, pt[k]);
    }
    free2d(pt, len);

}
