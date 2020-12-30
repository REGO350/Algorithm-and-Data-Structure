#include <stdio.h>
#define N 100

int main( void ){
  FILE *fp;
  FILE *fp_write;
  int i=0;
  int a;
  int max,min;
  
  fp = fopen("rand10000.csv", "r"); // ファイルrand1000.csvのオープン
  fp_write = fopen("rand10000_min_max.csv", "w");

  if (fp == NULL){
    printf("\aファイル\"rand10000.csv\"をオープンできませんでした\n"); // ファイルがない場合な
  }else{
    while(fscanf( fp, "%d", &a ) == 1 && i < N){ // fopen の戻り値は読み取りに成功した項目
      if(max < a || i==0){
        max = a;
      }
      if(a < min || i==0){
        min = a;
      }
      i++;
    }
  }
  fclose(fp); // ファイルをクローズする
  printf("MAX: %d\nMIN: %d\n", max, min);
  return 0;
}