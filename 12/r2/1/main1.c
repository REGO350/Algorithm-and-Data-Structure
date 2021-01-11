#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "clock.h"

#define NMAX 1000000
extern void simplesort(int *d, int n);

int getDataFromCMDL(int *d, int argc, char **argv) {
  int i, n = argc-1;
  for (i=0; i<n; i++) {
    d[i] = atoi(argv[i+1]);
  }
  return n;
}

void printData(int *d, int n, char *msg) {
  int i;
  printf("%s\n", msg);
  for (i=0; i<n; i++)
    printf("%3d ", d[i]);
  printf("\n");
}

int main(int argc, char **argv) {
  int i, n, dArray[NMAX];
  if (argc == 2)
    n = (int)atoi(argv[1]);
  else {
    printf("usage: bstsort n\n");
    return 1;
  }

  generateRandomData(dArray, n);

  startClock();
  simplesort(dArray, n);
  stopClock();
  printClock();
  // printData(dArray, n, "data after simple sorting");

  return 0;
}
