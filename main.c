#include "include/table.h"
#include "include/strbuffer.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

  /*table *tb = inittable("test.txt");*/
  /*for (int i = 0; i < tb->numlab; i++) {*/
  /*  printf("%s\t", tb->labels[i]);*/
  /*}*/

  
  strBuffer *buf = malloc(sizeof(strBuffer));
  strBuffer *nbuf = malloc(sizeof(strBuffer));

  strbuf_readline(buf, stdin, '/', 0);
  printf("%d, %d\n", buf->globindex, nbuf->strlen);
  strbuf_readlinefrombuf(nbuf, buf, '/', 0);
  
  printf("%s", nbuf->string);
  
  return EXIT_SUCCESS;
}
