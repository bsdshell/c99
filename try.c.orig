#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "/Users/aaa/myfile/github/c99lib/AronCLibNew.h"
#include "/Users/aaa/myfile/github/c99libtest/my_vector.h"

enum {IP_LEN = 20};
// BEG_flow
// const int IP_LEN = 20;   //  255.255.255.255 + '\0' = 3*4 + 4 + 1;
const int FLOW_STR_LEN = 200;
typedef struct {
  char source_ip[IP_LEN];
  char dest_ip[IP_LEN];
  unsigned short source_port;
  unsigned short dest_port;
  unsigned char protocol;
} flow;

typedef struct {
  flow* flowPt;
  struct flow_node_* next;
  unsigned long count;
} flow_node;


// URL xfido.com/publicfile/codedoc/hash_table_implementation.svg
typedef struct {
  int max;
  int count;
  // flow_node** flow_node_arr;
  void ** flow_node_arr;
} hash_table;

// BEG_test_only
typedef struct {
  char name[50];
  int age;
} person;

typedef struct MyStuff;

typedef struct {
  int n;
  char* str;
  void (*free)(struct MyStuff*);
  void (*add)(struct MyStuff*, void*);
} MyStuff;

// BEG_single_linked_list
typedef struct {
  unsigned long key;
  char arr[100];
  struct node *next;
  // void (*add)(struct Node_* self);
} node;

// END_test_only




void flow_to_str(unsigned char* buf, const int size, flow* pt);
unsigned long hash_flow(flow* pt);
bool is_equal_flow_str(flow* flowPt1, flow* flowPt2);
void print_flow_node(flow_node* pt);

void print_flow(flow* pt);
char* to_str(flow* pt);
flow* make_flow();
void hash_table_init(hash_table* self);
void free_hash_table(hash_table* self);
void insert_hash_table(hash_table* self, flow_node* fnPt);
bool hash_table_contain(hash_table* self, flow_node* fnPt);
void print_hash_table(hash_table* self);
void free_flow_node(flow_node* fnPt);
bool is_equal_flow_str(flow* flowPt1, flow* flowPt2);
void print_flow_node(flow_node* pt);
void print_flow_node_list(flow_node* head);
bool isBucketEmpty(flow_node* pt);
void mystuff_free(MyStuff* self);
void mystuff_add(struct MyStuff* self, void* data);
void mystuff_init(MyStuff* self);
node* remove_first(node* self);
node* remove_last(node* self);
node* make_node(unsigned long key, const char* str);
void print_list(node* head);
void free_node(node* self);
unsigned long hash(unsigned char *str);
void fun(char** pt);
void myfun(person* pt);
void to_string(char* restrict_str, size_t size, const char* restrict_format, ...);
void flow_to_str(unsigned char* buf, const int size, flow* pt);
unsigned long hash_flow(flow* pt);
flow* build_flow(
				 char source_ip[IP_LEN],
				 char dest_ip[IP_LEN],
				 unsigned short source_port,
				 unsigned short dest_port,
				 unsigned char protocol
				 );

char** readFileToBuffer(char* fname, int fixedLen, int *len);
void splitStrXX(Vector* vector, char** str, const char* delimiter);
char* trim(char* str);
int* vectorToArray_int(Vector vector);
double* vectorToArray_double(Vector vectort);
long* vectorToArray_long(Vector vectort);

// concat two char* 
char* concat(const char *s1, const char *s2) {
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
	char* result = (char*)malloc(sizeof(char) * (len1 + len2));
    if(result != NULL){
        strcpy(result, s1);
        strcpy(result + len1, s2);
    }
	return result;
}



/**
   KEY: trim leading and tailing whitespace c = ' '
   NOTE: Update the code to support newline = '\n' and tab = '\t'
   DATE: Monday, 16 May 2022 02:10 PDT
   
   char* str = "   a bc ";
   char* newStr = trim(str);
   t(cmpStr(newStr, "a bc"), "204 newStr => abc");
   free(newStr);

   fw("trim 2");
   char arr[50] = " \t314159\n ";
   char* pt = trim(arr);
   t_charPt(pt, "314159", "trim 2");
   printf("pt=[%s]\n", pt);
   free(pt);
   
*/
char* trim(char* str){
  const char SP = ' ';
  const char TAB = '\t';
  const char NL = '\n';
  char* newStr = NULL;
  int slen = strlen(str); // NOT including '\0'
  if(slen == 0){
    newStr = (char*)malloc(sizeof(char));
    newStr[0] = '\0';
  }else{
    int lx = 0;
    int rx = slen - 1;
    while(lx <= rx && ((str[lx] == SP || str[lx] == TAB || str[lx] == NL) || (str[rx] == SP || str[rx] == TAB || str[rx] == NL))){
      if(str[lx] == SP || str[lx] == TAB || str[lx] == NL){
		lx++;
      }

	  if(str[rx] == SP || str[rx] == TAB || str[rx] == NL){
		rx--;
      }
    }
    if(lx > rx){
      newStr = (char*)malloc(sizeof(char));
      newStr[0] = '\0';
    }else{
      newStr = (char*)malloc(sizeof(char)*(slen - lx - (slen - 1 - rx) + 1));
      strncpy(newStr, str + lx, slen - lx - (slen - 1 - rx));
      newStr[slen - lx - (slen - 1 - rx)] = '\0'; // null string
    }
  }
  return newStr;
}

int* vectorToArray_int(Vector vector){
  int* arr = (int*)malloc( sizeof(int) * vector.count );
  for(int i = 0; i < vector.count; i++){
	arr[i] = atoi(vector.data[i]);
  }
  return arr;
}

double* vectorToArray_double(Vector vector){
  double* arr = (double*)malloc( sizeof(double) * vector.count );
  for(int i = 0; i < vector.count; i++){
	arr[i] = atof(vector.data[i]);
  }
  return arr;
}

long* vectorToArray_long(Vector vector){
  long* arr = (long*)malloc( sizeof(long) * vector.count );
  for(int i = 0; i < vector.count; i++){
	arr[i] = atol(vector.data[i]);
  }
  return arr;
}

/*
 NOTE: need to free pt from outside the function
 USE: free2d(pt, len)
 From: $b/clib/AronCLib.h

 fw("readFileToBuffer 1");
 char* fname = "/tmp/x";
 int len = 10;
 char** pt = readFileToBuffer(fname, &len);
 for(int i = 0; i < len; i++){
   pp("%s", pt[i]);
 }
 
**/
char** readFileToBuffer(char* fname, int fixedLen, int *len){
  FILE* fp;
  char* line = NULL;
  ssize_t read;
  fp = fopen(fname, "r");
  if(fp == NULL){
	printf("ERROR: read file:%s\n", fname);
    exit(EXIT_FAILURE);
  }
  
  /* 
   char** -> pt[0] -> char* -> "abc"
   char** -> pt[1] -> char* -> "def"

      [0]    [1]
    ["abc", "efg"]
  */
  char** pt = (char**)malloc(sizeof(char*)*fixedLen);

  int inx = 0;
  size_t maxLen = 0;
  while((read = getline(&line, &maxLen, fp)) != -1){
    // printf("read=%d line=%s", read, line);
    // pt[inx] = (char*)malloc(sizeof(char)*(strlen(line) + 1));
	pt[inx] = (char*)malloc(sizeof(char)*maxLen);
    strcpy(pt[inx], line); // strcpy(source, destination), including null '\0'
    inx++;
  }
  *len = inx;
  
  if(fp)
    fclose(fp);
  if(line)
    free(line);
  return pt;
}






void swap(int* arr, int i, int j){
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

/**
   Partition an array with pivot, return index of the pivot
   1, 2, 4, 3
   1 < 3
            1
   2 < 3
   1  2 
   4 > 3
   1   2    4
   3 == 3
         3
   1 2	 3  4

   x
   2 3
   .
     x
   2 3
     .
	 
   
   1 3 2
   x
     x
	   .
   1 2 3
       x
 */
int partition_array(int* arr, int lo, int hi){
  int bigInx = lo;
  int pivotInx = lo;
  int pivot = arr[hi];
  for(int i = lo; i <= hi; i++){
	if(arr[i] <= pivot){
	  swap(arr, bigInx, i);
	  pivotInx = bigInx;
	  bigInx++;
	}
  }
  return pivotInx;
}


void quick_sort(int* arr, int lo, int hi){
  if(lo < hi){
	int pivotInx = partition_array(arr, lo, hi);
	quick_sort(arr, lo, pivotInx - 1);
	quick_sort(arr, pivotInx + 1, hi);
  }
}


void print_flow(flow* pt){
  if(pt != NULL){
	pl("source_ip=[%s]", pt -> source_ip);
	pl("source_ip len=[%d]", strlen(pt -> source_ip));

	pl("dest_ip=[%s]", pt -> dest_ip);
	pl("dest_ip len=[%d]", strlen(pt -> dest_ip));

	pl("source_port=[%u]", pt -> source_port);
	pl("dest_port=[%u]", pt -> dest_port);

	pl("protocol=[%u]", pt -> protocol);
	pl("hash=[%u]", hash_flow(pt));
  }else{
	pl("ERROR: pt is NULL");
  }
}

char* to_str(flow* pt){
  
}

flow* make_flow(){
  flow* pt = (flow*)malloc(sizeof(flow));
  strcpy(pt -> source_ip, "127.0.0.1");
  strcpy(pt -> dest_ip, "127.0.0.2");
  pt -> source_port = 21;
  pt -> dest_port = 106;
  pt -> protocol = 6;    // TCP
  return pt;
}

flow* build_flow(
				 char source_ip[IP_LEN],
				 char dest_ip[IP_LEN],
				 unsigned short source_port,
				 unsigned short dest_port,
				 unsigned char protocol
				 )
{
  flow* pt = (flow*)malloc(sizeof(flow));
  strcpy(pt -> source_ip, source_ip);
  strcpy(pt -> dest_ip, dest_ip);
  pt -> source_port = source_port;
  pt -> dest_port = dest_port;
  pt -> protocol = protocol;    // TCP
  return pt;
}

// END_flow

// BEG_flow_node

void hash_table_init(hash_table* self){
  self -> max = 2;
  self -> count = 0;
  self -> flow_node_arr = (flow_node**)malloc(sizeof(flow_node*) * self -> max);
  for(int i = 0; i < self -> max; i++){
	self -> flow_node_arr[i] = NULL;
  }
}
void hash_table_init_with(hash_table* self, unsigned long max){
  self -> max = max;
  self -> count = 0;
  self -> flow_node_arr = (flow_node**)malloc(sizeof(flow_node*) * self -> max);
  for(int i = 0; i < self -> max; i++){
	self -> flow_node_arr[i] = NULL;
  }
}

void free_hash_table(hash_table* self){
  // Iterate through  each spot in (int** flow_node_arr)
  // If the spot is NOT NULL then free the linked list with node: flow_node
  for(int i = 0; i < self -> max; i++){
	// free_flow_node frees the linked list
	free_flow_node(self -> flow_node_arr[i]);
  }
}

void print_hash_table(hash_table* self){
  pl("self -> max=[%d]", self -> max);
  pl("self -> count=[%d]", self -> count);
  for(int i = 0; i < self -> max; i++){
	pl("self -> flow_node_arr[%d]=>", i);
	print_flow_node_list(self -> flow_node_arr[i]);
  }
}

flow_node* make_flow_node(flow* flowPt){
  flow_node* pt = malloc(sizeof(flow_node));
  pt -> flowPt = flowPt;
  pt -> count = 1;
  pt -> next = NULL;
  return pt;
}

bool hash_table_contain(hash_table* self, flow_node* fnPt){
  bool ret = false;
  unsigned long key = hash_flow(fnPt -> flowPt) % self -> max;
  if(self -> flow_node_arr[key] != NULL){
	flow_node* curr = self -> flow_node_arr[key];
	while(curr && !ret){
	  if(is_equal_flow_str(curr -> flowPt, fnPt -> flowPt)){
		ret = true;
	  }
	  curr = curr -> next;
	}
  }
  return ret;
}

/*
  0. Insert flow_node to flow_node** array
  1. If the number of elements (self -> count < self -> max) in the hash table
  2. If the current spot is empty then just assign the flow_node* fnPt to the spot
  3. Otherwise, there is the spot is NOT empty
  Get the head of the linked list
  => flow_node_arr[key]
  iterate through all the nodes
  if the flow is the same as the current new flow
  Increase the count in the flow_node, done
  else
  Append the new flow to the end of the linked list
  4. If count is NOT less than the max
  Allocate a new flow_node** arr
  Iterate through the old array: flow_node** flow_node_arr
	   
  TODO: FIX BUG
  Get all the heads in flow_node_arr and Rehash each flow.
  (We only need to rehash all the heads, do not need to iterate through all the elements in the linked list)
  (Becase all the nodes in the linked list have the same hash key)
*/
void insert_hash_table(hash_table* self, flow_node* fnPt){
  if(self -> count < 5*self -> max){
	unsigned long key = hash_flow(fnPt -> flowPt) % self -> max;
	// flow_node* head = self -> flow_node_arr[key];
    // BEG insert flow_node here
	// flow_node* fn = insert_hash_table(head, fnPt);

	// No flow_node inside flow_node_arr[key]
	if(self -> flow_node_arr[key] == NULL){
	  self -> flow_node_arr[key] = fnPt;
	}else{
	  flow_node* curr = self -> flow_node_arr[key];
	  bool is_equal = false;
	  // XXX: BUG here
	  // 1. one node issue
	  // FIX: DONE
	  flow_node* prev = NULL;
	  while(curr && !is_equal){
		if(is_equal_flow_str(curr -> flowPt, fnPt -> flowPt)){
		  // Same flow
		  curr -> count += 1;
		  is_equal = true;
		}
		prev = curr;
		curr = curr -> next;
	  }
	  // Is curr the last node?
	  if(!is_equal && prev){
		prev -> next = fnPt;
	  }
	}
	self -> count++;
	// END inert flow_node here
  }else{
	// Rehash the hash table
	long old_max = self -> max;
	self -> max = 2*(self -> max);
	
	flow_node** arr = (flow_node**)malloc(sizeof(flow_node*) * self -> max);
	for(int i = 0; i < self -> max; i++){
	  arr[i] = NULL;
	}

	// Need to rehash all the nodes
	for(int i = 0; i < old_max; i++){
	  flow_node* curr = self -> flow_node_arr[i];
	  
	  while(curr){
		unsigned long key = hash_flow(curr -> flowPt) % self -> max;
		if(arr[key] == NULL){
		  arr[key] = curr;
		}else{
		  // hash collision
		  flow_node* tmp_curr = arr[key];
		  while(tmp_curr -> next){
            if(is_equal_flow_str(tmp_curr -> flowPt, curr -> flowPt)){
			  tmp_curr -> count++;
			  break;
			}else{
			  tmp_curr = tmp_curr -> next;
			}
		  }
		  // Can not match any node with same string
		  if(tmp_curr -> next == NULL){
			tmp_curr -> next = curr;
		  }
		}
		curr = curr -> next;
	  }
	}
	
	free(self -> flow_node_arr);
	self -> flow_node_arr = arr;
	insert_hash_table(self, fnPt);
  }
}
/*
   URL  xfido.com/publicfile/codedoc/delete_node.svg
 */
void free_flow_node(flow_node* fnPt){
  flow_node* curr = fnPt;
  while(curr){
	flow_node* tmp = curr;
	curr = curr -> next;
	free(tmp -> flowPt);
	free(tmp);
  }
}

flow_node* add_flow_node(flow_node* head, flow_node* fnPt){
  flow_node* ret = head;
  if(head == NULL){
	// head is NULL
	ret = fnPt;
  }else{
	flow_node* curr = head;
	while(curr -> next){
	  curr = curr -> next;
	}
	curr -> next = fnPt;
  }
  return ret;
}

bool is_equal_flow_str(flow* flowPt1, flow* flowPt2){
  unsigned char buf1[FLOW_STR_LEN];
  unsigned char buf2[FLOW_STR_LEN]; 
  flow_to_str(buf1, FLOW_STR_LEN, flowPt1);
  flow_to_str(buf2, FLOW_STR_LEN, flowPt2);
  return strcmp(buf1, buf2) == 0;
}

/*
  flow_node* insert_flow_node(flow_node* head, flow_node* fnPt){
  flow_node* ret = head;
  if(head == NULL){
  // head is NULL
  ret = fnPt;
  }else{
  // Compare each node
  // if two node have the same string
  //    break from the loop
  // otherwise, continue
  flow_node* curr = head;
  while(curr -> next){
  if(!is_equal_flow_str(curr -> flowPt, fnPt -> flowPt)){
  curr = curr -> next;
  }else{
  break;
  }
  }
  if(curr ->next == NULL){
  curr -> next = fnPt;
  }
  }
  return ret;
  }
*/

void print_flow_node(flow_node* pt){
  if(pt != NULL){
	print_flow(pt -> flowPt);
  }else{
	pl("ERROR: print_flow_node => flod_node* pt is NULL");
  }
}

void print_flow_node_list(flow_node* head){
  flow_node* curr = head;
  int count = 0;
  fw("print_flow_node_list ->");
  while(curr){
	print_flow_node(curr);
	count++;
	curr = curr -> next;
	fl("");
  }
  pl("linkedList node=>count node=>%d", count);
}

bool isBucketEmpty(flow_node* pt){
  bool ret = false;
  if(pt != NULL){
	pl("pt is not NULL KKK");
	ret = (pt -> flowPt == NULL) ? true : false; 
  }else{
	pl("ERROR: flow_node* pt is NULL");
	exit(1);
  }
  return ret;
}

// END_flow_node

// BEG_hash_table

// END_hash_table


void mystuff_free(MyStuff* self){
  free(self -> str);
}

void mystuff_add(struct MyStuff* self, void* data){
}

void mystuff_init(MyStuff* self){
  self -> n = 0;
  self -> str = (char*)malloc(sizeof(char) * 50);
  self -> add = &mystuff_add;
}





node* add(node* self, node* npt){
  if(self == NULL){
	return npt;
  }else{
	// Go to the last node
	node* curr = self;
	while(curr -> next){
	  curr = curr -> next;
	}
	curr -> next = npt;
	return curr;
  }
}

node* remove_first(node* self){
  node* curr = self;
  if(curr){
	node* tmp = curr;
	curr = curr -> next;
	free(tmp);
  }
  return curr;
}

node* remove_last(node* self){
  node* head;
  node* curr;
  head = curr = self;
  node* prev = NULL;
  if(curr){
	while(curr -> next){
	  prev = curr;
	  curr = curr -> next;
	}
  }
  if(prev){
	// More than one node
	prev -> next = NULL;
  }else{
	// One node ONLY
	head = NULL;
  }
  free(curr);
  return head;
}

node* make_node(unsigned long key, const char* str){
  node* pt = (node*)malloc(sizeof(node));
  pt -> key = key;
  strcpy(pt -> arr, str);
  pt -> next = NULL;
  return pt;
}

void print_list(node* head){
  node* curr = head;
  while(curr){
	printf("key=[%u] arr=[%s]\n", curr -> key, curr -> arr);
	curr = curr -> next;
  }
}

void free_node(node* self){
  node* curr = self;
  while(curr){
	node* next = curr -> next;
	free(curr);
	curr = next;
  }
}


// END_single_linked_list

// https://stackoverflow.com/questions/7666509/hash-function-for-string
unsigned long hash(unsigned char *str){
  unsigned long hash = 5381;
  int c;
  while(c = *str++){
	// pp("%d\n", c);
	hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  }
  return hash;
}

// void printCharPt2d(char** pt, int nCol){
  // for(int i = 0; i < nCol; i++){
	// printf("[%s]\n", pt[i]);
  // }
// }

void fun(char** pt){
  *pt = NULL;
}

void myfun(person* pt){
  strcpy(pt -> name, "Andrew Brown");
  pt -> age = 31;
}

void to_string(char* restrict_str, size_t size, const char* restrict_format, ...){
  snprintf(restrict_str, size, restrict_format);
}


Vector readFileToVector(Vector* vector, char* fname, int fixedLen){
	int len = 0;
	char** pt = readFileToBuffer(fname, fixedLen, &len);
	
	for(int i = 0; i < len; i++){
	  splitStrXX(vector, pt[i], " ");
	}
	
	for(int i = 0; i < len; i++){
	  free(pt[i]);
	}
	free(pt);
}


void test3(){
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
  {
	fw("Vector 1");
	Vector vector;
	vector_init(&vector);
	t_int(vector.count, 0, "test count");
	t_int(vector.limit, 4, "test limit");
	vector.free(&vector);
  }
  {
	fw("Vector 2");
	Vector vector;
	vector_init(&vector);
	vector.push_back(&vector, "abcd");
	t_int(vector.count, 1, "count");
	t_int(vector.limit, 4, "limit");
	vector.free(&vector);
  }
  {
	fw("Vector 3");
	Vector vector;
	vector_init(&vector);
	 
	vector.push_back(&vector, "abcd");
	t_int(vector.count, 1, "count");
	vector.remove(&vector, 0);
	t_int(vector.count, 0, "count");
	t_int(vector.limit, 4, "limit");
	 
	vector.free(&vector);
  }
  {
	fw("Vector 4");
	Vector vector;
	vector_init(&vector);
	vector.push_back(&vector, "abcd");
	vector.push_back(&vector, "efgh");
	vector.push_back(&vector, "ijkl");
	vector.push_back(&vector, "mnop");
	t_int(vector.count, 4, "count");
	t_int(vector.limit, 4, "limit");

	vector.push_back(&vector, "qrst");
	t_int(vector.count, 5, "count");
	t_int(vector.limit, 8, "limit");
	 
	for(int i = 0; i < vector.count; i++){
	  printf("%s\n", (char*)vector.data[i]);
	}
	 
	vector.free(&vector);
  }
  {
	fw("Vector 5");
	Vector vector;
	vector_init(&vector);
	vector.push_back(&vector, "abcd");
	vector.push_back(&vector, "efgh");
	vector.push_back(&vector, "ijkl");
	vector.push_back(&vector, "mnop");
	vector.push_back(&vector, "qrst");
	vector.remove(&vector, 0);
	vector.remove(&vector, 0);
	vector.remove(&vector, 0);
	vector.remove(&vector, 0);
	vector.remove(&vector, 0);
	vector.remove(&vector, 0);
	t_int(vector.count, 0, "count");
	t_int(vector.limit, 8, "limit");
	 
	for(int i = 0; i < vector.count; i++){
	  printf("%s\n", (char*)vector.data[i]);
	}
	 
	vector.free(&vector);
  }
  {
	fw("MyStuff 1");
	MyStuff stuff;
	mystuff_init(&stuff);
  }
  {
	char *str = "120.33.44.55";
	unsigned long h = hash(str);
	printf("hash=%d\n", h);
  }
  {
	int n = 3;
	int m = pow(2, 5);
	printf("kkn=%d\n", n * m);
	printf("kkn=%d\n", n << 5);
  }
  {
	char* s = "abc";
	char arr[10];
	int len = strlen(s);
	strncpy(arr, s, len);
	printf("Need null str at the end of string arr=[%s]\n", arr);
	arr[len] = '\0';
	printf("Ok, arr=[%s]\n", arr);
  }
  
}

void test2(){
  {
	fw("node 1");
	node *pt = (node*)malloc(sizeof(node));
	pt -> key = 100;
	char* s = "abc";
	int len = strlen(s);
	strcpy(pt -> arr, s);
	print_list(pt);
	free(pt);
  }
  {
	fw("node 2");
	node *head = (node*)malloc(sizeof(node));
	head -> key = 100;
	char* s = "abc";
	int len = strlen(s);
	strcpy(head -> arr, s);
	head -> next = NULL;
	// add node
	node* next = (node*)malloc(sizeof(node));
	next -> key = 25519;
	char* s1 = "curve25519";
	int len1 = strlen(s1);
	strcpy(next -> arr, s1);
	next -> next = NULL;
	 
	head -> next = next;
	 
	node* curr = head;
	print_list(curr);
	free(head);
  }
  {
	fw("node 3");
	node *head = NULL;
	node *curr = head;
	print_list(curr);
	free_node(head);
  }
  {
	fw("node 4");
	node *head = make_node(500, "Grag Miller");
	node *curr = head;
	print_list(curr);
	free_node(head);
  }
  {
	fw("node 5");
	node *head = make_node(500, "Grag Miller");
	node *n1 = make_node(600, "Elliptic Curve");
	head = add(head, n1);
	node *curr = head;
	print_list(curr);
	free_node(head);
  }
  {
	fw("node 6");
	node *head = make_node(500, "Grag Miller");
	node *n1 = make_node(600, "Elliptic Curve");
	node *n2 = make_node(700, "Fermat Last Theorem FLT");
	head = add(head, n1);
	head = add(head, n2);
	node *curr = head;
	print_list(curr);
	free_node(head);
  }
  {
	fw("node 7");
	node *head = NULL;
	node *n1 = make_node(800, "TCP UDP");
	head = add(head, n1);
	node* curr = head;
	print_list(curr);
	free_node(head);
  }
  {
	fw("node remove_first 1");
	node *head = NULL;
	node *n1 = make_node(800, "TCP UDP");
	head = add(head, n1);
	node* new_head = remove_first(head);
	t_voidPt(new_head, NULL, "new_head is NULL");
	free_node(new_head);
  }
  {
	fw("node remove_first 2");
	node *head = NULL;
	char* s1 = "TCP UDP";
	node *n1 = make_node(800, s1);
	char* s2 = "FreeBSD";
	node *n2 = make_node(900, s2);
	head = add(head, n1);
	head = add(head, n2);
	node* new_head = remove_first(head);
	print_list(new_head);
	t_int(new_head -> key, 900, "key");
	t_charPt(new_head -> arr, s2, "arr");
	free_node(new_head);
  }
  {
	fw("node remove_last 1");
	node *head = NULL;
	char* s1 = "TCP UDP";
	node *n1 = make_node(800, s1);
	char* s2 = "FreeBSD";
	node *n2 = make_node(900, s2);
	head = add(head, n1);
	head = add(head, n2);
	node* new_head = remove_last(head);
	t_int(new_head -> key, 800, "key");
	t_charPt(new_head -> arr, s1, "arr");
  }
  {
	fw("node remove_last 1");
	node *head = NULL;
	char* s1 = "TCP UDP";
	node *n1 = make_node(800, s1);
	char* s2 = "FreeBSD";
	node *n2 = make_node(900, s2);
	head = add(head, n1);
	head = add(head, n2);
	node* new_head = remove_last(head);
	new_head       = remove_last(new_head);
	t_voidPt(new_head, NULL, "new_head");
  }
  {
	fw("node remove_last 2");
	node *head = NULL;
	char* s1 = "TCP UDP";
	node *n1 = make_node(800, s1);
	head = add(head, n1);
	node* new_head = remove_last(head);
	t_voidPt(new_head, NULL, "new_head");
  }
  {
	person* pt = (person*)malloc(sizeof(person));
	myfun(pt);
	printf("name=%s age=%d\n", pt -> name, pt -> age);

	free(pt);
  }
  {
	person* p = (person*) malloc(sizeof(person));
	strcpy(p -> name, "Andrew");
	p -> age = 10;
	 
	int height = 4;
	int width = 3;
	person** pt = (person**)malloc(sizeof(person*) * height);
	for(int i = 0; i < height; i++){
	  pt[i] = (person*)malloc(sizeof(person) * width);
	  for(int j = 0; j < width; j++){
		pt[i] = p;
	  }
	}
  }  
}

void flow_to_str(unsigned char* buf, const int size, flow* pt){
  snprintf(buf, size, "%s-%s-%u-%u-%u", pt -> source_ip, pt -> dest_ip, pt -> source_port, pt -> dest_port, pt -> protocol);
}

unsigned long hash_flow(flow* pt){
  char buf[FLOW_STR_LEN];
  flow_to_str(buf, FLOW_STR_LEN, pt);
  unsigned long h = hash(buf);
  return h;
}

void test1(){
  {
	fw("Vector 00");
	int num = 10;
	flow** arr = (flow**)malloc(sizeof(flow*) * num);
	Vector vector;
	vector_init(&vector);
	 
	flow* pt = build_flow(
						  "127.0.0.1",
						  "127.0.0.2",
						  21,
						  106,
						  6
						  );
	vector.push_back(&vector, pt);

	for(int i = 0; i < num; i++){
	  arr[i] = build_flow(
						  "127.0.0.2",
						  "127.0.0.3",
						  121,
						  1006,
						  60
						  );
	  vector.push_back(&vector, arr[i]);
	}
	for(int i = 0; i < vector.count; i++){
	  print_flow((flow*)vector.data[i]);
	  fw("Greg");
	}
	 
	for(int i = 0; i < num; i++){
	  free(arr[i]);
	}

	free(pt);
	vector.free(&vector);
  }
  {
	fw("snprintf 0");
	const int BUSIZE = 200;
	char buf[BUSIZE];
	char* s = "Souvenir";
	pp("len=%d", strlen(buf));
	snprintf(buf, BUSIZE, "%s-%d-%f", s, 400, 3.1415);
	pl("ok");
	pl(buf);
  }
  {
	fw("snprintf 1");
	const int BUSIZE = 200;
	char buf[BUSIZE];
	char* s = "Souvenir";
	pl("sizeof buf=%d", sizeof buf);
	snprintf(buf, sizeof buf, "%s-%d-%f", s, 400, 3.1415);
	pl("ok");
	pl(buf);
  }
  {
	fw("flow_to_str 1");
	flow* pt = make_flow();
	const int BUSIZE = 200;
	char buf[BUSIZE];
	flow_to_str(buf, BUSIZE, pt);
	pl(buf);
	pl("len=%d", strlen(buf));
	pl("hash=%u", hash(buf));
	pl("hash=%u", hash("abc"));
	pl("hash=%u", hash("123"));
  }
  {
	fw("flow_node 1k");
	flow* pt = make_flow();
	print_flow(pt);
	unsigned long h = hash_flow(pt);
	flow_node* fn = (flow_node*)malloc(sizeof(flow_node));
	// fn -> pt = (flow*) malloc(sizeof(flow));
	fn -> flowPt = make_flow();
	unsigned long hash = hash_flow(fn -> flowPt);
	fw("print_flow_node 0");
	print_flow_node(fn);
	pl("%u", hash);

	free(pt);
	free(fn);
  }
  
  {
	fw("test flow_node 11");
	flow* flowPt = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	print_flow(flowPt);
	free(flowPt);
  }
  {
    fw("print_flow_node");
	flow_node* fpt = (flow_node*)malloc(sizeof(flow_node));
	flow* flowPt = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	fpt -> flowPt = flowPt;
	print_flow_node(fpt);
	free(flowPt);
	free(fpt);
  }
  {
	int num = 4;
	int* pt = (int*)malloc(sizeof(int) * num);
	for(int i = 0; i < num; i++){
	  pt[i] = i; 
	}

	for(int i = 0; i < num; i++){
	  pl("%x", &pt[i]);
	  pl("%d", pt[i]);
	}
  }
  {
	fl("is_equal_flow_str 1");
	flow* flowPt1 = build_flow(
							   "127.0.0.2",
							   "127.0.0.3",
							   121,
							   1006,
							   60
							   );

	flow* flowPt2 = build_flow(
							   "127.0.0.2",
							   "127.0.0.3",
							   121,
							   1006,
							   60
							   );
	bool b = is_equal_flow_str(flowPt1, flowPt2);
    t_bool(b, true, "Same Flow");
  }
  {
	fl("is_equal_flow_str 2");
	flow* flowPt1 = build_flow(
							   "127.0.0.2",
							   "127.0.0.3",
							   121,
							   1006,
							   60
							   );

	flow* flowPt2 = build_flow(
							   "127.0.0.2",
							   "127.0.0.3",
							   122,
							   1006,
							   60
							   );
	bool b = is_equal_flow_str(flowPt1, flowPt2);
    t_bool(b, false, "Different Flow");
  }
  {
	bool b = false;
	if(!b){
	  pl("reverse bool");
	}
  }
  {
	fw("thing kk");
	struct thing_ {
	  char arr[10];
	  int n;
	} thing_;
	typedef struct thing_ thing;
	pl("thing=%d", sizeof(thing));
  }
  {
	int num = 3;
	int** arr = (int**)malloc(sizeof(int*) * num);
	int** duplicated_arr = (int**)malloc(sizeof(int*) * num);
	
	for(int i = 0; i < num; i++){
	  arr[i] = (int*)malloc(sizeof(int));
	  arr[i][0] = i;
	}

	for(int i = 0; i < num; i++){
	  pl("arr[%d][0]=%d", i, arr[i][0]);
	}
	
	// copy int** arr  => int** duplicated_arr
	for(int i = 0; i < num; i++){
	  duplicated_arr[i] = arr[i];
	}

	free(arr);

	for(int i = 0; i < num; i++){
	  pl("duplicated_arr[%d][0]=%d", i, duplicated_arr[i][0]);
	}

	for(int i = 0; i < num; i++){
	  free(duplicated_arr[i]);
	}
  }
  {
	fw("flow_node 2");
	fw("print_flow_node 333");

	int buf_len = 4;
	flow_node** flow_node_arr = (flow_node**)malloc(sizeof(flow_node*)* buf_len);

	for(int i = 0; i < buf_len; i++){
	  flow_node_arr[i] = NULL;
	}
	for(int i = 0; i < buf_len + 2; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10 + i
								);

	  unsigned long hash = hash_flow(flowPt); 
	  unsigned long key = hash % buf_len;

	  pl("Bucket is empty => key=%u", key);
	  flow_node* fnPt = (flow_node*)malloc(sizeof(flow_node));
	  fnPt -> flowPt = flowPt;
	  fnPt -> next = NULL;
	  flow_node_arr[key] = add_flow_node(flow_node_arr[key], fnPt);
	}
	fw("print_flow_node inside 44");
	for(int i = 0; i < buf_len; i++){
	  print_flow_node(flow_node_arr[i]);
	  pl("");
	}

	fw("print_flow_node_list 11");
	for(int i = 0; i < buf_len; i++){
	  pl("key=%u", i);
	  print_flow_node_list(flow_node_arr[i]);
	  pl("--");
	}
  }

  {
	fw("flow_node 3");
	int buf_len = 4;
	hash_table htable;
	hash_table_init(&htable);
	flow* flowPt = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	
	flow_node* fnPt = make_flow_node(flowPt);
	insert_hash_table(&htable, fnPt);
  }
}

void test0(){
  {
	fw("hash_table test 1");
	hash_table htable;
	hash_table_init(&htable);
	flow* flowPt = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	flow_node* fnPt = make_flow_node(flowPt);
	insert_hash_table(&htable, fnPt);
	t_int(htable.max, 2, "htable.max");
	t_int(htable.count, 1, "htable.count");
	free_hash_table(&htable);
  }
  {
	fw("hash_table test 2");
	hash_table htable;
	hash_table_init_with(&htable, 3);
	flow* flowPt = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	flow_node* fnPt = make_flow_node(flowPt);
	insert_hash_table(&htable, fnPt);
	t_int(htable.max, 3, "htable.max");
	t_int(htable.count, 1, "htable.count");
	free_hash_table(&htable);
  }
  {
	fw("hash_table test 3");
	hash_table htable;
	hash_table_init_with(&htable, 3);
	flow* flowPt0 = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	flow_node* fnPt0 = make_flow_node(flowPt0);
	
	flow* flowPt1 = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	flow_node* fnPt1 = make_flow_node(flowPt1);
	
	insert_hash_table(&htable, fnPt0);
	insert_hash_table(&htable, fnPt1);
	
	t_int(htable.max, 3, "htable.max");
	t_int(htable.count, 2, "htable.count");
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table test 4");
	hash_table htable;
	hash_table_init_with(&htable, 3);
	flow* flowPt0 = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	flow_node* fnPt0 = make_flow_node(flowPt0);
	
	flow* flowPt1 = build_flow(
							  "127.0.0.1",
							  "127.0.0.2",
							  21,
							  106,
							  10
							  );
	flow_node* fnPt1 = make_flow_node(flowPt1);
	
	insert_hash_table(&htable, fnPt0);
	insert_hash_table(&htable, fnPt1);
	
	t_int(htable.max, 3, "htable.max");
	t_int(htable.count, 2, "htable.count");
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table test 5");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	for(int i = 0; i < 4; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10 + i
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	t_int(htable.max, 2, "htable.max");
	t_int(htable.count, 4, "htable.count");

	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 6");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 10
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 4; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}

	
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, true, "hash_table_contain");
	

	free_hash_table(&htable);
  }

  {
	fw("hash_table_contain test 7");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 30
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 4; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}

	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, false, "hash_table_contain");
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 8");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 13
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 3; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	print_hash_table(&htable);
	
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, false, "hash_table_contain");
	
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 9");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 10
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 3; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	print_hash_table(&htable);
	
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, true, "hash_table_contain");
	t_int(htable.count, 3, "htable.count");
	
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 10");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 10
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 1; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	print_hash_table(&htable);
	
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, true, "hash_table_contain");
	t_int(htable.count, 1, "htable.count");
	
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 11");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 14
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 1; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	print_hash_table(&htable);
	
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, false, "hash_table_contain");
	t_int(htable.count, 1, "htable.count");
	
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 12");
	hash_table htable;
	hash_table_init_with(&htable, 2);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 10
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 3; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10 + i
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, true, "hash_table_contain");
	t_int(htable.count, 3, "htable.count");
	
	
	free_hash_table(&htable);
  }
  {
	fw("hash_table_contain test 13");
	hash_table htable;
	// hash table become a linked list
	hash_table_init_with(&htable, 1);
	flow* checkPt = build_flow(
							 "127.0.0.1",
							 "127.0.0.2",
							 21,
							 106,
							 19
							 );
	flow_node* fnPt0 = make_flow_node(checkPt);
	
	for(int i = 0; i < 5; i++){
	  flow* flowPt = build_flow(
								"127.0.0.1",
								"127.0.0.2",
								21,
								106,
								10 + i
								);
	  flow_node* fnPt = make_flow_node(flowPt);
	  insert_hash_table(&htable, fnPt);
	}
	print_hash_table(&htable);
	bool b = hash_table_contain(&htable, fnPt0);
	t_bool(b, false, "hash_table_contain");
	t_int(htable.count, 5, "htable.count");
	free_hash_table(&htable);
  }
  {
	fw("Check char, unsigned char, signed char");
	char* s0 = "abc";
	unsigned char* s1 = "abc";
	signed char* s2 = "→⇒";
    pl("s0=%s s1=%s s2=%s", s0, s1, s2);

	for(int i = 0; i < strlen(s0); i++){
	  pl("kk=%d %2x %c", s0[i], s0[i], s0[i]);
	}
	
	for(int i = 0; i < 127; i++){
	  pl("=%d 0x%x %c", i, i, i);
	}
  }
  {
	long n = random();
	long t = time(NULL);
	pl("t=%u n=%u", t, n);
  }
  {
#if 0
	struct tm {
	int	tm_sec;		/* seconds after the minute [0-60] */
	int	tm_min;		/* minutes after the hour [0-59] */
	int	tm_hour;	/* hours since midnight [0-23] */
	int	tm_mday;	/* day of the month [1-31] */
	int	tm_mon;		/* months since January [0-11] */
	int	tm_year;	/* years since 1900 */
	int	tm_wday;	/* days since Sunday [0-6] */
	int	tm_yday;	/* days since January 1 [0-365] */
	int	tm_isdst;	/* Daylight Savings Time flag */
	long	tm_gmtoff;	/* offset from UTC in seconds */
	char	*tm_zone;	/* timezone abbreviation */
    };
#endif
	
	time_t timer;
	struct tm y2k = {0};
	double seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer);  /* get current time; same as: timer = time(NULL)  */

	seconds = difftime(timer,mktime(&y2k));

	printf ("%.f seconds since January 1, 2000 in the current timezone", seconds);
	pl("tm_sec=%d", y2k.tm_sec);

	struct tm currtime = {0};
	time_t t = mktime(&currtime);
	pl("tm_sec=%d", currtime.tm_sec);
  }
  {
	time_t epoch = 0;
    printf("%jd seconds since the epoch began\n", (intmax_t)epoch);
    printf("%s", asctime(gmtime(&epoch)));
	struct tm result;
	struct tm* tpt = gmtime_r(&epoch, &result);
	pl("gmtime_r => tm_sec=%d", result.tm_sec);
	pl("gmtime_r => tm_sec=%d", tpt -> tm_sec);
  }
  {
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime );
	timeinfo = localtime ( &rawtime );
	printf( "Current local time and date: %s", asctime (timeinfo) );
	pl("tm_sec=%d  size=[%d]", timeinfo -> tm_sec, sizeof(timeinfo -> tm_sec));
	pl("tm_min=%d  size=[%d]", timeinfo -> tm_min, sizeof(timeinfo -> tm_min));
	pl("tm_hour=%d size=[%d]", timeinfo -> tm_hour,sizeof(timeinfo -> tm_hour));
	pl("tm_mday=%d size=[%d]", timeinfo -> tm_mday,sizeof(timeinfo -> tm_mday));
	pl("tm_mon=%d  size=[%d]", timeinfo -> tm_mon, sizeof(timeinfo -> tm_mon));
	pl("tm_year=%d size=[%d]", timeinfo -> tm_year,sizeof(timeinfo -> tm_year));
	pl("tm_wday=%d size=[%d]", timeinfo -> tm_wday,sizeof(timeinfo -> tm_wday));
	pl("tm_yday=%d size=[%d]", timeinfo -> tm_yday,sizeof(timeinfo -> tm_yday));
	pl("tm_isdst=%d, size=[%d]", timeinfo -> tm_isdst, sizeof(timeinfo -> tm_isdst));
	pl("tm_gmtoff=%ld size=[%d]", timeinfo -> tm_gmtoff, sizeof(timeinfo -> tm_gmtoff));
	pl("tm_zone=%s size=[%d]", timeinfo -> tm_zone,      sizeof(timeinfo -> tm_zone));
	printf("sizeof(struct tm)=%d\n", sizeof(struct tm));
  }
  {
	printf("sizeof(char*)=%d\n", sizeof(char*));
	printf("sizeof(long)=%d\n", sizeof(long));
	printf("sizeof(int)=%d\n", sizeof(int));
	printf("sizeof(struct tm)=%d\n", sizeof(struct tm));
  }
  {
    printf("c=%c\n", 100);
  }
# if 0
  {
	int c = 1;
	int** pt = (int**)malloc(sizeof(int*) * 4 * 3);
	for(int i = 0; i < 4; i++){
	  pt[i] = (int*)malloc(sizeof(int)*3);
	  for(int j = 0; j < 3; j++){
		pt[i][j] = c;
		c++;
	  }
	}
	
	int arr[4][3] = {{1, 2, 3},
					 {4, 5, 6},
					 {7, 8, 9},
					 {10, 11,12}};
	
	for(int i = 0; i < 4; i++){
	  for(int j = 0; j < 3; j++){
		pl("pt=%2d",  **(pt++));
		// pl("*(arr + %d)=%d", x, arr[i][j]);
	  }
	}

  }
#endif
  
  {
	const int ROWS = 2;
	const int COLS = 2;
	int a[ROWS][COLS] = {{ 1, 2 }, { 3, 4 }};
    int *p = *a;
    int i, j;

    for (i = 0; i < ROWS; i++) {
	  for (j = 0; j < COLS; j++){
            printf (" %2d", a[i][j]);
	  }
	  putchar ('\n');
    }

    /* using a pointer to access the values */
    for (i = 0; i < ROWS * COLS; i++){
	  printf (" %2d", *(p++));
	}
    putchar ('\n');
  }
  {
	fw("quick_sort 1");
	int num = 1;
	int* arr = (int*)malloc(sizeof(int) * num);
	arr[0] = 2;
	int lo = 0;
	int hi = num - 1;
	quick_sort(arr, lo, hi);
	for(int i = 0; i < num; i++){
	  pl("quick_sort=%d", arr[i]);
	}
	free(arr);
  }
  
  {
	fw("quick_sort 2");
	int num = 2;
	int* arr = (int*)malloc(sizeof(int) * num);
	arr[0] = 2;
	arr[1] = 1;
	int lo = 0;
	int hi = num - 1;
	quick_sort(arr, lo, hi);
	for(int i = 0; i < num; i++){
	  pl("quick_sort=%d", arr[i]);
	}
	free(arr);
  }
  {
	/**
	     x
	     2  1  2
		 .
		 
		    x
	     2  1  2
		    .
			
			   x
	     2  1  2
		       .
		 
	 */
	fw("quick_sort 2");
	int num = 3;
	int* arr = (int*)malloc(sizeof(int) * num);
	arr[0] = 2;
	arr[1] = 1;
	arr[2] = 2;
	int lo = 0;
	int hi = num - 1;
	quick_sort(arr, lo, hi);
	for(int i = 0; i < num; i++){
	  pl("quick_sort=%d", arr[i]);
	}
	
	free(arr);
  }
  {
	{
	  fw("mc 1 int");
	  int num = 10;
	  int* pt = mc(num, "int");
	  for(int i = 0; i < num; i++){
		pt[i] = i;
	  }
	
	  for(int i = 0; i < num; i++){
		pl("pt[%d]=%d", i, pt[i]);
	  }
	}
	{
	  fw("mc 2 float");
	  int num = 10;
	  float* pt = mc(num, "float");
	  for(int i = 0; i < num; i++){
		pt[i] = i;
	  }
	
	  for(int i = 0; i < num; i++){
		pl("pt[%i]=%f", i, pt[i]);
	  }
	}

	
  }
  
}

void splitStrChar_test(){
  pl("splitStrChar_test");
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
}

void readFileToBuffer_test(){
  	{
	  fw("readFileToBuffer 1");
	  char* fname = "/tmp/x";
	  int fixedLen = 100;
	  int len = 0;
	  
	  char** pt = readFileToBuffer(fname, fixedLen, &len);
	  for(int i = 0; i < len; i++){
		pp("%s", pt[i]);
	  }

	  for(int i = 0; i < len; i++){
		free(pt[i]);
	  }
	  free(pt);
	}
}

Vector fun3_test(){
  Vector vector;
  vector_init(&vector);
  vector.push_back(&vector, "Larissa");
  return vector;
}

void strsep_test(){
  {
	char* string = strdup("ab c d    e\nkk");
	char* token = NULL;
	while((token = strsep(&string, " ")) != NULL){
	  if(strlen(token) != 0){
		pl("[%s]", token);
	  }
	}
	
	free(string);
  }
  
  {
	Vector vector;
	vector_init(&vector);
	
	char* string = strdup("ab c d    e\nkk");
	char* token = NULL;
	
	while((token = strsep(&string, " ")) != NULL){
	  if(strlen(token) != 0){
		printf("[%s]\n", token);
		vector.push_back(&vector, token);
	  }
	}

	for(int i = 0; i < vector.count; i++){
	  printf("vector.data[%d]=[%s]\n", i, (char*)vector.data[i]);
	}
	
	free(string);
  }
  {
	Vector vector;
	vector_init(&vector);
	
	char* string = strdup("ab c d    e\nkk");
	char* token = NULL;
	
	while((token = strsep(&string, " ")) != NULL){
	  if(strlen(token) != 0){
		printf("[%s]\n", token);
		vector.push_back(&vector, token);
	  }
	}

	for(int i = 0; i < vector.count; i++){
	  printf("vector.data[%d]=[%s]\n", i, (char*)vector.data[i]);
	}
	
	free(string);
  }
  {
	{
	  fw("trim 1");
	  char arr[50] = " 314159 ";
	  char* pt = trim(arr);
	  t_charPt(pt, "314159", "trim 1");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
	{
	  fw("trim 2");
	  char arr[50] = " \t314159\n ";
	  char* pt = trim(arr);
	  t_charPt(pt, "314159", "trim 2");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
	{
	  fw("trim 3");
	  char arr[50] = "314159";
	  char* pt = trim(arr);
	  t_charPt(pt, "314159", "trim 3");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
	{
	  fw("trim 4");
	  char arr[50] = "\n";
	  char* pt = trim(arr);
	  t_charPt(pt, "", "trim 4");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
	{
	  fw("trim 5");
	  char arr[50] = "\n\t ";
	  char* pt = trim(arr);
	  t_charPt(pt, "", "trim 5");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
	{
	  fw("trim 7");
	  char arr[50] = "  \n ";
	  char* pt = trim(arr);
	  t_charPt(pt, "", "trim 6");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
	{
	  fw("trim 8");
	  char arr[50] = "3\n";
	  char* pt = trim(arr);
	  t_charPt(pt, "", "trim 6");
	  t_int(strlen(pt), 1, "trim 6");
	  printf("pt=[%s]\n", pt);
	  free(pt);
	}
  }
  {
	{
	  fw("fun3_test");
	  Vector vector = fun3_test();
	  for(int i = 0; i < vector.count; i++){
		printf("kk => %s\n", (char*)vector.data[i]);
	  }
	  vector.free(&vector);
	}
  }
  
  {
	fw("splitStrXX 1");
	Vector vector;
	vector_init(&vector);
	
	char* string = strdup("ab c d    e\nkk");
	char* token = NULL;
	splitStrXX(&vector, string, " ");
	
	for(int i = 0; i < vector.count; i++){
	  printf("vector.data[%d]=[%s]\n", i, (char*)vector.data[i]);
	}
	
	vector.free(&vector);
  }
  {
	Vector vector;
	vector_init(&vector);
	int fixedLen = 100;
	int len = 0;
	char* fname = "/tmp/x";
	char** pt = readFileToBuffer(fname, fixedLen, &len);
	
	for(int i = 0; i < len; i++){
	  pp("%s", pt[i]);

	  //
	  char* token = NULL;
	  splitStrXX(&vector, pt[i], " ");
	  for(int i = 0; i < vector.count; i++){
		printf("vector.data[%d]=[%s]\n", i, (char*)vector.data[i]);
	  }
	  printf("vector.count=[%d]\n", vector.count);
	  //
	}

	for(int i = 0; i < len; i++){
	  free(pt[i]);
	}
	free(pt);
	vector.free(&vector);
  }
  {
	{
	  // XXX:
	  fw("readFileToVector 1");
	  char* env = getenv("b");
	  char* pt = concat(env, "/testfile/try_test.txt");
	  char fname[100];
	  Vector vector;
	  vector_init(&vector);
	  strcpy(fname, pt);
	  free(pt);
	  
	  int fixedLen = 100;
	  readFileToVector(&vector, fname, fixedLen);

	  for(int i = 0; i < vector.count; i++){
		int len = strlen(vector.data[i]);
		char s[50];
		strcpy(s, vector.data[i]);
		// s[len] = '\0';
		printf("     vector.data[%d]=[%s]\n", i, trim(vector.data[i]));
		printf("atoi vector.data[%d]=[%d]\n", i, atoi(vector.data[i]));
	  }
	  
	  int* arr = vectorToArray_int(vector);
	  printf("vector.count=[%d]\n", vector.count);
	  printArrayint(arr, vector.count);
	  
	  vector.free(&vector);
	}
  }
  {
	  // XXX:
	  fw("readFileToVector 2");
	  char* fname = "/tmp/b";
	  Vector vector;
	  vector_init(&vector);

	  int fixedLen = 1050;
	  readFileToVector(&vector, fname, fixedLen);

	  /*
	  for(int i = 0; i < vector.count; i++){
		int len = strlen(vector.data[i]);
		char s[50];
		strcpy(s, vector.data[i]);
		// s[len] = '\0';
		printf("     vector.data[%d]=[%s]\n", i, trim(vector.data[i]));
		printf("atoi vector.data[%d]=[%d]\n", i, atoi(vector.data[i]));
	  }
	  */
	  
	  int* arr = vectorToArray_int(vector);
	  printf("vector.count=[%d]\n", vector.count);
	  // printArrayint(arr, vector.count);
	  int lo = 0;
	  int hi = vector.count - 1;
	  
	  unsigned long old = (unsigned long)time(NULL);
	  printf("time=%lu\n", (unsigned long)time(NULL));
      quick_sort(arr, lo, hi);
	  unsigned long curr = (unsigned long)time(NULL);
	  
	  unsigned long diff = curr - old;
	  fw("quick_sort");
	  printf("diff=%lu\n", diff);
	  // printArrayint(arr, vector.count);
	  
	  vector.free(&vector);
	
  }
  {
	{
	  fw("concat 0");
	  char s1[20] = "";
	  char s2[20] = "";
	  char* pt = concat(s1, s2);
	  printf("pt=>[%s]\n", pt);
	  t_charPt(pt, "", "concat 0");
	}
	{
	  fw("concat 1");
	  char s1[20] = "abc";
	  char s2[20] = "Larissa";
	  char* pt = concat(s1, s2);
	  printf("pt=>[%s]\n", pt);
	  t_charPt(pt, "abcLarissa", "concat 1");
	}
	{
	  fw("concat 2");
	  char s1[20] = "";
	  char s2[20] = "Larissa";
	  char* pt = concat(s1, s2);
	  printf("pt=>[%s]\n", pt);
	  t_charPt(pt, "Larissa", "concat 2");
	}
  }


}

void shuffle(int* pt, int len){
    long seed = time(NULL);
    for(int i = 0; i < len - 1; i++){
        long r = randomNum(seed) % (len - 1 - i);
        printf("r=%lu\n", r);
        int tmp = pt[r];
        pt[r] = pt[len - 1 - i];
        pt[len - 1 - i] = tmp;
        seed = r;
    }
}


/**
 *  Split list of string, push all strings to vector
 *
 *  TODO: Add test cases
 */
void splitStrXX(Vector* vector, char** str, const char* delimiter){
  char* token = NULL;
  
  while((token = strsep(&str, delimiter)) != NULL){
	char* tpt = trim(token);
	if(strlen(tpt) > 0){
	  vector -> push_back(vector, tpt);
	}
  }
}

void string_to_number(){
  {
	{
	  fw("string_to_number 1");
	  char str[10] = "3.14159  ";
	  printf("[%g]\n", atof(str));
	}
	{
	  fw("string_to_number 2");
	  printf("%g\n", atof("  -0.0000000123junk"));
	  printf("%g\n", atof("0.012"));
	  printf("%g\n", atof("3.14159"));
	  printf("%g\n", atof("15e16"));
	  printf("%g\n", atof("-0x1afp-2"));
	  printf("%g\n", atof("inF"));
	  printf("%g\n", atof("Nan"));
	  printf("%g\n", atof("1.0e+309"));   // UB: out of range of double
	  printf("%g\n", atof("0.0"));
	  printf("%g\n", atof("junk"));       // no co
	}
  }
}


/*
    COMPILE: gcc -I../clib try.c -o try
    COMPILE: run.sh
*/
int main () {
  
  // test3();
  // test2();
  // test1();
  // test0();
  splitStrChar_test();
  /*
  readFileToBuffer_test();
  strsep_test();
  string_to_number();
  */
  {
    long seed = 104;
    int num = 0;
    while(num < 10){
        long r = randomNum(seed);
        printf("r=%lu\n", r);
        seed = r;
        num++;
    }
  }
  {
    int len = 10;
    int* pt = (int*)malloc(sizeof(int)*len);
    for(int i = 0; i < len; i++){
        pt[i] = i;
    }
    shuffle(pt, len);
    printArrayint(pt, len);
    free(pt);
  }
  {
	int len = 4;
	int* pt = (int*)malloc(sizeof (int) * len);
	for(int i = 0; i < len; i++){
	  pt[i] = (i + 1);
	}
	printArrayint(pt, len);
	
	pt = realloc(pt, sizeof (int) * (2*len));
	
	printArrayint(pt, 2*len);
  }
  
  {
	int maxLen = 26;
	int k = maxLen;
	int len = 4;
	int n = 1;
	int* pt = NULL;
	while(0 < maxLen){

	  pt = realloc(pt, sizeof(char) * n * len);
	  
	  for(int i = (n-1)*len; i < n * len; i++){
		pt[i] = 'a' + i;
	  }
	  n++;
	  maxLen = maxLen - len;
	}
	
	for(int i = 0; i < k; i++){
	  printf("%c ", pt[i]);
	}
	free(pt);


  }
  return(0);
}
