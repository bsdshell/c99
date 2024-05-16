#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AronCLibNew.h"

int countLineFile(char* fname);

char** readFileToBuffer(char* fname, int *len);
char* readFilePt(char* fname, int *len);


/*
 * Thu  7 Mar 16:35:17 2024  
 *
 * return -1 if there is error
 *
 * long size = getFileSize("/tmp/f.x")
 */
long getFileSize(char* fname){
  long size = -1;
  char* line = NULL;
  ssize_t read;
  FILE* stream = fopen(fname, "rb");  // rb => binary mode 
  if(stream == NULL){
    printf("ERROR: open file=%s\n", fname);
    exit(EXIT_FAILURE);
  }

  if(fseek(stream, 0, SEEK_END) == 0){
    size = ftell(stream);
    if(size == -1){
      printf("ERROR: ftell error=%s\n", fname);
      exit(EXIT_FAILURE);
    }
    rewind(stream);
  }
  return size;
}

int countLineFile(char* fname){
  FILE* fp;
  char* line = NULL;
  ssize_t read;
  fp = fopen(fname, "rb");
  if(fp == NULL){
    exit(EXIT_FAILURE);
  }

  size_t maxLen = 0;
  int inx = 0;
  while((read = getline(&line, &maxLen, fp)) != -1){
    inx++;
  }

  if(fp) 
    fclose(fp);
  if(line) 
    free(line);

  return inx;
}

char* readFilePt(char* fname, int *retLen){
    int len = 0;
    char** b2 = readFileToBuffer(fname, &len);
    int c = 0;
    for(int i = 0; i < len; i++){
        c +=strlen(b2[i]) + 1;
    }
    char* pt = (char*)malloc(sizeof(char)*c); 
    char* ret = pt;

    for(int i = 0; i <len; i++){
        int n = strlen(b2[i]) + 1;  // strlen(str) + '\n'
        memcpy(pt, b2[i], n);
        pt += n; 
    }

    for(int i = 0; i < len; i++){
      free(b2[i]);
    }
    free(b2);

    *retLen = c;

    return ret;

}

char** readFileToBuffer(char* fname, int *len){
  FILE* fp;
  char* line = NULL;
  ssize_t read;
  fp = fopen(fname, "rb");
  if(fp == NULL){
    exit(EXIT_FAILURE);
  }
  
  int nLine = countLineFile(fname);
  char** pt = (char**)malloc(sizeof(char*)*nLine);

  int inx = 0;
  size_t maxLen = 0;
  while((read = getline(&line, &maxLen, fp)) != -1){
    printf("read=%d line=%s maxLen=%d\n", read, line, maxLen);
    pt[inx] = (char*)malloc(sizeof(char)*(strlen(line) + 1));
    strcpy(pt[inx], line); // strcpy(destination, source), including null '\0'
    inx++;
  }
  printf("inx=%d\n", inx);

  *len = inx;
  
  if(fp)
    fclose(fp);
  if(line)
    free(line);
  return pt;
}

// gcc myfile.c -o main
int main () {
    {
      int len = 0;
      char** pt = readFileToBuffer("./test.txt", &len);
      printf("len=%d\n", len);
      for(int i = 0; i < len; i++){
         printf("%s", pt[i]);
      }
    }

   {
     int len = 0;
     char* fname = "./test.txt";
     char* pt = readFilePt(fname, &len);
     char* dp = pt;
     printf("readFile\n");
     
     int i = 0;
     while(len > 0){
       printf("%s", pt);
       int n = strlen(pt) + 1;
       pt += n;
       len -= n;
     }
     free(dp);
   } 
   {
     int len = 0;
     char* fname = "./test.txt";
     char* pt = readFilePt(fname, &len);
     char* dp = pt;
     printf("readFile\n");
     printf("len pt = %d\n", strlen(pt));
     printf("len dp = %d\n", strlen(dp));
     
     int i = 0;
     while(len > 0){
       printf("%s", pt);
       int n = strlen(pt) + 1;
       pt += n;
       len -= n;
     }
     free(dp);
   } 

   {
     char* fn = "./f.x";
     long size = getFileSize(fn);
     printf("%s, size=%d\n", fn, size);
   }

   return(0);
}
