#include <stdio.h>

#define swap(t, x, y) { t tmp; tmp = x; x = y; y = tmp; }

int main() {
  int a = 1;
  int b = 2;
  printf("a = %d, b = %d\n", a, b);
  swap(int, a, b);
  printf("a = %d, b = %d\n", a, b);

  double x = 3.4;
  double y = 5.6;
  printf("x = %g, y = %g\n", x, y);
  swap(double, x, y);
  printf("x = %g, y = %g\n", x, y);

  char *s = "one";
  char *t = "two";
  printf("s = %s, y = %s\n", s, t);
  swap(char*, s, t);
  printf("s = %s, y = %s\n", s, t);
}
