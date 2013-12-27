#include <stdio.h>

#define MAXLINE 1000

void unescape(char in[], char out[]);

int main() {
  int i = 0;
  char input[MAXLINE];
  char output[MAXLINE];
  int c;
  while ((c = getchar()) != EOF) {
    if (i < MAXLINE - 2)
      input[i++] = c;
  }
  input[i - 1] = '\0';

  unescape(input, output);
  printf("%s\n", output);
}

void unescape(char in[], char out[]) {
  int i = 0;
  int j = 0;
  while (in[i] != '\0') {
    if (in[i] == '\\') {
      switch (in[i + 1]) {
        case 't':
          out[j++] = '\t';
          i += 2;
          break;
        case 'n':
          out[j++] = '\n';
          i += 2;
          break;
        default:
          out[j++] = in[i++];
          break;
      }
    } else {
      out[j++] = in[i++];
    }
  }
  out[j] = '\0';
}
