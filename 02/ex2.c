#include <stdio.h>
#define N 100

int max(int a[], int n);

int main( void ){
  FILE *fp;
  int MAX;
  int i=0;
  int a[N];
  fp = fopen("rand10000.csv", "r");

  if (fp == NULL){
    printf("\aファイル\"rand10000.csv\"をオープンできませんでした\n"); // ファイルがない場合な
  }else{
    while(fscanf( fp, "%d", &a[i] ) == 1 && i < N){ // fopen の戻り値は読み取りに成功した項目
      i++;
    }
    MAX = max( a, N );
    printf( "MAX: %d\n", MAX );
    fclose(fp);
  }
  return 0;
}

int max(int a[], int n){
  int i;
  double max = a[0];
  for(i = 0; i < n; i++){
    if(max < a[i]){
      max = a[i];
    }
  }  
  return max;
}

// double mean( int a[], int n ){
//   int i;
//   double avg = 0.0;
//   for( i = 0 ; i < n ; i++ ){
//     avg += a[i]; // avg = avg + a[i];
//   }
//   avg /= n;
//   return avg;
// }