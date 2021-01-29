// ⽂字列ポインタの値を交換
//文字列がポインタで表現できることからポインタ変数の値を入れ替えることで，文字列の交換が行える.
#include <stdio.h>

void swap_ptr(char **x, char **y){
  char *tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(void){
  char *s1 = "ABCD";
  char *s2 = "1234";

  printf("ポインタ s1 は\"%s\"を指しています．\n",s1);
  printf("ポインタ s2 は\"%s\"を指しています．\n",s2);

  swap_ptr(&s1, &s2);

  printf("ポインタ s1 は\"%s\"を指しています．\n",s1);
  printf("ポインタ s2 は\"%s\"を指しています．\n",s2);
  
  return 0;
}