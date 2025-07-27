#include "../include/strbuffer.h"
#include <stdlib.h>
#include <stdio.h>


void strbuf_readline(strBuffer* buf, FILE* file, char delim, int leavenewline) {
  //Initalize the buffer size and a character
  //Then alloc memory for the buffer
  int bufsize = 1;
  int index = 0;
  char c;

  buf->string = malloc(bufsize);

  while((c = getc(file)), c != '\0' && c != EOF && c != delim && c != '\n') {
    //If more space needs to be allocated
    if (index == bufsize) {
      bufsize *= 2;
      buf->string = realloc(buf->string, bufsize);
    }

    buf->string[index++] = c;
  }
  if (bufsize != index + 1) {
      buf->string = realloc(buf->string, index + 1);
  }

  if (leavenewline && c == '\n') {
      buf->string = realloc(buf->string, index + 2);
      buf->string[index++] = '\n';
  }

  buf->strlen = index;
  buf->string[index] = '\0';
}

void strbuf_clear(strBuffer* buf) {
  free(buf->string);
  buf->strlen = 0;
}

