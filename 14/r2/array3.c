#include <stdio.h>
#include <string.h>
#include "array3.h"

// データの読み込み
int getDataInArray(Data *a, FILE *f) {
  char line[256], *s;
  int n = 1;

  a[0] = 0; // a[0] is a sentinel.
  while (fgets(line, sizeof(line), f)) {
      s = strtok(line, " ");
      sscanf(s, "%d", &a[n++]); // start at n=0
      while ((s=strtok(NULL, " "))) {
        sscanf(s, "%d", &a[n++]);
      }
    }
    return n;
  }

void swap(Data *a, int i, int j) {
  Data t;

  t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void printArrayQS(Data *a, int l, int r, char *msg) {
  int i;

  printf("%s\n", msg);
  for (i=l; i<=r; i++) {
    printf("a[%1d]=%2d ",i, a[i]);
  }
  printf("\n");
}