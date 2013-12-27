#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

const char DIGITS[] = "0123456789abcdefghijklmnopqrstuvwxyz";

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  int base = atoi(argv[2]);
  char s[30];

  itob(n, s, base);
  printf("%s\n", s);
}

void itob(int n, char s[], int base) {
  int i, digit, sign;
  sign = n;

  i = 0;
  do {
    digit = n % base;
    if (digit < 0)
      digit = -digit;
    s[i++] = DIGITS[digit];
  } while ((n /= base) != 0);
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
