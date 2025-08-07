#include "include/strbuffer.h"
#include "include/table.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  table *tb = inittable("test.txt");
  node* tempnode = tb->start;

  for (int i = 0; i < 4; i++) {
    printf("%s\t", tb->labels[i]);
  }

  printf("\n");

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      printf("%s\t", tempnode->data[j]);
    }
    printf("\n");
    tempnode = tempnode->next;
  }

  return EXIT_SUCCESS;
}
