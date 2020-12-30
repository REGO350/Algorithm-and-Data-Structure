#include <stdio.h>

double mean( int a[], int n ); // double mean( int *a, int n)と書いても良い

int main( void ){
  double m;
  int a[10] = { 8, 3, 2, 4, 5, 7, 6, 9, 0, 1 }; // 要素が9個以下の場合個以下の場合
  m = mean( a+3, 4 );
  printf( "average of a = %f\n", m );
  return 0;
}

double mean( int a[], int n ){
  int i;
  double avg = 0.0;
  for( i = 0 ; i < n ; i++ ){
    avg += a[i]; // avg = avg + a[i];
  }
  avg /= n;
  return avg;
}