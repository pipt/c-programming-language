#include <stdio.h>

int main() {
  int current, previous;

  previous = 'x';
  while ((current = getchar()) != EOF) {
    if (current != ' ') {
      if (previous == ' ')
        putchar(' ');
      putchar(current);
    }
    previous = current;
  }
}
