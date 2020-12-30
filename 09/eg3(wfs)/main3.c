#include <stdio.h>
#include "tree.h"
#include "queue.h"

#define NMAX 100
#define QMAX 100

extern int parserCBT(Node **nList);
extern void scanWFS(Node *root);

int main(void) {
  int nNodes;
  Node *nList[NMAX]; /* Node型のポインタを格納する配列 */

  nNodes = parserCBT(nList);

  initQueue(QMAX);
  scanWFS(nList[0]);

  return 0;
}