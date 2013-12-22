#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXLINE 1000

long htoi(char s[]);
int starts_with_0x(char s[]);
int charval(char c);

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
  switch(c) {
    case '0':
      return 0;
      break;
    case '1':
      return 1;
      break;
    case '2':
      return 2;
      break;
    case '3':
      return 3;
      break;
    case '4':
      return 4;
      break;
    case '5':
      return 5;
      break;
    case '6':
      return 6;
      break;
    case '7':
      return 7;
      break;
    case '8':
      return 8;
      break;
    case '9':
      return 9;
      break;
    case 'a':
    case 'A':
      return 10;
      break;
    case 'b':
    case 'B':
      return 11;
      break;
    case 'c':
    case 'C':
      return 12;
      break;
    case 'd':
    case 'D':
      return 13;
      break;
    case 'e':
    case 'E':
      return 14;
      break;
    case 'f':
    case 'F':
      return 15;
      break;
  }
  return 0;
}

int starts_with_0x(char s[]) {
  return strlen(s) > 3 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X');
}
