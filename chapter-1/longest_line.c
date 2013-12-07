#include <stdio.h>
#define MAXLINE 32

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = getLine(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0) {
    printf("Longest line length: %d\n", max);
    if (max > MAXLINE)
      printf("Longest line, truncated to %d characters:\n", MAXLINE);
    else
      printf("Longest line:\n");
    printf("%s\n", longest);
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

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
