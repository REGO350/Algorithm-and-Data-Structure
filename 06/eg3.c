#include <stdio.h>

/*--- 要素数nの配列aからkeyと一致する要素を線形探索（番兵法）---*/
int search(int a[], int n, int key){
  int i = 0;
  a[n] = key; /* 番兵を追加 */
  for(;;i++){
    if(a[i] == key)
      break; /* 発見！ */
  }
  return (i == n ? -1 : i);
}

int main(void){
  int i, ky, idx;
  int x[7];
  int nx = sizeof(x) / sizeof(x[0]);

  printf("%d個の整数を入力してください\n", nx -1);
  for(i = 0; i < nx -1; i++){ /* 注意：値を読み込むのはnx個ではない */
    printf("x[%d] : ", i);
    scanf("%d", &x[i]);
  }
  printf("探す値を入力して下さい : ");
  scanf("%d", &ky);

  idx = search(x, nx-1, ky); /* 配列xから値がkyである要素を線形探索 */
  if(idx == -1)
    puts("探索に失敗しました");
  else
    printf("%dは%d番目にあります\n", ky, idx + 1);
  return (0);
}