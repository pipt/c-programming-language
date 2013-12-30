#include <stdio.h>
#include <stdlib.h>

void my_strncat(char *s, char *t, int n);

int main(int argc, char **argv) {
  char s[1000];
  s[0] = '\0';
  int n = atoi(argv[1]);
  for (int i = 2; i < argc; i++)
    my_strncat(s, argv[i], n);
  printf("%s\n", s);
}

void my_strncat(char *s, char *t, int n) {
  while(*s++)
    ;
  s--;
  while(n-- > 0 && (*s++ = *t++))
    ;
}
