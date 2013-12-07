#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
  int c, previousState, state;

  state = OUT;
  previousState = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      if (previousState != OUT) {
        putchar('\n');
      }
    } else {
      if (state == OUT) {
        state = IN;
      }
      putchar(c);
    }
    previousState = state;
  }
}
