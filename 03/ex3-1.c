#include<stdio.h>
#include<math.h>

int main(void){
  unsigned long a = 1;
  int f, n, count = 0;

  printf("3^n> "); scanf("%d", &n);
  for( ; n >= 0 ; n--){
    count++;
    a *= 3;
    f = a % 997;
    printf("a = %lu, f = %d, loop = %d\n", a, f, count);
  }
  return 0;
}

