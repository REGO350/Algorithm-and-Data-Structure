#include <stdio.h>
#include "tree.h"

void printTreeInOrder(Node * n) {
  ....
}

// Node n を根とする木の位数を返す
int order(Node *n) {
  int oT = 0;
  if (n != NULL)
    // oT = nの左部分木の位数+nの右部分木の位数+1
    ...
  return oT;
}

int pathLength(Node *n) {
  int pL = 0;
  if (n != NULL)
    // pL = n の左部分木の全パス長　＋ n の右部分木の前パス長 + 二つの部分木の位数
    ...
  return pL;
}