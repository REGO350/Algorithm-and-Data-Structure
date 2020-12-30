#include <stdio.h>

int main(void){
  int i, n;
  int p = 1;
  unsigned long counter = 0; 

  for (n = 2; n <= 1000; n++) {
    p = 1;
    for (i = 2; i < n; i++) {
      counter++;
      if (n % i == 0) 
        p = 0;
    }
    if (p == 1) 
      printf("%d\n", n);
  }
  printf("除算を行った回数：%lu\n", counter);
  return 0;
}