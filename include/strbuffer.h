#ifndef _STRBUFFER
#define _STRBUFFER

#include <stdio.h>


typedef struct strBuffer {
  int strlen;
  int globindex;
  char* string;
} strBuffer;


//strbuf_readline function,
//Workes similarly to the getline function in cpp, requires a delim character to stop.
//However, it will stop reading automatically if it encounters a /0 or EOF character
void strbuf_readline(strBuffer* buf, FILE* file, char delim, int leavenewline);

//Resets the buffer
void strbuf_clear(strBuffer* buf);

#endif
