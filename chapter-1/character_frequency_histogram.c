#include <stdio.h>

#define MAX_CHAR_VALUE 255

int main() {
  int i, j, c;
  int characterFrequency[MAX_CHAR_VALUE];

  for (i = 0; i < MAX_CHAR_VALUE; ++i)
    characterFrequency[i] = 0;

  while ((c = getchar()) != EOF)
    ++characterFrequency[c];

  for (i = ' '; i <= '~'; ++i) {
    printf("%c: ", i);
    for (j = 0; j < characterFrequency[i]; ++j)
      putchar('#');
    putchar('\n');
  }
}
