#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strrindex(char *input, char *search);

int main(int argc, char **argv) {
  char input[100];
  fgets(input, sizeof(input), stdin);
  printf("%d\n", strrindex(input, argv[1]));
}

int strrindex(char *input, char *search) {
  int i, j, k;

  for (i = strlen(input) - strlen(search); i >= 0; i--) {
    for (j = i, k = 0; search[k] != '\0' && input[j] == search[k]; j++, k++)
      ;
    if (k > 0 && search[k] == '\0')
      return i;
  }
  return -1;
}
