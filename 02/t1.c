#include <stdio.h>

struct rectangle{
  int length;
  int width;
};

int main(void){
  struct rectangle rec1 = {5, 10};
  printf("Length: %d. Width: %d\n", rec1.length, rec1.width);
}