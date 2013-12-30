#include <stdio.h>
#include <stdlib.h>

int my_strncmp(char *s, char *t, int n);

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  int result;

  result = my_strncmp(argv[2], argv[3], n);
  printf("%d\n", result);
}

int my_strncmp(char *s, char *t, int n) {
  for ( ; n-- > 0 && *s == *t; s++, t++)
    if (*s == '\0' || n == 0)
      return 0;
  return *s - *t;
}
