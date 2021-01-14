#include <stdio.h>
#include "heap.h"

void buildHeap(Data *a, int n) {
  int l, r, k, power2=1;
  if (n > 1) {
    for (l=1; ; l++) {
      power2 <<= 1; // power2 = 2^l
      for (r = 0; r<power2; r++) {
        k = power2+r;
        upHeap(a, k, l);
        if (k==n)
          return;
      } // end of the inner loop
    } // end of the outer loop
  } // end of if
}
// 配列 a[1..k] で表される完全2分木の根から節点kへの
// パス上の節点を節点 k から根まで逆順に列挙する．
void upHeap(Data *a, int k, int l) {
  int i, j, b;

  b = 1;
  j = k;

  printf("k: %3d: ", k);
  printf(" %d", j);
  for (i = 1; i <= l; i++) {// k を二進展開したビット列を逆順で求める．
    j = (k & b)?((j-1)/2):j/2;
    b <<= 1;
    printf(" %d", j);
  }
  printf("\n");
}