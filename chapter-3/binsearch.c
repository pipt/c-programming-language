#include <stdio.h>
#include <stdlib.h>

int binsearch(int x, int v[], int n);
int binsearch_original(int x, int v[], int n);

int main(int argc, char **argv) {
  int search = atoi(argv[1]);
  int array_size = atoi(argv[2]);

  int v[array_size];
  char s[100];
  for (int i = 0; i < array_size; i++) {
    fgets(s, sizeof(s), stdin);
    v[i] = atoi(s);
  }
  printf("%d\n", binsearch(search, v, array_size));
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low < high - 1) {
    /*printf("[%d, %d, %d]\n", low, mid, high);*/
    mid = (low + high) / 2;
    if (x > v[mid])
      low = mid;
    else
      high = mid - 1;
  }
  if (x == v[mid])
    return mid;
  else if (x == v[low])
    return low;
  else if (x == v[high])
    return high;
  else
    return -1;
}

int binsearch_original(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid;
  }
  return -1;
}
