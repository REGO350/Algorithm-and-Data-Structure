// ⽂字の計算
#include <stdio.h>

int main(void){
  char c = 'A';
  for(c=65; c<=90; c+=2)
    printf("%c\n",c);
  return 0;
}