#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void inc(int *w) {
  *w = *w + 1; 
}

int main() {
  int *x = malloc(sizeof(int));
  *x = 123;
  int *y;
  y = x;
  inc(y);
  printf("%d,%d\n", *x, *y);
  free(x);
  return EXIT_SUCCESS;
}
