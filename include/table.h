#ifndef _TABLE
#define _TABLE

#include <stdio.h>

typedef struct node {
  struct node *next;
  char **data;
} node;

typedef struct table {
  char **labels;
  int numlab;
  node *start;
  int numnodes;
} table;

// Code to initalize the whole table given a file
table *inittable(char *filename);

//Print the current table
void printtable(table *tb);

//Looks for a certain data(such as a name or id) in a certain label.
//Then finds the label the user wants to find and retuns that data
char* retrievedata(table* tb, char* ilabel, char* idata, char* rlabel);

//Returns the whole line of data that matches the paras.
char** retrievedataline(table* tb, char* ilabel, char* idata);

#endif
