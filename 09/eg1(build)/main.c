#include <stdio.h>
#include "tree.h"

#define NMAX 100

extern int parserCBT(Node **nList);

int main() {
  int i,nNodes;
  Node *nList[NMAX]; /* Node型のポインタを格納する配列 */

  nNodes = parserCBT(nList);
  for (i = 0; i<nNodes; i++)
    printNode(nList[i]);

  return 0;
}