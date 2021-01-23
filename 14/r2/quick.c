#include <stdio.h>
#include "array3.h"

int quicksort(Data *a, int l, int r) {
  int t; // データを仕分ける基準値
  int i, j;
  int mcnt=0, lcnt=0, rcnt=0;

  if (l >= r) 
    return 0;
  
  t=a[r];
  i=l-1; j=r;
  
  while (1) {
    while (a[++i]<t){
      mcnt++;
    }
    while (a[--j]>t){
      mcnt++;
    }
    if (i < j)
      swap(a, i, j);
    else
      break;
  }

  a[r]=a[i];
  a[i]=t;
  
  lcnt = quicksort(a, l, i-1);
  rcnt = quicksort(a, i+1, r);

  return mcnt+lcnt+rcnt;
}