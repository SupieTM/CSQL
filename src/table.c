#include "../include/table.h"
#include "../include/strbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void loadlabels_t(table *tb, FILE *file) {
  // Initalzie buffers
  strBuffer *buf = malloc(sizeof(strBuffer));
  strBuffer *nbuf = malloc(sizeof(strBuffer));

  // Initalize the labels
  tb->labels = malloc(sizeof(char *));

  // Pull in the first line from the file
  strbuf_readline(buf, file, '\n', 0);
  int index = 0;

  // Loop through each labels, realloc more memory for the labels list, then
  // insert the label into the list
  while (strbuf_readfrombuf(nbuf, buf, ',')) {
    tb->labels = realloc(tb->labels, sizeof(char *) * (index + 1));
    tb->labels[index] = malloc(nbuf->strlen);
    strcpy(tb->labels[index], nbuf->string);
    strbuf_clear(nbuf);
    index++;
  }

  tb->numlab = index--;
}

static void loaddata_t(table *tb, FILE *file) {
  strBuffer *buf = malloc(sizeof(strBuffer));
  strBuffer *nbuf = malloc(sizeof(strBuffer));

  int _numnodes = 0;

  tb->start = malloc(sizeof(node));
  node *tn = tb->start;

  while (strbuf_readline(buf, file, '\n', 0)) {
    int index = 0;
    tn->data = malloc(sizeof(char *));
    while (strbuf_readfrombuf(nbuf, buf, ',')) {
      tn->data = realloc(tn->data, sizeof(char *) * (index + 1));
      tn->data[index] = malloc(nbuf->strlen);
      strcpy(tn->data[index], nbuf->string);
      strbuf_clear(nbuf);
      index++;
    }
    _numnodes++;
    tn->next = malloc(sizeof(node));
    tn = tn->next;
    strbuf_clear(buf);
  }

  tb->numnodes = _numnodes;
}

table *inittable(char *filename) {

  // Open the table file
  FILE *file = fopen(filename, "r");

  // Initalize the labels and data
  table *tb = malloc(sizeof(table));
  tb->numlab = 0;
  loadlabels_t(tb, file);
  loaddata_t(tb, file);

  fclose(file);

  return tb;
}

void printtable(table *tb) {

  node *tempnode = tb->start;
  for (int i = 0; i < tb->numlab; i++) {
    printf("%s\t", tb->labels[i]);
  }
  printf("\n");
  for (int i = 0; i < tb->numnodes; i++) {
    for (int j = 0; j < tb->numlab; j++) {
      printf("%s\t", tempnode->data[j]);
    }
    printf("\n");
    tempnode = tempnode->next;
  }

  return;
}
