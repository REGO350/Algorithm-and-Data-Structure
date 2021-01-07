#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"

#define NMAX 1000000
extern void merge_sort(int *a, int l, int r);

int main(int argc, char **argv) {
  int i, n;
  int dArray[NMAX];

  if (argc == 2)
    n = atoi(argv[1]);
  else {
    printf("Usage: mergesort n\n");
    return 1;
  }

  generateRandomData(dArray, n);

  merge_sort(dArray, 0, n-1);

  printf(" \tafter merge sorting\n");
  for (i=0; i < n; i++) {
    printf("\t%4d %10d\n", i, dArray[i]);
  }
  return 0;
}