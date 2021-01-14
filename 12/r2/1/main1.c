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
  int test[10] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000};

  for(i=0; i<10; i++){
    n = test[i];
    printf("data length: %d\n", n);
    generateRandomData(dArray, n);
    startClock();
    simplesort(dArray, n);
    stopClock();
    printClock();
    puts("#############");
  }
  // printData(dArray, n, "data after simple sorting");

  return 0;
}
