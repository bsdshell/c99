#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "/Users/aaa/myfile/github/c99libtest/my_vector.h"

double indexMat (int i, int j, int nRow, int nCol, const double* pt) {
  int ir = i * nCol + j; 
  int ic = j * nRow + j;
  return pt[ix];
}

/*
    COMPILE: gcc -I../clib try.c -o try
    COMPILE: run.sh
*/
int main () {
    return(0);
}
