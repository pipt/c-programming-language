#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void my_strncpy(char *s, char *t, int n);

int main(int argc, char **argv) {
  char t[1000];
  my_strncpy(argv[1], t, atoi(argv[2]));
  printf("%s\n", t);
}

void my_strncpy(char *s, char *t, int n) {
  while(n-- > 0 && (*t++ = *s++))
    ;
}

