#include <stdio.h>

long power(int n){
  long ans = 1;
  int i;
  for(i=0;i<n;i++) ans *= 2;
  return ans;
}

int main(void){
  int n;
  printf("nを入力して下さい: ");
  scanf("%d", &n);
  printf("2^%d: %ld\n", n, power(n));
  return 0;
}