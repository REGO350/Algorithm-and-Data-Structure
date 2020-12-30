#include <stdio.h>

void hanoi(char src, char dst, char aux, int n){
if (n > 0) {
  hanoi(src, aux, dst, n-1);
  printf("Move disk %d from peg %c to peg %c.\n", n, src, dst);
  hanoi(aux, dst, src, n-1);
  }
}
int main() {
  hanoi('A', 'B', 'C', 3);
  return 0;
}