#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void tidyLine(char s[], int len);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0)
    if (len > 1) {
      tidyLine(line, len);
      printf("%s", line);
    }

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

void tidyLine(char s[], int len) {
  int i;
  i = len - 2; /* Skip the \n */

  while (i-- > 0 && (s[i] == ' ' || s[i] == '\t')) {
    s[i] = '\n';
    s[i + 1] = '\0';
  }
}
