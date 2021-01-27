#include <stdio.h>
#include "array3.h"

int quicksort(Data *a, int l, int r) { //a,1,n
  int t; // データを仕分ける基準値
  int i, j;
  int mcnt=0, lcnt=0, rcnt=0;

  if (l >= r) 
    return 0;
  
  t=a[r];
  i=l-1; j=r;
  
  // puts("##########");
  while (1) {
    do{
      mcnt++;
    }while (a[++i]<t); 
    //while{}ではループ前に条件を満たすとmcnt++が実行されないため

    do{
      mcnt++;
    }while (a[--j]>t); 

    // printf("t: %d, i: %d, j: %d\n", t, i, j);
    // printf("mcnt: %d\n", mcnt);
    if (i < j){
      swap(a, i, j); puts("swap");
    }
    else
      break;
  }

  a[r]=a[i];
  a[i]=t;
  
  lcnt = quicksort(a, l, i-1); //l=1,i-1=0
  rcnt = quicksort(a, i+1, r); //i+1=2, r=2

  return mcnt+lcnt+rcnt;
}