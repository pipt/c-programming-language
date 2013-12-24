#include <stdio.h>
#include <stdlib.h>

int bitcount(unsigned x);

int main(int argc, char **argv) {
  unsigned x = atoi(argv[1]);

  printf("%d\n", bitcount(x));
}

int bitcount(unsigned x) {
  if (x == 0)
    return 0;
  int count = 1;
  while ((x &= (x - 1)) != 0)
    count++;
  return count;
}
