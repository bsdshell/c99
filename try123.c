#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "gsl/gsl_poly.h"
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
   {
     float pt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
     int nCol = 4; 
     printArrayFixed(pt, 10, nCol);
   }
   {
     //  f(x) = (x - 1) * (x - 2) 
     //  f(x) = x ^2 - 3x + 2
     double a = 1;
     double b = -3;
     double c = 2;
     double x0;
     double x1;
	 
     int ret = gsl_poly_solve_quadratic(a, b, c, &x0, &x1);
     printf("x0=%f x1=%f\n", x0, x1);
     printf("ret=%d\n", ret);
	 
   }


   return(0);
}
