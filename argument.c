#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "AronLib.h" 

// KEY: input argument, shell input
int main (int argc, char* argv[]) {
  if(argc == 1){
	printf("argv[0] => %s\n", argv[0]);
  }

  if(argc == 2){
	printf("argv[0] => %s\n", argv[0]);
	printf("argv[1] => %s\n", argv[1]);
  }

  if(argc == 3){
	printf("argv[0] => %s\n", argv[0]);
	printf("argv[1] => %s\n", argv[1]);
	printf("argv[2] => %s\n", argv[2]);
  }

  return(0);
}
