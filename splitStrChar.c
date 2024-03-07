#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <AronCLibNew.h>



void printCharPt2d(char** pt, int nCol){
  for(int i = 0; i < nCol; i++){
	printf("[%s]\n", pt[i]);
  }
}

void fun(char** pt){
  *pt = NULL;
}

// gcc myfile.c -o main
int main () {
   pp("Hello World C!\n");
   {
	 char c = '/';
	 char* str = "/";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 3, " splitStrChar xx 1");
	 t_charPt(retppt[0], "", " splitStrChar xx 2");
	 t_charPt(retppt[1], "/", " splitStrChar xx 2");
	 t_charPt(retppt[2], "", " splitStrChar xx 2");
	 printCharPt2d(retppt, retRow);
   }
   {
	 char c = '/';
	 char* str = "//";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 5,           " splitStrChar 1 ");
	 t_charPt(retppt[0], "",   " splitStrChar 2");
	 t_charPt(retppt[1], "/", " splitStrChar 3");
	 t_charPt(retppt[2], "", " splitStrChar  4");
	 t_charPt(retppt[3], "/", " splitStrChar  5");
	 t_charPt(retppt[4], "", " splitStrChar  5");
	 printCharPt2d(retppt, retRow);
   }
   {
	 char c = '.';
	 char* str = ".";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 3,           " splitStrChar kkk 1 ");
	 t_charPt(retppt[0], "",   " splitStrChar kkk 2");
	 t_charPt(retppt[1], ".", " splitStrChar kkk 3");
	 t_charPt(retppt[2], "", " splitStrChar  kkk 4");
	 printCharPt2d(retppt, retRow);
   }
   {
	 char c = '.';
	 char* str = "c";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 1,           " splitStrChar ee 1 ");
	 t_charPt(retppt[0], "c",   " splitStrChar ee 2");
	 printCharPt2d(retppt, retRow);
   }
   {
	 char c = '/';
	 char* str = "/tmp/f.x";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 5,           " splitStrChar kk 1 ");
	 t_charPt(retppt[0], "",    " splitStrChar kk 2");
	 t_charPt(retppt[1], "/",   " splitStrChar kk 3");
	 t_charPt(retppt[2], "tmp", " splitStrChar kk 4");
	 t_charPt(retppt[3], "/",   " splitStrChar kk 5");
	 t_charPt(retppt[4], "f.x",   " splitStrChar kk 6");
	 printCharPt2d(retppt, retRow);

   }
   {
	 char c = '/';
	 char* str = "tmp/f.x";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 3,           " splitStrChar ee 1 ");
	 t_charPt(retppt[0], "tmp",   " splitStrChar ee 2");
	 t_charPt(retppt[1], "/", " splitStrChar ee 3");
	 t_charPt(retppt[2], "f.x",   " splitStrChar ee 4");
	 printCharPt2d(retppt, retRow);
   }
   {
	 char c = '/';
	 char* str = "f.x";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 1,           " splitStrChar cc 1 ");
	 t_charPt(retppt[0], "f.x",   " splitStrChar cc 2");
	 for(int i = 0; i < retRow; i++){
	   pp("retppt=%s\n", retppt[i]);
	 }
   }
   {
	 char c = '/';
	 char* str = "/f.x";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 3,           " splitStrChar jj 1 ");
	 t_charPt(retppt[0], "",   " splitStrChar jj 2");
	 t_charPt(retppt[1], "/",   " splitStrChar jj 3");
	 t_charPt(retppt[2], "f.x",   " splitStrChar jj 4");
	 
	 printCharPt2d(retppt, retRow);

   }
   {
	 char c = '.';
	 char* str = "/f.x";
	 int bufLen = strlen(str);
	 int retRow = 0;
	 char** retppt = splitStrChar(str, bufLen, &retRow, c);
	 t_int(retRow, 3,           " splitStrChar bb 1 ");
	 t_charPt(retppt[0], "/f",   " splitStrChar bb 2");
	 t_charPt(retppt[1], ".",   " splitStrChar bb 3");
	 t_charPt(retppt[2], "x",   " splitStrChar bb 4");
	 printCharPt2d(retppt, retRow);
	 
   }
   {
	 char* pt = "abc";
	 fun(&pt);
	 if(pt){
	   pp("pt is NOT NULL\n");
	 }else{
	   pp("pt is NULL\n");
	 }
   }
   
   return(0);
}
