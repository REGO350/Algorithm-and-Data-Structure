#include <stdio.h>
#include "tree.h"

#define NMAX 1000000
void printTreeInOrder(Node *n) {
  // int sArray[NMAX];
  // saveKeyInOrder(root, sArray);
  // for(int i=0;i<n;i++){
  //   printf("%10d\n", sArray[i]);
  // }
  if(n!=NULL){
    // printTreeInOrder(n->left);
    printTreeInOrder(n->left);
    printf("%10d\n", n->id);
    printTreeInOrder(n->right);
  }
}

// Node n を根とする木の位数を返す
int order(Node *n) {
  int oT = 0;
  if (n != NULL)
    // oT = nの左部分木の位数+nの右部分木の位数+1
    oT = order(n->left) + order(n->right) + 1;
  return oT;
}

int pathLength(Node *n) {
  int pL = 0;
  if (n != NULL)
    // pL = n の左部分木の全パス長　＋ n の右部分木の前パス長 + 二つの部分木の位数
    pL = pathLength(n->left) + pathLength(n->right) + order(n) - 1;
  return pL;
}