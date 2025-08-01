#include "../include/table.h"
#include "../include/strbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void loadlabels_t(table *tb, FILE *file) {
  //Init value
  strBuffer *buf = malloc(sizeof(strBuffer));
  int index = 0;
  tb->labels = malloc(sizeof(char *));

  //Loop and insert labels
  while ((strbuf_readline(buf, file, ',', 1),
          buf->string[buf->strlen - 1] != '\n')) {
    tb->labels = realloc(tb->labels, sizeof(char *) * (index + 1));
    tb->labels[index] = malloc(buf->strlen);
    strcpy(tb->labels[index++], buf->string);
    strbuf_clear(buf);
  }

  //Do a final loop, but remove the new line character
  tb->labels = realloc(tb->labels, sizeof(char *) * (index + 1));
  tb->labels[index] = malloc(buf->strlen - 1);
  buf->string[buf->strlen - 1] = '\0';
  strcpy(tb->labels[index], buf->string);
  strbuf_clear(buf);
  free(buf);
  

  //set the number of labels
  tb->numlab = index + 1;
}

static void loaddata_t(table *tb, FILE *file) {
  strBuffer *buf = malloc(sizeof(strBuffer));
  int index = 0;
}


table *inittable(char *filename) {

  FILE *file = fopen(filename, "r");
  table *tb = malloc(sizeof(table));
  tb->numlab = 0;
  loadlabels_t(tb, file);
  loaddata_t(tb, file);
  fclose(file);

  return tb;
}
