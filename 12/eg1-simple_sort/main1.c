#include <stdio.h>
#include <stdlib.h>

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

#define NMAX 100

int main(int argc, char **argv) {
  int n;
  int d[NMAX];

  n = getDataFromCMDL(d, argc, argv);
  simplesort(d, n);
  printData(d, n, "data after simple sorting");

  return 0;
}