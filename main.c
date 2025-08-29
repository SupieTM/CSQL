#include "include/strbuffer.h"
#include "include/table.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  table *tb = inittable("test.txt");

  char **dataline = malloc(sizeof(char *) * 4);

  char* temp = "1234567";

  for (int i = 0; i < 4; i++) {
    dataline[i] = malloc(8);
    dataline[i] = temp;
  }

  changedataline(tb, "name", "bob", "house", "tragic");

  return EXIT_SUCCESS;
}
