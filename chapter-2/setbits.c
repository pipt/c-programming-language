#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);
void printBits(size_t const size, void const * const ptr);

int main(int argc, char **argv) {
  unsigned x = atoi(argv[1]);
  int p = atoi(argv[2]);
  int n = atoi(argv[3]);
  unsigned y = atoi(argv[4]);

  unsigned result = setbits(x, p, n, y);
  printBits(sizeof(result), &result);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned y_shifted_left = y << (32 - (p + n));
  unsigned mask = ~(~0 << n) << (32 - (p + n));
  return (x & ~mask) | (y_shifted_left & mask);
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
