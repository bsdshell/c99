#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <AronCLibNew.h>


/*

  KEY: concat ALL strings to ONE string
  
  pt[0] = "abc"
  pt[1] = "def"
  pt[2] = "hij"
  int len = 3
  char* str = concatStr(pt, len);
  str = "abcdefhij"

 */

// gcc myfile.c -o main
int main () {
   pp("Test concatStr\n");
   {
	 pp("concatStr 1\n");
	 int n = 3;
	 char** pt = (char**)malloc(sizeof(char*)*n);
	 for(int i = 0; i < n; i++){
	   pt[i] = (char*)malloc(sizeof(char)*10);
	   char* str = "abc";
	   int len = strlen(str);
	   memcpy(pt[i], str, len);
	   pt[i][len] = '\0';
	 }
	 
	 char* s = concatStr(pt, n);
	 pp("s=%s\n", s);
	 free_concatStr(s);
	 
	 for(int i = 0; i < n; i++){
	   if(pt[i]){
		 free(pt[i]);
		 pt[i] = NULL;
	   }
	 }
   }

   {
	 int nCol = 1;
	 int nRow = 10;
	 char* str = "";
	 int len = strlen(str);
	 
	 char** ppt = allocateCharPt(nCol, nRow);
	 memcpy(ppt[0], str, len);
	 
	 ppt[0][len] = '\0';

	 char* strPt = concatStr(ppt, nCol);
	 t_charPt(strPt, str, "concatStr test 0");
	 free(strPt);
	 free_allocateCharPt(ppt, nCol);
   }
   {
	 int nCol = 1;
	 int nRow = 10;
	 char* str = "abc";
	 int len = strlen(str);
	 
	 char** ppt = allocateCharPt(nCol, nRow);
	 memcpy(ppt[0], str, len);
	 
	 ppt[0][len] = '\0';

	 char* strPt = concatStr(ppt, nCol);
	 t_charPt(strPt, str, "concatStr test 1");
	 free(strPt);
	 free_allocateCharPt(ppt, nCol);
   }
   {
	 int nCol = 2;
	 int nRow = 10;
	 char* str1 = "dog";
	 char* str2 = "cat";
	 int len1 = strlen(str1);
	 int len2 = strlen(str2);
	 
	 char** ppt = allocateCharPt(nCol, nRow);
	 memcpy(ppt[0], str1, len1);
	 memcpy(ppt[1], str2, len2);
	 
	 ppt[0][len1] = '\0';
	 ppt[1][len2] = '\0';
	 

	 char* strPt = concatStr(ppt, nCol);
	 t_charPt(strPt, "dogcat", "concatStr test 2");
	 free(strPt);
	 free_allocateCharPt(ppt, nCol);
   }
   {
	 int nCol = 2;
	 int nRow = 10;
	 char* str1 = "";
	 char* str2 = "cat";
	 int len1 = strlen(str1);
	 int len2 = strlen(str2);
	 
	 char** ppt = allocateCharPt(nCol, nRow);
	 memcpy(ppt[0], str1, len1);
	 memcpy(ppt[1], str2, len2);
	 
	 ppt[0][len1] = '\0';
	 ppt[1][len2] = '\0';
	 
	 char* strPt = concatStr(ppt, nCol);
	 t_charPt(strPt, "cat", "concatStr test 3");
	 pp("strPt=%s\n", strPt);
	 
	 free(strPt);
	 free_allocateCharPt(ppt, nCol);
   }
   
   {
	 int nCol = 3;
	 int nRow = 10;
	 char* str1 = "cat";
	 char* str2 = "dog";
	 char* str3 = "cowfox";
	 int len1 = strlen(str1);
	 int len2 = strlen(str2);
	 int len3 = strlen(str3);
	 
	 char** ppt = allocateCharPt(nCol, nRow);
	 memcpy(ppt[0], str1, len1);
	 ppt[0][len1] = '\0';
	 memcpy(ppt[1], str2, len2);
	 ppt[1][len2] = '\0';
	 memcpy(ppt[2], str3, len3);
	 ppt[2][len3] = '\0';
	 
	 char* strPt = concatStr(ppt, nCol);
	 t_charPt(strPt, "catdogcowfox", "concatStr test 4");
	 t_int(strlen(strPt), len1 + len2 + len3, " concatStr check length 1");
	 pp("strPt=%s\n", strPt);
	 
	 free(strPt);
	 free_allocateCharPt(ppt, nCol);
   }
   return(0);
}
