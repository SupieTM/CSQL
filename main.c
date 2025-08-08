#include "include/strbuffer.h"
#include "include/table.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  table *tb = inittable("test.txt");

  printtable(tb);

  return EXIT_SUCCESS;
}
