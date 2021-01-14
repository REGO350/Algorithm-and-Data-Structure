#include <stdio.h>
#include <string.h>
#include "heap.h"

// データの読み込み
int getDataInArray(Data *a, FILE *f) {
  char line[512], *s;
  int n = 0;

  while (fgets(line, sizeof(line), f)) {
    s = strtok(line, " ");
    sscanf(s, "%d", &a[++n]); // start to
    while (s) {
      s = strtok(NULL, " ");
      if (s)
        sscanf(s, "%d", &a[++n]);
    }
  }
  return n;
}