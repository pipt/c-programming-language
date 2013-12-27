#include <stdio.h>

#define MAXLINE 1000

void escape(char in[], char out[]);

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

  escape(input, output);
  printf("%s\n", output);
}

void escape(char in[], char out[]) {
  int i = 0;
  int j = 0;
  while (in[i] != '\0') {
    switch (in[i]) {
      case '\t':
        out[j++] = '\\';
        out[j++] = 't';
        break;
      case '\n':
        out[j++] = '\\';
        out[j++] = 'n';
        break;
      default:
        out[j++] = in[i];
        break;
    }
    i++;
  }
  out[j] = '\0';
}
