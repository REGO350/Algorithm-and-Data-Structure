#include <stdio.h>
#include "array3.h"

void quicksort(Data *a, int l, int r) {
  int t; // データを仕分ける基準値
  int i, j;

  if (l >= r) 
    return;
  
  t=a[r];
  i=l-1; j=r;
  
  while (1) {
    while (a[++i]<t);
    while (a[--j]>t);
    if (i < j)
      swap(a, i, j);
    else
      break;
  }

  a[r]=a[i];
  a[i]=t;
  
  quicksort(a, l, i-1);
  quicksort(a, i+1, r);
}