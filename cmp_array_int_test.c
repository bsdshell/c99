#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "/Users/aaa/myfile/github/c99lib/my_vector.h"
#include "/Users/aaa/myfile/github/c99lib/AronCLibDev.h"

/*
    COMPILE: gcc -I../clib try1.c -o try1
    COMPILE: run.sh
*/


typedef struct Num{
  bool isNeg;   // 0 => positive, 1 => negative
  int len;
  int* arr;
} Num;

void mkNum(int* arr, int len, Num *num){
  num -> isNeg = 0;
  num -> len = len;
  num -> arr = (int*)malloc(sizeof(int) * len);
  for(int i = 0; i < len; i++){
	num -> arr[i] = arr[i];
  }
}

void print_num(Num num){
  printf("isNeg = %d\n", num.isNeg);
  printf("len   = %d\n", num.len);
  print_array_int(num.arr, num.len, num.len);
}

int max_c(int a, int b){
  return a > b ? a : b;
}

int mul_int_c(int a, int b){
  return a * b;
}

float mul_float_c(float a, float b){
  return a * b;
}
double mul_double_c(double a, double b){
  return a * b;
}

int add_int_c(int a, int b){
  return a + b;
}

float add_float_c(float a, float b){
  return a + b;
}

double add_double_c(double a, double b){
  return a + b;
}

int min_c(int a, int b){
  return a > b ? b : a;
}

void rev_array_int(int* arr, int len){
  for(int i = 0; i < len/2; i++){
	int j = len - 1 - i;
	swap(arr, i, j);
  }
}

/*
  NOTE: len of retArr >= len + 1
        len of arr0 == len of arr1

	   1 1 0    <- c
	   --------
	     9 9    <- arr0
		 8 2    <- arr1
	   --------
	   1 8 1    <- retArr


	   [ 0, 1, 2]  => 12
	     |
		 + -> sign bit, 0 => positive, 1 => negative
		 
	   [ 1, 1, 2]  => -12
	     |
		 + -> sign bit, 0 => positive, 1 => negative
		 
 */
void add_array_int(int* arr0, int* arr1, int len, int* retArr){
  int c = 0;
  
  for(int i = 1; i < len; i++){
	int rx = len - 1 - i;
	int s = arr0[rx + 1] + arr1[rx + 1] + c;
	retArr[rx + 1] = s % 10;
	c = s / 10;
  }
  retArr[1] = c;
}


void subArr(int* arr0, int* arr1, int* retArr, int len){
  for(int i = 0; i < len; i++){
	if(arr0[i] - arr1[i] == 0){
	  retArr[i] = 0;
	}else if(arr0[i] > arr1[i]){
	  retArr[i] = 1;
	}else{
	  retArr[i] = -1;
	}
  }
}

bool fx(int a){
  return a == 0;
}

void dropWhile(bool(*f)(int a), int* arr, int len, int* retArr, int* retLen){
  int count = 0;
  bool done = false;
  for(int i = 0; i < len && !done; i++){
	if(f(arr[i])){
	  count++;
	}else{
	  done = true;
	}
  }
  int x = 0;
  for(int i = count; i < len; i++){
	retArr[x] = arr[i];
	x++;
  }
  *retLen = x;
}

void takeWhile(bool(*f)(int a), int* arr, int len, int* retArr, int* retLen){
  int count = 0;
  bool done = false;
  for(int i = 0; i < len && !done; i++){
	if(f(arr[i])){
	  count++;
	}else{
	  done = true;
	}
  }
  int x = 0;
  for(int i = 0; i < count; i++){
	retArr[x] = arr[i];
	x++;
  }
  *retLen = x;
}


int noneZero(int* arr, int len){
  int ret = -1;
  for(int i = 0; i < len && ret == -1; i++){
	if(arr[i] == 0){
	  ret = i;
	}
  }
  return ret;
}

int cmp_array_int(int* arr0, int* arr1, int len){
  int ret = 0;
  for(int i = 0; i < len; i++){
	  int x0 = arr0[0];
	  int x1 = arr1[0];
	  int y0 = arr0[1];
	  int y1 = arr1[1];
	  if(x0 == 1 && y0 == 0){
		printf("ERROR 1");
	  }else if(x1 == 1 && y1 == 0){
		printf("ERROR 2");
	  }else if(x0 == x1 && x0 == 0 && y0 == y1 && y0 == 0){
		ret = 0;
	  }else if(x0 == 0 && x1 == 1){
		ret = 1;
	  }else if(x0 == 1 && x1 == 0){
		ret = -1;
	  }else if((x0 == 0 && x1 == 0) || (x0 == 1 && x1 == 1)){
		int* arr = (int*)malloc(sizeof(int) * len);
		int k = 0;
		for(int i = 1; i < len; i++){
		  arr[k] = arr0[i] == arr1[i] ? 0 : (arr0[i] > arr1[i] ? 1 : -1);
		  k++;
		}
		int* retArr = (int*)malloc(sizeof(int) * k);
		int retLen = 0;
		dropWhile(fx, arr, k, retArr, &retLen);
		if(retLen == 0){
		  ret = 0;
		}else{
		  ret = retArr[0];
		}

		fw("retArr 0");
		print_array_int(retArr, k, k);

		free(retArr);
		free(arr);
		
		ret = x0 == 1 && x1 == 1 ? -ret : ret;
	  }
  }
  return ret;
}


void sub_array_int(int* arr0, int* arr1, int len, int* retArr){

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
  {
	const int len = 1;
	int arr0[] = {9};
	int arr1[] = {8};
	int retArr[2];
	int expArr[2] = {1, 7};

	fw("add_array_int 1");
	add_array_int(arr0, arr1, 1, retArr);
	print_array_int(retArr, 2, 2);
	t_array_int(2, retArr, 2, expArr, "add_array_int 1");
  }

  {
	const int len = 3;
	int arr[] = {1, 2, 3};
    int expArr[] = {3, 2, 1};
	int retArr[len];
	rev_array_int(arr, len);
	print_array_int(arr, len, len);
	t_array_int(len, arr, len, expArr, "rev_array_int 1");
  }
  {
	const int len = 4;
	int arr[len];
	gene_array_int(arr, len, 1, 9);
	print_array_int(arr, len, 1);

	int s = foldl_int(max_c, 0, arr, len);
	printf("max_c=%d\n", s);
  }
  {
	/*
	     9 9
		 8 2
	   --------
	   0 1 7
	*/
	const int len = 2;
	int arr0[] = {9, 9};
	int arr1[] = {8, 2};
	int retArr[3];
	int expArr[3] = {0, 1, 7};

	fw("sub_array_int 1");
  }
  {
	/*
	*/
	const int len = 2;
	int arr0[] = {9, 9};
	int arr1[] = {8, 2};
	int retArr[3];
	int expArr[3] = {0, 1, 7};
	fw("sub_array_int 1");
  }
  {
	const int len = 3;
	Num num;
    int arr[] = {1, 2, 3};
	mkNum(arr, len, &num);
	print_num(num);
	free(num.arr);
  }

  {
	const int len = 4;
	int arr0[len] = {1, 4, 2, 3};
	int arr1[len];
	int retLen = 0;
	fw("dropWhile");
	dropWhile(fx, arr0, len, arr1, &retLen);
	print_array_int(arr1, retLen, retLen);
  }
  {
	const int len = 4;
	int arr0[len] = {0, 4, 2, 3};
	int arr1[len];
	int retLen = 0;
	fw("dropWhile");
	dropWhile(fx, arr0, len, arr1, &retLen);
	print_array_int(arr1, retLen, retLen);
  }
  {
	const int len = 4;
	int arr0[len] = {0, 4, 2, 0};
	int arr1[len];
	int retLen = 0;
	fw("dropWhile");
	dropWhile(fx, arr0, len, arr1, &retLen);
	print_array_int(arr1, retLen, retLen);
  }
  {
	const int len = 4;
	int arr0[len] = {0, 4, 2, 0};
	int arr1[len];
	int retLen = 0;
	fw("takeWhile 1");
	takeWhile(fx, arr0, len, arr1, &retLen);
	print_array_int(arr1, retLen, retLen);
  }
  {
	const int len = 4;
	int arr0[len] = {3, 4, 2, 0};
	int arr1[len];
	int retLen = 0;
	fw("takeWhile 2");
	takeWhile(fx, arr0, len, arr1, &retLen);
	print_array_int(arr1, retLen, retLen);
  }
  {
	const int len = 4;
	int arr0[len] = {0, 0, 2, 0};
	int arr1[len];
	int retLen = 0;
	fw("takeWhile 3");
	takeWhile(fx, arr0, len, arr1, &retLen);
	print_array_int(arr1, retLen, retLen);
  }
  {
	const int len = 4;
	int arr0[len] = {1, 2, 3, 4};
	int arr1[len] = {0, 2, 0, 5};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 0");
	t_int(b, -1, "t_int 0");
  }
  {
	const int len = 4;
	int arr0[len] = {0, 2, 3, 4};
	int arr1[len] = {1, 2, 0, 5};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 1");
	t_int(b, 1, "t_int 1");
  }
  {
	const int len = 4;
	int arr0[len] = {1, 2, 3, 4};
	int arr1[len] = {1, 2, 0, 5};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 2");
	t_int(b, -1, "t_int 2");
  }
  {
	const int len = 4;
	int arr0[len] = {0, 2, 3, 4};
	int arr1[len] = {0, 2, 0, 5};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 3");
	t_int(b, 1, "t_int 3");
  }
  {
	const int len = 4;
	int arr0[len] = {0, 2, 3, 4};
	int arr1[len] = {0, 2, 3, 5};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 4");
	t_int(b, -1, "t_int 4");
  }
  {
	const int len = 4;
	int arr0[len] = {0, 2, 3, 4};
	int arr1[len] = {0, 2, 3, 4};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 5");
	t_int(b, 0, "t_int 5");
  }
  {
	const int len = 4;
	int arr0[len] = {0, 2, 3, 4};
	int arr1[len] = {1, 2, 3, 4};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 6");
	t_int(b, 1, "t_int 6");
  }
  {
	const int len = 4;
	int arr0[len] = {0, 0, 3, 4};
	int arr1[len] = {0, 0, 3, 4};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 7");
	t_int(b, 0, "t_int 7");
  }
  {
	const int len = 2;
	int arr0[len] = {0, 0};
	int arr1[len] = {0, 0};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 8");
	t_int(b, 0, "t_int 8");
  }
  {
	const int len = 2;
	int arr0[len] = {0, 0};
	int arr1[len] = {0, 1};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 9");
	t_int(b, -1, "t_int 9");
  }
  {
	const int len = 2;
	int arr0[len] = {0, 2};
	int arr1[len] = {0, 1};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 10");
	t_int(b, 1, "t_int 10");
  }
  {
	const int len = 2;
	int arr0[len] = {1, 2};
	int arr1[len] = {0, 1};
	int b = cmp_array_int(arr0, arr1, len);
	fw("cmp_array_int 11");
	t_int(b, -1, "t_int 11");
  }

  return(0);
}
