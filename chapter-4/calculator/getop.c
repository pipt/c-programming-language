#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]) {
  int i, c;
  i = 0;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  if (c == '\n')
    return c;
  while ((c = getch()) && c != ' ' && c != '\n' && c != EOF)
    s[++i] = c;
  if (c != EOF)
    ungetch(c);
  s[i + 1] = '\0';

  if ((strlen(s) > 1 && isdigit(s[1])) || isdigit(s[0])) {
    return NUMBER;
  } else if (strlen(s) > 1) {
    return LONG_COMMAND;
  } else {
    return s[0];
  }
}
