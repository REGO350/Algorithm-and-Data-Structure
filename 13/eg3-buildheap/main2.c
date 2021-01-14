#include <stdio.h>
#include "heap2.h"
#include "array2.h"
#define NMAX 1000

int main() {
  Data a[NMAX];
  int n;

  n = getDataInArray(a, stdin);

  printf("before building Heap\n");
  printArray(a, n);
  heapQ(a, n); // 読み込んだデータ配列がヒープか調べる
  buildHeap(a, n);
  printf("after buidling Heap\n");
  printArray(a, n);
  heapQ(a, n); // buildHeapの結果，aがヒープになったか調べる
  return 0;
}