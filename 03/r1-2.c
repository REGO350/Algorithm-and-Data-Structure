#include <stdio.h>
#include <math.h>

int main(void){
  int n, count = 0, loop_count = 0;
  printf("2^n> "); scanf("%d", &n);
  n = pow(2,n);
  while(n > 0){
    if(n % 2 == 1)
      count++;
    n /= 2;
    loop_count++;
  }
  printf("amout of 1s: %d\n", count);
  printf("loops: %d\n", loop_count);
  return 0;
}
