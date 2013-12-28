#include <stdio.h>

#define BUFSIZE 100

int buf = -1;

int getch(void) {
  if (buf == -1) {
    return getchar();
  } else {
    int tmp = buf;
    buf = -1;
    return tmp;
  }
}

void ungetch(int c) {
  if (c == EOF)
    printf("ungetch: can't push back EOF\n");
  else if (buf != -1)
    printf("ungetch: already storing a character\n");
  else
    buf = c;
}
