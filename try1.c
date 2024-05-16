#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "/Users/aaa/myfile/github/c99libtest/my_vector.h"
#include "/Users/aaa/myfile/github/c99lib/AronCLibDev.h"

/*
    COMPILE: gcc -I../clib try1.c -o try1
    COMPILE: run.sh
*/

int max_c(int a, int b){
  return a > b ? a : b;
}

int min_c(int a, int b){
  return a > b ? b : a;
}
void add_array(int* arr0, int n0, int* arr1, int n1, int* retArr){
  int m = max_c(n0, n1);
  for(int i = 0; i < m; i++){
  }
}


int main () {
  printf("try1.c\n");
  
  const int len = 9;
  const int width = 3;
  int arr[len];
  fun(arr, len, width);

  long seed = 101;

  {
    int i = 0;
    while(i < 10){
      long r = randomNum(seed);
      long m = r % 10;
      float fn = m/10.0;
      if(m != 0){
        i++;
        printf("r=%d m=%d fn=%0.2f\n", r, m, fn);
      }
      seed = r;
    }
  }
  {
    int arr[10];
    fillArray(arr, 10, 0, 1);
    print_array_int(arr, 10, 5);
  }
  {
    int len = 9;
    double* pt = (double*)malloc(sizeof(double) * len);
    geneArrayDouble(pt, len);
    print_array_double(pt, len, 3);
	
	free(pt);
  }
  {
    int len = 9;
    float* pt = (float*)malloc(sizeof(float) * len);
    gene_array_float(pt, len);
    print_array_float(pt, len, 3);
	
	free(pt);
  }
  {
	/* a1 1   2  6  24
     *    {1} 2  3  4   => 24
	 *    1  {2} 3  4   => 12
     *    1   2 {3} 4   => 8
	 *    1   2  3 {4}  => 6
	 *    6   6  3  1
	 *
	 */
	const int len = 4;
	int arr[len] = {2, 3, 4, 5};
	int a1[len];
	int a2[len];
	a1[0] = 1;
	a2[len-1] = 1;
	int m = 1;
	
	for(int i = 1;  i < len; i++){
	  int rx = len - 1 - i + 1; // reverse index
	  a1[i] =  a1[i-1]*arr[i-1];     // ->[ ] -> []
	  a2[rx - 1] = a2[rx]*arr[rx];  // <-[ ] <- []
	}
	
	for(int i = 0; i < len; i++){
	  a2[i] = a1[i] * a2[i];
	}
	print_array_int(a1, len, 1);
	fw("a2");
	print_array_int(a2, len, 1);
	fw("final array");
	print_array_int(a2, len, 1);
	printf("m=%d\n", m);
  }
  {
  	int n = gcd_c(0, 1);
	t_int(n, 1, "t0");
	
	n = gcd_c(1, 0);
	t_int(n, 1, "t1");
	
	n = gcd_c(1, 1);
	t_int(n, 1, "t2");
	
	n = gcd_c(2, 2);
	t_int(n, 2, "t3");
	
	n = gcd_c(3, 9);
	t_int(n, 3, "t4");
	
	n = gcd_c(12, 18);
	t_int(n, 6, "t5");
  }
  {
	int n = lcm(0, 1);
	t_int(n, 0, "t0");
	n = lcm(1, 0);
	t_int(n, 0, "t1");
	n = lcm(1, 4);
	t_int(n, 4, "t2");
	n = lcm(2, 4);
	t_int(n, 4, "t3");
	n = lcm(3, 4);
	t_int(n, 12, "t4");
	
  }
  {
	const int len = 9;
	int arr[len];
	gene_array_int(arr, len, 1, 9);
	print_array_int(arr, len, 3);

	subRow(arr, 1, 2, 3);
	fw("subRow");
	print_array_int(arr, len, 3);

	fw("subRow 1");
	for(int i = 1; i < 3; i++){
	  subRow(arr, (i-1), i, 3);
	}
	print_array_int(arr, len, 3);
	fw("mulRow 1");
	int r0 = 2;
	mulRow(10, arr, r0, 3);
	print_array_int(arr, len, 3);
  }
  {
	const int len = 9;
	int arr[len];
	int r0 = 2;
	gene_array_int(arr, len, 1, 9);
	print_array_int(arr, len, 3);
	fw("mulRow 1");
	mulRow(10, arr, r0, 3);
	print_array_int(arr, len, 3);
  }

  {
	const int len = 9;
	const int width = 3;
	int arr[len] = {2, 4, 8,
					5, 7, 6,
					8, 3, 5};
	int r0 = 0;
	print_array_int(arr, len, width);
	rowDiv(2, arr, r0, width);
	fw("rowDiv");
	print_array_int(arr, len, width);
  }
  {
	{
	  const int len = 4;
	  int arr[len] = {2, 4, 8, 2};
	  int g = gcd_array(arr, len);
	  t_int(g, 2, "gcd_array 1");
	}
	{
	  const int len = 4;
	  int arr[len] = {3, 4, 12, 4};
	  int g = gcd_array(arr, len);
	  t_int(g, 1, "gcd_array 2");
	}
	{
	  const int len = 4;
	  int arr[len] = {16, 20, 12, 4};
	  int g = gcd_array(arr, len);
	  t_int(g, 4, "gcd_array 3");
	}
  }
  {
	const int len = 9;
	const int width = 3;
	int arr[len] = {2, 4, 8,
					5, 7, 6,
					8, 3, 5};
	int r0 = 0;
	print_array_int(arr, len, width);
    int rowArr[3];
	int rx = 0;
	get_row(arr, len, rowArr, rx, width);
	fw("rowArr");
	print_array_int(rowArr, width, 1);
  }

  {
	const int len = 9;
	const int width = 3;
	int arr[len] = {2, 4, 8,
					5, 7, 6,
					8, 3, 5};
	
	print_array_int(arr, len, width);
    int colArr[3];
	int cx = 2;
	get_col(arr, len, colArr, cx, width);
	fw("colArr");
	int nRow = len / width;
	print_array_int(colArr, nRow, 1);
  }
  {
	char* str = "abc";
	char retBuf[100];
	pad_left(str, 4, 'x', retBuf);
	printf("retBuf=%s\n", retBuf);
	t_str(retBuf, "xxxxabc", "pad_left 1");
  }
  {
	char* s1 = "abc";
	char* s2 = "kkk";
	char retBuf[50];
	concat_str(s1, s2, retBuf);
	t_str(retBuf, "abckkk", "concat_str 1");
  }
  {
	char* str = "abc";
	char retBuf[100];
	pad_right(str, 4, 'x', retBuf);
	t_str(retBuf, "abcxxxx", "pad_right 1");
  }
  {
	const int len = 4;
	int arr[len];
	gene_array_int(arr, len, 1, 9);
	// print_array_int(arr, len, 1);

	int s = foldl_int(add, 0, arr, len);
	printf("s=%d\n", s);
  }
  {
	const int len = 4;
	int arr[len];
	gene_array_int(arr, len, 1, 9);
	// print_array_int(arr, len, 1);

	int s = foldl_int(mul, 1, arr, len);
	printf("s=%d\n", s);
  }
  {
	const int len = 9;
	const int width = 3;
	int arr[len] = {2,   4,    8000000,
					500, 7,    6,
					8,   3000, 5};
	print_matrix_int(arr, len, width);
  }

  
  {
	const int len = 2;
	int arr[len] = {0, 1};
	remove_zero(arr, len);
	print_array_int(arr, len, 1);
  }
  {
	pair p = fun3(3, 1);
	print_pair(p);
  }

  {
	const int len = 25;
	const int width = 5;
	int nRow = len / width;
	int arr[len];
	gene_array_int(arr, len, 1, 20);
	matrix_reduce(arr, len, width);
  }
  {
	const int len = 16;
	const int width = 4;
	int nRow = len / width;
	int arr[len] = {2, 4, 1, 3,
					5, 7, 6, 2,
					8, 3, 5, 19,
					4, 5, 7, 8
	               };
	matrix_reduce(arr, len, width);
  }
  /*
  {
	const int len = 25;
	const int width = 5;
	int nRow = len / width;
	int arr[len] = {
					276, 353, 226, 231, 331,
					318, 224, 203, 321, 271,
					10,  341, 253, 89,  191,
					393, 365, 315, 350, 130,
					309, 109, 24,  365, 204
	               };
	matrix_reduce(arr, len, width);
  }
  */
  {
	const int len = 3;
	int arr[len] = {1, 2, 3};
	char** strArr = (char**)malloc(sizeof(char*)*len);
	const int strLen = 20;
	for(int i = 0; i < len; i++){
	  strArr[i] = (char*)malloc(sizeof(char)*strLen);
	}
	
	arrToStr_int(arr, len, strArr);
	for(int i = 0; i < len; i++){
	  printf("strArr=%s\n", strArr[i]);
	}
	free2d(strArr, len);
  }
  {
	int hight = 3;
	int width = 4;
	int** pt = malloc2d(hight, width, "int");
	for(int i = 0; i < hight; i++){
	  for(int j = 0; j < width; j++){
		pt[i][j] = 100;
	  }
	}
	for(int i = 0; i < hight; i++){
	  for(int j = 0; j < width; j++){
		printf("%d ", pt[i][j]);
	  }
	  newline_c();
	}
	free2d(pt, hight);
  }
  {
	int hight = 3;
	int width = 10;
	char** pt = malloc2d(hight, width, "char");
	for(int i = 0; i < hight; i++){
	  sprintf(pt[i], "%d", 3000);
	}
	for(int i = 0; i < hight; i++){
	  printf("%s ", pt[i]);
	}
	free2d(pt, hight);
  }
  {
	int a1[4] = {1, 9, 2, 20};
	int lo = 0;
	int hi = 3;
	int mid = (lo + hi)/2;
	merge_int(a1, lo, mid, hi);
	fw("a1 1");
	print_array_int(a1, 4, 4);
  }
  {
	int a1[1] = {4};
	int lo = 0;
	int hi = 0;
	int mid = (lo + hi)/2;
	merge_int(a1, lo, mid, hi);
	fw("a1 2");
	print_array_int(a1, 1, 1);
  }
  {
	int a1[2] = {4, 2};
	int lo = 0;
	int hi = 1;
	int mid = (lo + hi)/2;
	merge_int(a1, lo, mid, hi);
	fw("a1 2");
	print_array_int(a1, 2, 2);
  }
  {
	int a1[3] = {2, 4, 1};
	int lo = 0;
	int hi = 2;
	int mid = (lo + hi)/2;
	merge_int(a1, lo, mid, hi);
	fw("a1 2");
	print_array_int(a1, 3, 3);
  }
  {
	int a1[1] = {2};
	int lo = 0;
	int hi = 0;
	fw("mergeSort 0");
	mergeSort(a1, lo, hi);
	print_array_int(a1, 1, 1);
  }
  {
	int a1[2] = {2, 1};
	int lo = 0;
	int hi = 1;
	fw("mergeSort 1");
	mergeSort(a1, lo, hi);
	print_array_int(a1, 2, 2);
  }
  {
	int a1[3] = {2, 4, 1};
	int lo = 0;
	int hi = 2;
	fw("mergeSort 2");
	mergeSort(a1, lo, hi);
	print_array_int(a1, 3, 3);
  }
  {
	int a1[8] = {2, 4, 1, 9, 9, 3, 4, 9};
	int lo = 0;
	int hi = 7;
	fw("mergeSort 3");
	mergeSort(a1, lo, hi);
	print_array_int(a1, 8, 8);
  }
  {
	const int len = 9;
	const int width = 3;
	float arr[len] = {2.0,   4,    8000000,
					  500, 7,    6,
					  8,   3000, 5};
	print_matrix_float(arr, len, width);
  }
  {
	int n = 314;
	char buf[20];
	intToStr_c(buf, n);
	printf("%s\n", buf);
  }

  return(0);
}
