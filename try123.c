#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AronCLibNew.h" 

// gcc myfile.c -o main

/**

   float pt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   int nCol = 4; 
   printArrayFixed(pt, 10, nCol);

   0.00 1.00 2.00 3.00
   4.00 5.00 6.00 7.00
   8.00 9.00
*/
void printArrayFixed(float* pt, int len, int nCol){
    for(int i = 0; i < len; i++){
        if((i + 1) % nCol != 0){
            printf("%.2f ", pt[i]);
        }else{
            printf("%.2f\n", pt[i]);
        }
    }
}

int main () {
   // printf("Hello World C!");

   float pt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

   int nCol = 4; 
   printArrayFixed(pt, 10, nCol);


   return(0);
}
