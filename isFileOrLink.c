
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


bool isRegFile (char * fp){
    struct stat buf;
    int x;
    bool isReg = false;
    FILE * of = fopen(fp, "r");
    if ( of != NULL){
        x = lstat (fp, &buf);
        if (S_ISREG(buf.st_mode)) {
            isReg = true;
        }
    }
    return isReg;
}

bool isValidSymbolicLink(char *fp){
    struct stat buf;
    int x;
    bool isValid = false;
    FILE * of = fopen(fp, "r");
    if ( of != NULL){
        x = lstat (fp, &buf);
        if (S_ISLNK(buf.st_mode)) {
            isValid = true;
        }
    }
    return isValid;
}

bool fileExist(char *fp){
    FILE * pp = fopen(fp, "r");
    return pp != NULL;
}


int main (int argc, char* argv[]) {
  if(argc == 2){
    char* fp = argv[1];
    if ( strcmp(fp, "-h") == 0){
        printf("ERR => File does not exist, can not open file\n");
        printf("REG => Regular file\n");
        printf("SYM => Valid Symbolic link file\n");
    }else{
        if(fileExist(fp)){
            if(isRegFile(fp)){
                printf("REG");
            }else{
                if(isValidSymbolicLink(fp)){
                    printf("SYM");
                }else{
                    printf("NOTSYM");
                }
            }

        }else{
            printf("ERR");
        }
    }
  }else{
      printf("Need one argument\n");
  }
    return 0;
}
