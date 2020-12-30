#include "tree.h"

#define NMAX 100
extern int parserCBT(Node **nL);
extern void recursiveScan(Node *n);

int main() {
  int nNodes;
  Node *nList[NMAX]; /* Node型のポインタを格納する配列 */

  nNodes = parserCBT(nList);
  recursiveScan(nList[0]);

  return 0;
}