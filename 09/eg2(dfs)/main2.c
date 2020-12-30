#include <stdio.h>
#include "tree2.h"
#include "stack.h"

#define NMAX 100
#define SMAX 100

extern int parserCBT(Node **nList);
extern void scanDFS(Node *root);

int main(void) {
  int nNodes;

  Node *nList[NMAX]; /* Node型のポインタを格納する配列 */
  nNodes = parserCBT(nList);
  initStack(SMAX);
  scanDFS(nList[0]);

  return 0;
}