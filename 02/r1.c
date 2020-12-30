#include <stdio.h>
#define N 200

int min(int a[], int n);

int main( void ){
  FILE *fp;
  int A[N];

  fp = fopen("rand10000.csv", "r");
  if (fp == NULL){
    printf("\aファイル\"rand10000.csv\"をオープンできませんでした\n"); //エラー
    return 0;
  }

  int from, to, count;
  printf("range(0~199):\n");
  printf("from: "); scanf("%d", &from);
  printf("to: "); scanf("%d", &to);
  count = to - from + 1;

  int i=0;
  while(fscanf( fp, "%d", &A[i] ) == 1 && i < N){ //i=0~NまでA[i]にfpのi番目の値を格納
    i++;
  }

  int MIN;
  MIN = min( A + from, count ); //min関数に配列Aのfrom番目のアドレスと試験する幅countを入力
  printf( "MIN: %d\n", MIN );
  
  fclose(fp);
  return 0;
}

int min(int a[], int n){
  int i;
  int min = a[0];
  for(i = 0; i < n; i++){
    if(min > a[i])
      min = a[i];
  }  
  return min;
}