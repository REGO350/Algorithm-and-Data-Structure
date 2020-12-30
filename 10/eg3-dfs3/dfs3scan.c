#include <stdio.h> // NULL is defined in <stdio.h>.
#include "tree.h"

/* 行きがけ走査 */
void preRScan(Node *n) {
  if (n != NULL) {
    printNode(n);
    preRScan(n->left);
    preRScan(n->right);
  }
}
/* 通りがけ走査 */
void inRScan(Node *n) {
  if (n != NULL) {
    inRScan(n->left);
    printNode(n);
    inRScan(n->right);
  }
}
/* 戻りがけ走査 */
void postRScan(Node *n) {
  if (n != NULL) {
    postRScan(n->left);
    postRScan(n->right);
    printNode(n);
  }
}