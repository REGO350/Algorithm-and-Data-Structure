#include <stdio.h>
#include "array3.h"
#include "quick.h"
#define NMAX 1000

int main() {
  Data a[NMAX];
  int n, count;

  // stdin は main() で定義されている標準入力
  n = getDataInArray(a, stdin);
  
  printArrayQS(a, 1, n-1, "input data");
  
  count = quicksort(a, 1, n-1);
  
  printArrayQS(a, 1, n, "sorted");
  printf("Calculation count: %d\n", count);
  return 0;
}