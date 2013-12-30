#include <stdio.h>
#include <ctype.h>
#include <math.h>

int getch(void);
void ungetch(int);
int getfloat(double *pn);

int main(int argc, char **argv) {
  double n = 0.0;
  int result;
  result = getfloat(&n);
  printf("%d: %.16f\n", result, n);
}

int getfloat(double *pn) {
  double val, power, exponent;
  int c, sign, exponent_sign;

  while (isspace(c = getch()))
    ;

  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (val = 0.0; isdigit(c); c = getch())
    val = 10.0 * val + (c - '0');

  if (c == '.')
    c = getch();
  for (power = 1.0; isdigit(c); c = getch()) {
    val = 10.0 * val + (c - '0');
    power *= 10.0;
  }

  if (c == 'e' || c == 'E') {
    c = getch();
    exponent_sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
      c = getch();
    for (exponent = 0.0; isdigit(c); c = getch())
      exponent = 10.0 * exponent + (c - '0');
  }

  *pn = (sign * val / power) * pow(10, exponent * exponent_sign);
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
