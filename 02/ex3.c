/* int型の配列を動的に確保 */
#include <stdio.h>
#include <stdlib.h>

int main(void){
  FILE *fp;
  int no,i; 
  int *p;
  double avg = 0.0;
  fp = fopen("rand10000.csv", "r");
  
  printf("標本数：");
  scanf("%d", &no);
  p = calloc(no, sizeof(int));

  if (fp == NULL || p == NULL){
    puts("エラー");
    return 0;
  }

  while(fscanf( fp, "%d", &p[i] ) == 1 && i < no){ //配列にfpの値を格納
    i++;
  }

  for (i = 0; i < no; i++) /* 全要素の値を表示 */
    avg+=p[i];
  avg/=no; 
  printf("AVG: %lf\n", avg);
  free(p); /* 確保していた領域を解放 */
  fclose(fp);
  return 0;
}