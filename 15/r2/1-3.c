// ⽂字列ポインタの値を交換
#include <stdio.h>

void swap_ptr(char **x, char **y){ //入力値として、ポインタのアドレス値、つまりポインタのポインタが入力される。
  char *tmp = *x; //ポインタtmpにポインタxの値を代入==>ポインタs1のアドレス値
  *x = *y; //ポインタxの値にポインタyの値を代入
  *y = tmp; //ポインタyの値にポインタtmp（ポインタxの値）を代入
}

int main(void){
  char *s1 = "ABCD";
  char *s2 = "1234";

  printf("ポインタ s1 は\"%s\"を指しています．\n",s1);
  printf("ポインタ s2 は\"%s\"を指しています．\n",s2);

  swap_ptr(&s1, &s2); //ポインタs1, s2のアドレスを入力

  printf("ポインタ s1 は\"%s\"を指しています．\n",s1);
  printf("ポインタ s2 は\"%s\"を指しています．\n",s2);
  
  return 0;
}