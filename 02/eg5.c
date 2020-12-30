// /* int型の配列を動的に確保 */
// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//   int no; /* 配列の要素数 */
//   int *p;
//   int *q;
//   printf("確保する配列の要素数：");
//   scanf("%d", &no);
//   /* int型整数no個の配列を動的に確保 */
//   p = calloc(no, sizeof(int));
//   q = (int)calloc(no, sizeof(int));
//   printf("p: %p\n", p);
//   printf("q: %p\n", q);
//   if (p == NULL)
//     puts("記憶域の確保に失敗しました。");
//   else {
//     int i;
//     for (i = 0; i < no; i++, p++){ /* 全要素に添字と同じ値を代入 */
//       *p = i;
//       printf("%d %d %p\n", i, *p, p);
//     } 
//     for(i=0; i<no; i++){
//       p--;
//     }
//     for (i = 0; i < no; i++, p++) /* 全要素の値を表示 */
//   code    printf("p[%d] = %d\n", i, *p);
//     free(p); /* 確保していた領域を解放 */
//   }
//   return 0;
// }


/* int型の配列を動的に確保 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int no; /* 配列の要素数 */
  int *p;
  printf("確保する配列の要素数：");
  scanf("%d", &no);
  /* int型整数no個の配列を動的に確保 */
  p = calloc(no, sizeof(int));
  if (p == NULL)
    puts("記憶域の確保に失敗しました。");
  else {
    int i;
    for (i = 0; i < no; i++) /* 全要素に添字と同じ値を代入 */
      p[i] = i;
    for (i = 0; i < no; i++) /* 全要素の値を表示 */
      printf("p[%d] = %d\n", i, p[i]);
    free(p); /* 確保していた領域を解放 */
  }
  return 0;
}