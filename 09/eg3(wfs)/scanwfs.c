#include <stdio.h>
#include "tree.h"
#include "queue.h"

void scanWFS(Node * root) {
  Node *v;

  v = root;
  enQueue((char *)v);

  while (!emptyQueueQ()) {
    v = (Node *)deQueue();
    printNode(v);
    if (v->left != NULL)
      enQueue((char *)v->left);
    if (v->right != NULL)
      enQueue((char *)v->right);
  }
}