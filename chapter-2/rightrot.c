#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n);
void printBits(size_t const size, void const * const ptr);

int main(int argc, char **argv) {
  unsigned x = atoi(argv[1]);
  int n = atoi(argv[2]);

  unsigned result = rightrot(x, n);
  printBits(sizeof(result), &result);
}

unsigned rightrot(unsigned x, int n) {
  unsigned start = x << (32 - n);
  unsigned end = x >> n;
  return start | end;
}

//assumes little endian
// Taken from http://stackoverflow.com/a/3974138
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = b[i] & (1<<j);
            byte >>= j;
            printf("%u", byte);
        }
    }
    puts("");
}
