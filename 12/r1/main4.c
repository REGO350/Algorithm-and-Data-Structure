#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "pathlen.h"

#define NMAX 100
extern void buildBST(Node *n, int key);

int getDataFromCMDL(int *d, int argc, char **argv) {
  int i, n = argc-1;

  for (i=0; i<n; i++) {
    d[i] = atoi(argv[i+1]);
  }
  return n;
}

int main(int argc, char **argv) {
  int i, n;
  int d[NMAX];
  Node * root;

  n = getDataFromCMDL(d, argc, argv);
  // generate the BST of the input data
  root = newNodeBST(d[0]);
  for (i = 1; i < n; i++) {
    buildBST(root, d[i]);
  }

  printTreeInOrder(root, n); // 確認のため昇順にソートされたデータを出力する．

  printf("path length: %d\n", pathLength(root));

  return 0;
}