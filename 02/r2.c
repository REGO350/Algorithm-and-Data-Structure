/* int型の配列を動的に確保 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
  FILE *fp;
  int no,i; 
  int *p;
  double sq_avg=0.0, avg_sq=0.0;
  double variance = 0.0;
  fp = fopen("rand10000.csv", "r");
  
  printf("標本数＞");
  scanf("%d", &no); //標本数を入力
  p = calloc(no, sizeof(int));

  if (fp == NULL || p == NULL){
    puts("エラー");
    return 0;
  }

  while(fscanf( fp, "%d", &p[i] ) == 1 && i < no){ //配列にfpの値を格納
    i++;
  }

  /*二乗の平均と平均の二乗を求める*/
  for (i = 0; i < no; i++){ 
    sq_avg += powf(p[i], 2);
    avg_sq += p[i];
  }
  sq_avg /= no;
  avg_sq = powf((avg_sq/no), 2);
  variance = sq_avg - avg_sq; /*二乗の平均ー平均の二乗*/
  printf("標本分散: %lf\n", variance);
  free(p); /* 確保していた領域を解放 */
  fclose(fp);
  return 0;
}