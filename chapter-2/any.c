#include <stdio.h>
#include <limits.h>

int any(char *input, char *search);
int charpos(char *input, char search);

int main(int argc, char **argv) {
  char *input = argv[1];
  char *search = argv[2];

  int position = any(input, search);
  printf("%d\n", position);
}

int any(char *input, char *search) {
  int c;
  int i = 0;
  int minpos = INT_MAX;
  int curpos;
  while ((c = search[i]) && c != '\0') {
    curpos = charpos(input, c);
    if (curpos >= 0 && curpos < INT_MAX)
      minpos = curpos;
    i++;
  }
  if (minpos == INT_MAX)
    return -1;
  else
    return minpos;
}

int charpos(char *input, char search) {
  int c;
  int i = 0;
  while ((c = input[i]) && c != '\0')
    if (c == search)
      return i;
    else
      i++;
  return -1;
}
