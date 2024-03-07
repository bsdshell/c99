#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <AronCLibNew.h>

/*
   dropExt("abc")   => "abc"
   dropext("abc.")  => "abc"
   dropExt("abc.x") => "abc"

   abc. => "abc" "." ""
   .abc => "", "." "abc"
 */
char* dropExt(char* strPt){
  char* pt = NULL;
  
  int bufLen = strlen(strPt);
  int retRow = 0;
  bool foundDot = false;
  int c = '.';
  char** ppt = splitStrChar(strPt, bufLen, &retRow, c);
   if(retRow > 0){
	 for(int i = retRow - 1; i >= 0 && !foundDot; i--){
	   if(strcmp(ppt[i], ".") == 0){
		 pt = concatStr(ppt, i);
		 foundDot = true;
	   }
	 }
	 if(!foundDot){
	   pt = concatStr(ppt, retRow);
	 }
  }
  free_splitStrChar(ppt, retRow);
  return pt;
}
// gcc myfile.c -o main
int main () {
  {
	char* str = "abc";
	char* pt = dropExt(str);
	printf("pt=[%s]\n", pt);
	t_charPt(pt, "abc", " dropExt 1");
	free(pt);
  }
  
  {
	char* str = "abc.";
	char* pt = dropExt(str);
	printf("pt=[%s]\n", pt);
	t_charPt(pt, "abc", " dropExt 2");
	free(pt);
  }
  
  {
	char* str = "abc.x";
	char* pt = dropExt(str);
	t_charPt(pt, "abc", " dropExt 3");
	free(pt);
  }
  {
	char* str = ".x";
	char* pt = dropExt(str);
	t_charPt(pt, "", " dropExt 4");
	free(pt);
  }
  {
	char* str = "/tmp/f.x";
	char* pt = dropExt(str);
	t_charPt(pt, "/tmp/f", " dropExt 5");
	free(pt);
  }
  {
	char* str = "/tmp/";
	char* pt = dropExt(str);
	t_charPt(pt, "/tmp/", " dropExt 6");
	free(pt);
  }
  
   return(0);
}
