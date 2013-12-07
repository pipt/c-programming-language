#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LENGTH 255

int main() {
  int c, previousState, state, wordLength, i, j;
  int wordLengths[MAX_WORD_LENGTH];

  state = OUT;
  previousState = OUT;
  wordLength = 0;

  for (i = 0; i < MAX_WORD_LENGTH; ++i)
    wordLengths[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (previousState != OUT) {
        ++wordLengths[wordLength];
        wordLength = 0;
      }
    } else {
      if (state == OUT) {
        state = IN;
      }
      ++wordLength;
    }
    previousState = state;
  }

  int longestWord = 0;
  for (i = 0; i < MAX_WORD_LENGTH; ++i)
    if (wordLengths[i] > 0)
      longestWord = i;

  for (i = 1; i <= longestWord; ++i) {
    printf("%3d: ", i);
    for (j = 0; j < wordLengths[i]; ++j)
      putchar('#');
    putchar('\n');
  }
}
