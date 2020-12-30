#include <stdio.h>

int main(void){
  int i, n;
  int prime[500]; 
  int ptr = 0; 
  int p = 1;
  unsigned long counter = 0; 
  
  prime[ptr++] = 2; 
  for (n = 3; n <= 1000; n += 1) { 
    p = 1;
    for (i = 0; prime[i]*prime[i] < n; i++) { 
      counter++;
      if(prime[i] == 0) 
        //0で割ることを防止、0の時はそもそもnは素数ではないからbreak
        p = 0;
      if (n % prime[i] == 0) 
        //合成数の場合は素数でないからbreak
        p = 0;
    }
    if (p==1){ 
      //上のfor文を最後までクリアしたnが素数
      prime[ptr++] = n; 
    }
  }
  for (i = 0; i < ptr; i++)
    printf("%d\n", prime[i]);
  printf("除算を行った回数：%lu\n", counter);
  return 0;
}