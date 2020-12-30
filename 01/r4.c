#include <stdio.h>

double choose(int n, int k){
  double upper=1.0, lower=1.0, ans;
  int i,j=1;
  for(i=n;j<=k;i--,j++){
    upper*=i;
  }
  for(i=k;i>0;i--){
    lower*=i;
  }
  ans = upper/lower;
  return ans;
}

double sum(double *ptr, int N){
  int i=0;
  double sum=0.0;
  for(i=0;i<N;i++,ptr++){
    sum += *ptr;
  }
  return sum;
}

double power(int n){
  double ans = 1.0;
  int i;
  for(i=0;i<n;i++) ans *= 2;
  return ans;
}

int main(void){
  int n, k;
  double right=0.0, left;
  printf("Check for Σ[k=0,n] nCk = 2^n\n");
  printf("n> "); scanf("%d", &n);
  double nCk[n+1];
  for(k=0;k<n+1;k++){
    nCk[k] = choose(n,k);
  }
  right = sum(nCk, n+1);
  left = power(n);
  printf("Σ[k=0,n] nCk = %lf\n", right);
  printf("2^n = %lf\n", left);
  return 0;
}