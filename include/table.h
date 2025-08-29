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

// Print the current table
void printtable(table *tb);

// Looks for a certain data(such as a name or id) in a certain label.
// Then finds the label the user wants to find and retuns that data
char *retrievedata(table *tb, char *ilabel, char *idata, char *rlabel);

// Returns the whole line of data that matches the paras.
char **retrievedataline(table *tb, char *ilabel, char *idata);

// Insert a new dataline into the chart
void insertdataline(char **dataline, table *tb);

// change data for a specific section
void changedataline(table *tb, char *ilabel, char *idata, char *clabel,
                    char *newdata);
#endif
