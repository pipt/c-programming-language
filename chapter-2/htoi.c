#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 1000

long htoi(char s[]);
int starts_with_0x(char s[]);
int charval(char c);

const char HEX_ARRAY[] = "0123456789ABCDEF";

int main() {
  int c, i;
  i = 0;
  char line[MAXLINE];

  while((c = getchar()) && c != '\n') {
    line[i++] = c;
  }
  line[i] = '\0';

  long result = htoi(line);
  printf("%ld\n", result);

  return 0;
}

long htoi(char s[]) {
  int beginning, end, i;
  long total;
  if (starts_with_0x(s)) {
    beginning = 2;
  } else {
    beginning = 0;
  }
  end = strlen(s) - 1;
  total = 0;
  for (i = end; i >= beginning; --i) {
    total += charval(s[i]) * pow(16, end - i);
  }
  return total;
}

int charval(char c) {
  for (int i = 0; i < 16; ++i)
    if (HEX_ARRAY[i] == toupper(c))
      return i;
  return 0;
}

int starts_with_0x(char s[]) {
  return strlen(s) > 3 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
}
