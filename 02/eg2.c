#include <stdio.h>

int main( void )
{
  int i;
  int a[] = {1, 2, 3, 4};
  int *p;
  p = &a[1]; 
  *(p+1) = 30; // or p[1] = 30;
  for( i = 0 ; i < 4 ; i++ ){
    printf( "a[%d] = %d, p[%d] = %d\n", i, a[i], i, p[i] );
  }
  return 0;
}