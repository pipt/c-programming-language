#include <stdio.h>
#include <string.h>

int my_strend(char *s, char *t);

int main(int argc, char **argv) {
  printf("%d\n", my_strend(argv[1], argv[2]));
}

int my_strend(char *s, char *t) {
  int slen = strlen(s);
  int tlen = strlen(t);
  for (s = s + slen - tlen; s < s + tlen - 1 && *s; s++, t++)
    if (*s != *t)
      return 0;
  return 1;
}

