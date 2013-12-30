#include <stdio.h>

void my_strcat(char *s, char *t);

int main(int argc, char **argv) {
  char s[1000];
  s[0] = '\0';
  for (int i = 0; i < argc - 1; i++)
    my_strcat(s, argv[i + 1]);
  printf("%s\n", s);
}

void my_strcat(char *s, char *t) {
  while(*s++)
    ;
  s--;
  while((*s++ = *t++))
    ;
}
