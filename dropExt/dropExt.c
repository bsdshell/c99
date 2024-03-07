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
int main (int argc, char* argv[]) {
  if(argc == 2){
	char* pt = dropExt(argv[1]);
	printf("%s", pt);
	free(pt);
  }else{
	printf("dropExt /tmp/f.x => /tmp/f\n");
  }
   return(0);
}
