#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char **argv) {
  FILE *fp1, *fp2;
  fp1 = fopen(argv[1], "r");
  fp2 = fopen(argv[2], "r");
  char s1[MAXLINE];
  char s2[MAXLINE];
  int i = 0;

  while (fgets(s1, MAXLINE - 1, fp1) != NULL && fgets(s2, MAXLINE - 1, fp2) != NULL) {
    i++;
    if (strcmp(s1, s2) != 0) {
      printf("Files differs on line %d\n%s: %s%s: %s", i, argv[1], s1, argv[2], s2);
      exit(1);
    }
  }

  return 0;
}
