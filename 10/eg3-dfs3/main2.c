#include <stdio.h>
#include "tree.h"

#define NMAX 100

extern int parserCBT(Node **nL);
extern void recursiveScan(Node *n);
extern void preRScan(Node *n);
extern void inRScan(Node *n);
extern void postRScan(Node *n);

int main() {
  int nNodes;
  Node *nList[NMAX]; /* Node型のポインタを格納する配列 */

  nNodes = parserCBT(nList);
  printf("preRScan:\n"); preRScan(nList[0]);
  printf("inRScan:\n"); inRScan(nList[0]);
  printf("postRScan:\n"); postRScan(nList[0]);
  return 0;
}