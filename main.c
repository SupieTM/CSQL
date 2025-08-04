#include "include/strbuffer.h"
#include "include/table.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  table *tb = inittable("test.txt");

  for (int i = 0; i < 4; i++) {
    printf("%s\n", tb->labels[i]);
  }

  return EXIT_SUCCESS;
}
