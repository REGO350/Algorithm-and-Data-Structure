#include <stdio.h>
#include "heap3.h"
#include "array3.h"

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
  int i, j, p, b;
  b = 1;
  p = j = k;

  for (i = 1; i <= l; i++) {
    p = (k & b)?((j-1)/2):j/2;
    if (a[p] < a[j]) {
      swap(a, p, j);
      j = p;
    } else
      break;
    b <<= 1;
  }
}

void downHeap(Data *a, int i, int k) {
  /* a: ヒープ配列
  * i: 部分木 $T_i$ の根
  * k: 配列の末尾番地（節点 i から一番離れている節点)
  */
  int left, right;

  if (i >= k)
    return;

  // i < k
  left = (2*i <= k)?2*i:i;
  right = (2*i+1 <= k)?(2*i+1):i;

  if (a[left] > a[right]) {
    if (a[i] < a[left]) {
      swap(a, i, left);
      downHeap(a, left, k);
    }
  } else {
    if (a[i] < a[right]) {
      swap(a, i, right);
      downHeap(a, right, k);
    }
  }
}


static int _max3(int a, int b, int c) {
  if(a>b&&a>c){
    return a;
  }
  if(b>a&&b>c){
    return b;
  }
  return c;
}

static int _getMaxCBT(Data *a, int n, int k) {
  int lv, rv;
  if (k > n) { // 節点kは配列の範囲を越えている
    return -1;
  } else {
    lv = _getMaxCBT(a, n, 2*k);
    rv = _getMaxCBT(a, n, 2*k+1);
  }
  return _max3(lv, a[k], rv);
}

void heapQ(Data *a, int n) {
  int i, maxv;

  for (i = 1; i <= n; i++) {
    maxv = _getMaxCBT(a, n, i);
    if (a[i] != maxv) {
      break;
    }
  }
  printf("This array is%sa heap.\n", (i==n+1)?" ":" NOT ");
}