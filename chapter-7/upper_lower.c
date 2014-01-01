#include <stdio.h>
#include <ctype.h>
#include <string.h>

int strend(char *s, char *t) {
  int slen = strlen(s);
  int tlen = strlen(t);
  for (s = s + slen - tlen; s < s + tlen - 1 && *s; s++, t++)
    if (*s != *t)
      return 0;
  return 1;
}

int main(int argc, char **argv) {
  int c;

  while ((c = getchar()) != EOF)
    if (strend(argv[0], "upper") == 1)
      putchar(toupper(c));
    else
      putchar(tolower(c));
  return 0;
}
