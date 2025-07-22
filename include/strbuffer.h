#ifndef _STRBUFFER
#define _STRBUFFER

#include <stdio.h>


typedef struct strBuffer {
  char* string;
  int strlen;
} strBuffer;


//strbuf_readline function,
//Workes similarly to the getline function in cpp, requires a delim character to stop.
//However, it will stop reading automatically if it encounters a /0 or EOF character
void strbuf_readline(strBuffer* buf, FILE* file, char delim);

//Resets the buffer
void strbuf_clear(strBuffer* buf);

#endif
