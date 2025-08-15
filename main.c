#include "include/strbuffer.h"
#include "include/table.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  table *tb = inittable("test.txt");

  printtable(tb);
  
  char** temp = retrievedataline(tb, "pet", "bob"); 

  if (temp == NULL) {
    printf("Couldn't find thingy\n");
    return EXIT_SUCCESS;

  }
  for (int i = 0; i < tb->numlab; i++) {
    printf("%s\t", temp[i]);

  }



  return EXIT_SUCCESS;
}
