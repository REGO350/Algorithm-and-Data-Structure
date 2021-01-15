/*
 * main3T.c
 *  for measuring comp. time of heapsort
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap3.h"
#include "array3.h"
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

void heap_sort(int *a, int n) {
  int i;

  buildHeap(a, n);

  // printf("after buidling heap\n");
  //printArray(a, n);
  heapQ(a, n); // buildHeapの結果，aがヒープになったか調べる

  for (i = 0; i < n-1; i++) {
    swap(a, 1, n-i);
    downHeap(a, 1, n-1-i);
  }
}

int main(int argc, char **argv) {
  int i, j, n, *data;
  int test[10] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000};

  // if (argc != 2) {
  //   printf("Usage: heapsort n\n");
  //   return 1;
  // } else
  //   n = atoi(argv[1]);

  for(j=0; j<10; j++){
    n = test[j];
    printf("data length: %d\n", n);
    // the size of array must be n+1 for heap sorting.
    data = allocateMemoryForIntData(n+1);
    generateRandomData(data, n);
    for (i=n; i>0; i--)     // make data start at the address 1.
      data[i] = data[i-1];

    //for debugging
    //printDataArray(data, n, "input data");

    startClock();

    heap_sort(data, n);

    //for debugging
    //printDataArray(data, n, "after heapsort");
    //exit(0);

    stopClock();
    printClock();

    //for debugging
    //printArray(data, n);

    for (i = 1; i < n; i++)
      if (data[i] > data[i+1]) {
        printf("not sorted at the %dth data\n", i);
        break;
      }

    free(data);
    puts("#############");
  }

  return 0;
 }
