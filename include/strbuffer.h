#ifndef _STRBUFFER
#define _STRBUFFER

#include <stdio.h>


typedef struct strBuffer {
  char* string;
  int strlen;
} strBuffer;


void strbuf_readline(strBuffer* buf, FILE* file);

#endif
