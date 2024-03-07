#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <AronCLibNew.h>

void test0(){
    {
        char* str = "";
        bool b = all_digit(str);
        t_bool(b, false, "all_digit 0");
    }
    {
        char* str = "012";
        bool b = all_digit(str);
        t_bool(b, true, "all_digit 1");
    }

    {
        char* str = "0";
        bool b = all_digit(str);
        t_bool(b, true, "all_digit 2");
    }
    {
        char* str = "a";
        bool b = all_digit(str);
        t_bool(b, false, "all_digit 3");
    }
    {
        char* str = "a1";
        bool b = all_digit(str);
        t_bool(b, false, "all_digit 4");
    }
}

void test1(){
    {
        char* str = "0";
        int sum = strToInt(str);
        t_int(sum, 0, "strToInt 1");
    }
    {
        char* str = "1";
        int sum = strToInt(str);
        t_int(sum, 1, "strToInt 2");
    }
    {
        char* str = "10";
        int sum = strToInt(str);
        t_int(sum, 10, "strToInt 3");
    }
    {
        char* str = "123";
        int sum = strToInt(str);
        t_int(sum, 123, "strToInt 4");
    }
    {
        char* str = "12abc";
        int sum = strToInt(str);
        t_int(sum, -1, "strToInt 5");
    }
}

void test2(){
    {
        int n = 3;
        char c = 'a';
        char* pt = repeatChar(n, c);
        t_charPt(pt, "aaa", "repeatChar 1");
        if(pt){
            free(pt);
        }
    }
    {
        int n = 0;
        char c = 'a';
        char* pt = repeatChar(n, c);
        t_charPt(pt, "", "repeatChar 2");
        if(pt){
            free(pt);
        }
    }
    {
        int n = 1;
        char c = 'a';
        char* pt = repeatChar(n, c);
        t_charPt(pt, "a", "repeatChar 3");
        if(pt){
            free(pt);
        }
    }
    {
        int n = 2;
        char c = '-';
        char* pt = repeatChar(n, c);
        t_charPt(pt, "--", "repeatChar 4");
        if(pt){
            free(pt);
        }
    }
    {
        int n = 2;
        char c = '/';
        char* pt = repeatChar(n, c);
        t_charPt(pt, "//", "repeatChar 5");
        if(pt){
            free(pt);
        }
    }
}

// gcc myfile.c -o main
int main (int argc, char* argv[]) {
  if(argc == 3){
    char* pt = NULL;
	char* s = argv[2];
    int n = strToInt(argv[1]);
    int slen = strlen(s);

    if(n != -1 && slen > 0){
        // take the first char ONLY
        char c = s[0];
        pt = repeatChar(n, c);
    }
    printf("%s", pt);

    if(pt){
        free(pt);
    }
  }else{
	printf("repeatChar 3 a => aaa");
  }

  // test0();
  // test1();
  // test2();

  return(0);
}
