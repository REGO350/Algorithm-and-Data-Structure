#include <stdio.h>

double power(double x, int n){
  double ans = 1.0;
  int i;
  for(i=0;i<n;i++) ans *= x;
  return ans;
}

double fact(int n){
  double f=1.0;
  while(n>0){
    f *= n;
    n--;
  }
  return f;
}

int main(void){
  double ans;
  int a, b, c, d, e;
  printf("a^(b^c) + d^(e!)\n");
  printf("a> "); scanf("%d", &a);
  printf("b> "); scanf("%d", &b);
  printf("c> "); scanf("%d", &c);
  printf("d> "); scanf("%d", &d);
  printf("e> "); scanf("%d", &e);
  ans = power(a, power(b,c)) + power(d, fact(e));
  printf("%d^(%d^%d) + %d^(%d!) = %lf\n", a, b, c, d, e, ans);
  return 0;
}