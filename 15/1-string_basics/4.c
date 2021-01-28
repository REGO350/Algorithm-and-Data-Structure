// 数字を表す⽂字列から整数への変換
#include <stdio.h>
#include <stdlib.h>

int main(void){
  char *str = "456";
  int num;

  num = atoi("123");
  printf("%d\n", num + 1);
  num = atoi(str);
  printf("%d\n", num + 1);
  
  return 0;
}