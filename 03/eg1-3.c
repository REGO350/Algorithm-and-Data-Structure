#include <stdio.h>
#include <math.h>

int main(void){
  int i, n, p, sum;
  int ptr = 1000;
  int prime[ptr];
  int root = (int)(sqrt((double)ptr));
  unsigned long counter = 0;

  prime[0] = 0;

  for(i = 1; i < ptr; i++){
    prime[i] = 1;
  }

  for(i = 0; i < root; i++){
    counter++;
    if(prime[i]==1){
      sum = i + 1;
      for(p = sum*2-1; p < ptr; p += sum){
        prime[p] = 0;
      }
    }
  }

  for(i = 0; i < ptr; i++){
    if(prime[i] == 1){
      printf("%d\n", i+1);
    }
  }
    printf( "èúéZÇçsÇ¡ÇΩâÒêî:%lu\n", counter);

  return 0;
}




// int main(void){
//   int i, n;
//   int prime[500]; /* 素数を格納する配列 */
//   int ptr = 0; /* 既に得られた素数の個数 */
//   float end_loop = 0.0;
//   unsigned long counter = 0; /* 除算の回数 */
//   prime[ptr++] = 2; /* ２は素数である */
//   for (n = 3; n <= 1000; n += 2) { /* 奇数のみを対象とする */
//     for (i = 1; i*i < 500; i++) { /* 既に得られた素数で割ってみる */
//       counter++;
//       // printf("%d\n", i);
//       if (n % prime[i] == 0) /* 割り切れると素数ではない */
//         break; /* それ以上の繰返しは不要 */
//     }
//     if (ptr == i) /* 最後まで割り切れなかった */
//       prime[ptr++] = n; /* 配列に登録 */
//   }
//   for (i = 0; i < ptr; i++)
//     printf("%d\n", prime[i]);
//   printf("除算を行った回数：%lu\n", counter);
//   return 0;
// }
