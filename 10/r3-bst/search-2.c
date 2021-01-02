#include <stdio.h> // NULL is defined in NULL
#include "tree.h"

int count = 0;

int searchBST(Node *n, int x) {
  count++;
  if (n == NULL) {
    printf("unsuccessful search: not found the key\n");
    return count;
  }
  if (x == n->id) {
    printf("successful search: found the key at node %d\n", n->id);
    return count;
  } else {
    if (x < n->id)
      count = searchBST(n->left, x);
    else // x > p->data
      count = searchBST(n->right, x);
  }
  return count;
}