#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int start, int end);

int main(int argc, char **argv) {
  int num_lines_to_write;
  int num_read_lines;

  if (argc > 2) {
    printf("Usage: tail -<number of lines>");
    return 0;
  } else if (argc == 1) {
    num_lines_to_write = 10;
  } else {
    num_lines_to_write = -atoi(argv[1]);
  }

  if ((num_read_lines = readlines(lineptr, MAXLINES)) >= 0) {
    writelines(lineptr, num_read_lines - num_lines_to_write, num_read_lines);
    return 0;
  } else {
    printf("error: input too big to tail\n");
    return 1;
  }
}

#define MAXLEN 1000
int my_getline(char *, int);
char *alloc(int);

int my_getline(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = my_getline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  }
  return nlines;
}

void writelines(char *lineptr[], int start, int end) {
  while (start++ < end)
    printf("%s\n", *lineptr++);
}

#define ALLOCSIZE 100000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else {
    return 0;
  }
}
