#include <stdio.h>
#include <limits.h>

#define MAXLINE 1000

void expand(char *input, char *output);

int main(int argc, char **argv) {
  char *input = argv[1];
  char output[MAXLINE];

  expand(input, output);

  printf("%s\n", output);
}

void expand(char *input, char *output) {
  int c, i, j;
  i = j = 0;
  while ((c = input[i]) != '\0') {
    if (c == '-' && i > 0 && input[i + 1] != '\0') {
      int pre = input[i - 1];
      int post = input[i + 1];
      if (pre < post) {
        for (int x = pre + 1; x < post; x++) {
          output[j++] = x;
        }
      } else {
        for (int x = pre - 1; x > post; x--) {
          output[j++] = x;
        }
      }
      i++;
    } else {
      output[j++] = input[i++];
    }
  }
  output[j] = '\0';
}
