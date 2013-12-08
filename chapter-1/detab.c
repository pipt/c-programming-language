#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 8

int getLine(char s[], int lim);
void detab(char s[]);
int stringLength(char s[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = getLine(line, MAXLINE)) > 0) {
    detab(line);
  }
}

void detab(char s[]) {
  int c, i;
  int actualPosition, logicalPosition;
  actualPosition = logicalPosition = 0;

  while ((c = s[actualPosition]) != '\0') {
    if (c == '\t') {
      for (i = 0; i < logicalPosition % TABSIZE; i++) {
        putchar(' ');
        ++logicalPosition;
      }
    } else {
      putchar(c);
      ++logicalPosition;
    }
    ++actualPosition;
  }
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

int stringLength(char s[]) {
  int i;
  i = 0;

  while (s[i] != '\0')
    ++i;

  return i;
}
