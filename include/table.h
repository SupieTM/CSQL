#ifndef _TABLE
#define _TABLE

#include <stdio.h>

typedef struct node {
  struct node* next;
  char** data;
} node;

typedef struct table {
  char** labels;
  int numlab;
  node* start;
} table;

void loadlabels_t(table* tb, FILE* file);

table* inittable(char* filename);

#endif
