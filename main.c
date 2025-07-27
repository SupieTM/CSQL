#include <stdio.h>
#include <stdlib.h>
#include "include/table.h"


int main(int argc, char *argv[])
{

  table* tb = inittable("test.txt");
  printf("num %d\n", tb->numlab);
  for (int i = 0; i < tb->numlab; i++) {
    printf("%s\t", tb->labels[i]);

  }

  return EXIT_SUCCESS;
}
