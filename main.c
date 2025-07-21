#include <stdio.h>
#include <stdlib.h>
#include "include/strbuffer.h"


int main(int argc, char *argv[])
{

  strBuffer *buf = malloc(sizeof(strBuffer));

  strbuf_readline(buf, stdin);

  printf("%s", buf->string);
  printf("\nThe size is: %d", buf->strlen);

  return EXIT_SUCCESS;
}
