#include <stdio.h>
/*-- 要素数nの配列aからkeyと一致する要素を線形探索 ---*/
int search(const int a[], int n, int key){
  int i = 0;
  for(i = 0; i < n; i++)
    if(a[i] == key)
      return (i); /* 成功 */

  return (-1); /* 失敗 */
}

int main(void)
{
  int i, ky, idx;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

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