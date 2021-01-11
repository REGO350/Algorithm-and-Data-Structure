#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "data.h"

#define NMAX 1000000
extern void buildBST(Node *n, int key);

int main(int argc, char **argv) {
  int i, n, dArray[NMAX], sArray[NMAX];
  Node *root;

  if (argc == 2)
    n = (int)atoi(argv[1]);
  else {
    printf("usage: bstsort n\n");
    return 1;
  }

  generateRandomData(dArray, n);

  root = newNodeBST(dArray[0]);
  for (i = 1; i < n; i++) {
    buildBST(root, dArray[i]);
  }
  saveKeyInOrder(root, sArray);

  printf(" \tbefore BSTsorting\tafter BSTsorting\n");
  for (i=0; i < n; i++) {
    printf("\t%4d %10d\t%4d %10d\n", i, dArray[i], i, sArray[i]);
  }

  deleteTree(root);

  return 0;
}
