#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0)
    if (len > 80)
      printf("%s", line);

  return 0;
}

int getLine(char s[], int lim) {
  int c, i;
  i = 0;

  while ((c = getchar()) != EOF && c != '\n') {
    if (i < lim - 1)
      s[i] = c;
    ++i;
  }

  if (c == '\n') {
    if (i < lim - 1) {
      s[i++] = c;
      s[i] = '\0';
    } else {
      s[lim - 1] = '\0';
      ++i;
    }
  }

  return i;
}
