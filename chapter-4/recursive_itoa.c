#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive_itoa(int n, char s[]);
void append(char c, char s[]);

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  char s[30];
  s[0] = '\0';

  recursive_itoa(n, s);
  printf("%s\n", s);
}

void recursive_itoa(int n, char s[]) {
  if (n < 0) {
    append('-', s);
    n = -n;
  }
  if (n / 10)
    recursive_itoa(n / 10, s);
  append(n % 10 + '0', s);
}

void append(char c, char s[]) {
  int len = strlen(s);
  s[len] = c;
  s[len + 1] = '\0';
}
