#include <stdio.h>
#include <string.h>

void squeeze(char input[], char to_remove[]);
void squeeze_char(char input[], int c);

int main(int argc, char **argv) {
  char *input = argv[1];
  char *to_remove = argv[2];

  squeeze(input, to_remove);
  printf("%s\n", input);
}

void squeeze(char input[], char to_remove[]) {
  int len = strlen(to_remove);
  for (int i = 0; i < len; i++)
    squeeze_char(input, to_remove[i]);
}

void squeeze_char(char s[], int c) {
  int i, j;

  for (i = j = 0; s[i] != '\0'; i++)
    if (s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}
