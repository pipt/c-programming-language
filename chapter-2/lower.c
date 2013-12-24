#include <stdio.h>

int lower(int c);

int main(int argc, char **argv) {
  int c = argv[1][0];

  printf("%c\n", lower(c));
}

int lower(int c) {
  return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
