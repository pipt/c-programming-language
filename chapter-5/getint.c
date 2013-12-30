#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

int main() {
  int n = 0;
  int result;
  result = getint(&n);
  printf("%d: %d\n", result, n);
}

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c))
    return 0;
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int buf = -1;

int getch(void) {
  if (buf == -1) {
    return getchar();
  } else {
    int tmp = buf;
    buf = -1;
    return tmp;
  }
}

void ungetch(int c) {
  if (c == EOF)
    printf("ungetch: can't push back EOF\n");
  else if (buf != -1)
    printf("ungetch: already storing a character\n");
  else
    buf = c;
}
