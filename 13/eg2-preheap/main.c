#include <stdio.h>
#include "heap.h"
#include "array.h"
#define NMAX 100

int main() {
  Data a[NMAX];
  int n;
  // stdin　は　main()　で定義されている標準入力
  n = getDataInArray(a, stdin);
  buildHeap(a, n);
  return 0;
}