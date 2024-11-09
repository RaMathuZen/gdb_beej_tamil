#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  size_t sz = atoi(argv[1]);
  //size_t sz = 8;
  unsigned char *p = malloc(sz), *q;
  printf("%p\n", p);
  p[sz] = 0;
  free(p);
  q = malloc(sz);
  printf("%p\n", q);
  free(p);
  return 0;
}
