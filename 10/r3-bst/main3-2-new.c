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

  int total=0;
  for(x=10; x<=19; x++){
    count = searchBST(nList[0], x);
    total += count;
    printf("calculation counts for %d: %d\n", x, count);
  }
  printf("Total: %d\n", total);
  return 0;
}