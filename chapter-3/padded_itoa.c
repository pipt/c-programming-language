#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void padded_itoa(int n, char s[], int min_width);
void reverse(char s[]);

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  int min_width = atoi(argv[2]);
  char s[30];

  padded_itoa(n, s, min_width);
  printf("%s\n", s);
}

void padded_itoa(int n, char s[], int min_width) {
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
  while (i < min_width) {
    s[i++] = ' ';
  }
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
