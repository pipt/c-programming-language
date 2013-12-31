#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(
    void *lineptr[],
    int left,
    int right,
    int (*comp)(void *, void *),
    int reverse
    );
int numcmp(const char *, const char *);

int main(int argc, char **argv) {
  int c, nlines;
  int numeric = 0;
  int reverse = 0;
  int case_insensitive = 0;
  int (*comp)(const char*, const char*);

  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        case 'f':
          case_insensitive = 1;
          break;
        default:
          printf("sort: unknown option %c\n", c);
          return -1;
      }

  if (numeric)
    comp = numcmp;
  else if(case_insensitive)
    comp = strcasecmp;
  else
    comp = strcmp;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    my_qsort((void **) lineptr, 0, nlines - 1,
        (int (*)(void*, void*)) comp,
        reverse);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
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

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void my_qsort(
    void *v[],
    int left,
    int right,
    int (*comp)(void *, void *),
    int reverse
    ) {
  int i, last;

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) * (reverse ? -1 : 1) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  my_qsort(v, left, last - 1, comp, reverse);
  my_qsort(v, last + 1, right, comp, reverse);
}

#define ALLOCSIZE 10000

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

int numcmp(const char *s1, const char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}
