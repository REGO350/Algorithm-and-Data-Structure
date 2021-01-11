#include <stdio.h>
#include "tree.h"

Node *buildBST(Node *n, int x) {
  if (n == NULL)
  return newNodeBST(x); // キー x を格納するノードを作成する．
  if (n->id > x) {
    n->left = buildBST(n->left, x);
  } else {
    n->right = buildBST(n->right, x);
  }
  return n;
}