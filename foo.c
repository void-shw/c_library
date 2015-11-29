//
// gcc -Wall -fPIC -c foo.c
//
// ar rcs libfoo.a foo.o
//
// gcc -Wall -fPIC --shared -o libfoo.so.1.0 foo.o
//
#include <stdio.h>

int library_function(const char *name) {
  printf("\nHello from library! \t%s ", name);
  return 0;
}
