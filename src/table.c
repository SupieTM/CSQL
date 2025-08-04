#include "../include/table.h"
#include "../include/strbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void loadlabels_t(table *tb, FILE *file) {
  //Initalzie buffers
  strBuffer *buf = malloc(sizeof(strBuffer));
  strBuffer *nbuf = malloc(sizeof(strBuffer));


  //Initalize the labels
  tb->labels = malloc(sizeof(char*));

  //Pull in the first line from the file
  strbuf_readline(buf, file, '\n', 0);
  int index = 0;

  //Loop through each labels, realloc more memory for the labels list, then insert the label into the list
  while(strbuf_readfrombuf(nbuf, buf, ',')) {
    tb->labels = realloc(tb->labels, sizeof(char*) * (index + 1));
    tb->labels[index] = malloc(nbuf->strlen);
    strcpy(tb->labels[index], nbuf->string);
    strbuf_clear(nbuf);
    index++;
  }
}

static void loaddata_t(table *tb, FILE *file) {
  strBuffer *buf = malloc(sizeof(strBuffer));
  int index = 0;
}

table *inittable(char *filename) {

  //Open the table file
  FILE *file = fopen(filename, "r");

  //Initalize the labels and data
  table *tb = malloc(sizeof(table));
  tb->numlab = 0;
  loadlabels_t(tb, file);
  loaddata_t(tb, file);
  fclose(file);

  return tb;
}
