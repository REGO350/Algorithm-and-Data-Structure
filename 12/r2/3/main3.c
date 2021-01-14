#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "clock.h"

#define NMAX 2000000
extern void merge_sort(int *a, int l, int r);

int main(int argc, char **argv) {

  int i, n, dArray[NMAX];
  int test[10] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000};

  for(i=0; i<10; i++){
    n = test[i];
    printf("data length: %d\n", n);
    generateRandomData(dArray, n);
    startClock();
    merge_sort(dArray, 0, n-1);
    stopClock();
    printClock();
    puts("#############");
  }
  return 0;
}