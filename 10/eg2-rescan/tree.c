#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

Node *newNode(int id, char *data){
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n->id = id;
  n->data = strcpy(malloc(strlen(data)+1), data);
  n->left = n->right = NULL;
  n->flag = 0;
  return n;
}

void printNode(Node *v) {
  printf("node: %d ", v->id);
  if (v->left != NULL)
    printf("left: %d", v->left->id);
  else
    printf("left: null");
  if (v->right != NULL)
    printf(" right: %d", v->right->id);
  else
    printf(" right: null");
  printf(" data: %s\n", v->data);
}