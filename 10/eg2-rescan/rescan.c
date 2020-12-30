#include <stdio.h> // note: NULL is defined in stdio.h.
#include "tree.h"

void recursiveScan(Node *n) {
  if (n != NULL) {
    printNode(n);
    recursiveScan(n->left);
    recursiveScan(n->right);
  }
}