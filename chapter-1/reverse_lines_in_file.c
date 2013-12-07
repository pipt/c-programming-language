#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
void reverse(char s[]);
int stringLength(char s[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    reverse(line);
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

void reverse(char s[]) {
  int i, len;
  char c;
  len = stringLength(s);
  for (i = 0; i < len / 2; ++i) {
    c = s[(len - i) - 1];
    s[(len - i) - 1] = s[i];
    s[i] = c;
  }
}

int stringLength(char s[]) {
  int i;
  i = 0;

  while (s[i] != '\0')
    ++i;

  return i;
}
