#include "../include/strbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strbuf_readline(strBuffer *buf, FILE *file, char delim, int leavenewline) {
  // Initalize the buffer size and a character
  // Then alloc memory for the buffer
  int bufsize = 1;
  int index = 0;
  char c;

  buf->string = malloc(bufsize);

  while ((c = getc(file)), c != '\0' && c != EOF && c != delim && c != '\n') {
    // If more space needs to be allocated
    if (index == bufsize) {
      bufsize *= 2;
      buf->string = realloc(buf->string, bufsize);
    }

    buf->string[index++] = c;
  }
  if (bufsize != index + 1) {
    buf->string = realloc(buf->string, index + 1);
  }

  // Some functions need the new line character in order for their loops to work
  // This places the new line character back into the string
  if (leavenewline && c == '\n') {
    buf->string = realloc(buf->string, index + 2);
    buf->string[index++] = '\n';
  }

  buf->strlen = index;
  buf->globindex = 0;
  buf->string[index] = '\0';
}

// Clears memory from the buffer
void strbuf_clear(strBuffer *buf) {
  free(buf->string);
  buf->strlen = 0;
}

void strbuf_movegIndex(strBuffer *buf, char inital, int offset) {}

// Copy text from one buffer and put it into another buffer;
int strbuf_readfrombuf(strBuffer *outputBuf, strBuffer *inputBuf, char delim) {

  // Initalize variables
  int start, end;
  start = inputBuf->string[inputBuf->globindex] == delim
              ? inputBuf->globindex + 1
              : inputBuf->globindex;
  end = start;

  // Check if indexes are within bounds
  if (start >= inputBuf->strlen) {
    printf("Invalid Index, quitting");
    return 0;
  }

  // Move the end pointer until it hits the delim char or the end of the string
  while (inputBuf->string[end] != delim && end < inputBuf->strlen)
    end++;

  // Malloc the mem for the inputString
  outputBuf->string = malloc(end - start + 1);

  // copy over the characters
  for (int i = start, j = 0; i <= end; i++, j++) {
    outputBuf->string[j] = inputBuf->string[i];
  }

  // Initalize other variables
  inputBuf->globindex = end;

  outputBuf->string[end - start] = '\0';
  outputBuf->strlen = end - start;
  outputBuf->globindex = 0;
  return 1;
}
