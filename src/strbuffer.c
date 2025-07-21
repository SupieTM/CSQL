#include "../include/strbuffer.h"
#include <stdlib.h>
#include <stdio.h>


void strbuf_readline(strBuffer* buf, FILE* file) {
  //Initalize the buffer size and a character
  //Then alloc memory for the buffer
  int bufsize = 1;
  int index = 0;
  char c;

  buf->string = malloc(bufsize);

  while((c = getc(file)), c != '\n' && c != '\0' && c != EOF) {
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

  buf->strlen = index;
  buf->string[index] = '\0';
}

