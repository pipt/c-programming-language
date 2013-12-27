#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void reverse(char s[]);
void check_int(int n);

int main() {
  check_int(0);
  check_int(INT_MAX);
  check_int(INT_MIN);
}

void check_int(int n) {
  char s[30];
  itoa(n, s);
  printf("%d: %s\n", n, s);
}

void itoa(int n, char s[]) {
  int i, digit, sign;
  sign = n;

  i = 0;
  do {
    digit = n % 10;
    if (digit < 0)
      digit = -digit;
    s[i++] = digit + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
