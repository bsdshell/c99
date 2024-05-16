#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "gsl/gsl_poly.h"

// Fri 26 Apr 12:20:40 2024 
// KEY: gnu scientific library, gsl
// gcc -lm -lgsl -lgslcblas myfile.c -o myfile
// https://gist.github.com/bsdshell/faf8f2c07198e037ecde6f965db00501

int main () {
   {
     //  f(x) = (x - 1) * (x - 2) 
     //  a x^2 -3x + 2 = 0
     //  f(x) = 0
     //  => x0 = 1, x1 = 2
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
