#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array3.h"
#include "quick.h"
#include "data.h"
#include "clock.h"
#define NMAX 1000001

int *allocateMemoryForIntData(int n) {
  // check the value of n
  int *d;
  if (n > NMAX) {
    printf("The input data size exeeds %d\n", NMAX);
    exit(2);
  } else if (n<0) {
    printf("n must be positive integer.\n");
    exit(1);
  }
  d = (int *)calloc(n, sizeof(int));
  if (d == NULL) {
    printf("Failed to allocate memoryn");
    exit(9);
  } else
    return d;
}

int main() {
  Data *a;
  int n;
  int test[10] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000};

  for(int j=0; j<10; j++){
    n = test[j];
    // printf("data length: %d\n", n);
    a = allocateMemoryForIntData(n+1);
    generateRandomData(a, n);
    startClock();
    quicksort(a, 1, n-1);
    stopClock();
    printClock();
    free(a);
    // puts("#############");
  }



  // stdin は main() で定義されている標準入力
  // n = getDataInArray(a, stdin);
  
  // printArrayQS(a, 1, n, "input data");
  
  // quicksort(a, 1, n);
  
  // printArrayQS(a, 1, n, "sorted");
  return 0;
}