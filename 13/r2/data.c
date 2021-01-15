#include <stdio.h>
#include <time.h>
#include "MT.h" // メルセンヌ・ツイスター法による乱数発生ルーチン

void printDataArray(int *d, int n, char *msg) {
  int i;
  printf("%s\n", msg);
  for (i=0; i<n; i++)
    printf("%d ", d[i]);
  printf("\n");
}

void generateRandomData(int *a, int n) {
  int i;
  init_genrand((unsigned)time(NULL)); //初期値設定
  for (i=0; i<n; i++)
    a[i]=(int)(genrand_int31()); //擬似乱数を生成
}