#include <stdio.h> // NULL is defined in NULL
#include "tree.h"

void searchBST(Node *n, int x) {
  if (n == NULL) {
    printf("unsuccessful search: not found the key\n");
    return;
  }
  if (x == n->id) {
    printf("successful search: found the key at node %d\n", n->id);
    return;
  } else {
    if (x < n->id)
      searchBST(n->left, x);
    else // x > p->data
      searchBST(n->right, x);
  }
}