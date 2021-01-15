#include <stdio.h>
#include "heap3.h"
#include "array3.h"
#define NMAX 1000

int main() {
  Data a[NMAX];
  int n, i;

  n = getDataInArray(a, stdin);

  printf("before building Heap\n");
  printArray(a, n);
  heapQ(a, n); // 読み込んだデータ配列がヒープか調べる
  buildHeap(a, n);
  printf("after buidling Heap\n");
  printArray(a, n);
  heapQ(a, n); // buildHeapの結果，aがヒープになったか調べる

  for (i = 0; i < n-1; i++) {
    swap(a, 1, n-i);
    downHeap(a, 1, n-1-i);
  }
  printf("after heap sort\n");
  printArray(a, n);

  return 0;
}