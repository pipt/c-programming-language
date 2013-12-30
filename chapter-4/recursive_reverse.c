#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recursive_reverse(char *s, int len);
void reverse(char *s);
void append(char c, char s[]);

int main(int argc, char **argv) {
  char *s = argv[1];
  reverse(s);
  printf("%s\n", s);
}

void reverse(char *s) {
  recursive_reverse(s, strlen(s));
}

void recursive_reverse(char *s, int len) {
  char swap;
  if (len < 2)
    return;

  swap = s[0];
  s[0] = s[len - 1];
  s[len - 1] = swap;
  recursive_reverse(s + 1, len - 2);
}
