#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

#define NMAX 100

extern int parserCBT(Node **nL);
extern int searchBST(Node *n, int x);

int main() {
  int nNodes, i, x, count;
  Node * nList[NMAX];

  nNodes = parserCBT(nList);

  /* キーの入力*/
  for (i=0; i<nNodes; i++)
    nList[i]->id = atoi(nList[i]->data);
  for (i=0; i<nNodes; i++)
    printNode(nList[i]);

  freopen("/dev/tty", "r", stdin); // 標準入力をターミナルに戻す

  printf("enter a key: ");
  scanf("%d", &x);
  printf("Your key is %d\n", x);

  count = searchBST(nList[0], x);
  printf("calculation counts: %d\n", count);

  return 0;
}