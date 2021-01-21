#include <stdio.h>
#include "array3.h"
#include "quick.h"
#define NMAX 1000

int main() {
  Data a[NMAX];
  int n;

  // stdin は main() で定義されている標準入力
  n = getDataInArray(a, stdin);
  
  printArrayQS(a, 1, n, "input data");
  
  quicksort(a, 1, n);
  
  printArrayQS(a, 1, n, "sorted");
  return 0;
}