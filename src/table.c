#include "../include/table.h"
#include "../include/strbuffer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


table* inittable(char* filename) {
  
  FILE* file = fopen(filename, "r");
  table* tb = malloc(sizeof(table));
  tb->numlab = 0;
  loadlabels_t(tb, file);
  fclose(file);

  return tb;
}

void loadlabels_t(table* tb, FILE* file) {
  strBuffer* buf = malloc(sizeof(strBuffer));
  int index = 0;
  while ((strbuf_readline(buf, file, ','), buf->string[buf->strlen - 1] != '\n')) {
    printf("buf: %s\n", buf->string);
    strbuf_clear(buf);
  }
}

 
