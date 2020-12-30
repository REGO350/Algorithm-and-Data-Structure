#include <stdio.h>

/*-- 要素数nの配列aからkeyと一致する要素を線形探索 ---*/
int search(const int a[], int n, int key){ /*const修飾子を利用することで変数の書換を抑止*/
  int i = 0;
  while(1){
  if (i == n)
    return (-1); /* 失敗 */
  if(a[i] == key)
    return (i); /* 成功 */
    i++;
  }
}

int main(void)
{
  int i, ky, idx;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);
  /*mallocやcallocで利用しているsizeof()と同じ
  この場合，配列x全体の大きさを配列の一要素で割っている
  つまり，配列の要素数の計算をしている
  */

  printf("%d個の整数を入力してください\n", nx);
  for(i =0; i<nx; i++){
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }
  printf("探す値を入力して下さい:");
  scanf("%d", &ky);
  idx = search(x, nx, ky);
  if(idx == -1)
    printf("探索に失敗しました\n");
  else
    printf("%dは%d番目にあります\n", ky, idx+1);
  return (0);
}