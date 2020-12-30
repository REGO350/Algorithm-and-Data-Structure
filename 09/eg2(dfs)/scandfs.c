#include <stdio.h>
#include "tree2.h"
#include "stack.h"

void scanDFS(Node * root) {
  Node *v;
  v = root;
  while (1) {
  /* print the information of v */
  if (v->flag == 0) {
    printNode(v);
    v->flag = 1; // visted node v.
  }
  if (v->left != NULL && v->left->flag == 0) {
    pushStack((char *)v);
    v = v->left;
  } else if (v->right != NULL && v->right->flag == 0) {
    pushStack((char *)v);
    v = v->right;
  } else if (emptyStackQ())
    break; // 探索終了
  else
    v = (Node *)popStack();
  }
}