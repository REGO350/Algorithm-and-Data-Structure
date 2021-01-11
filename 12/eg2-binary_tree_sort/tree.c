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

Node *newNodeBST(int key){
  Node *n;
  n = (Node *)malloc(sizeof(Node));
  n->id = key;
  n->left = n->right = NULL;
  n->data = NULL;
  return n;
}

void printNodeBST(Node *v) {
  printf("node: %d ", v->id);
  if (v->left != NULL)
    printf("left: %d", v->left->id);
  else
    printf("left: null");
  if (v->right != NULL)
    printf(" right: %d", v->right->id);
  else
    printf(" right: null");
  printf(" key: %d\n", v->id);
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

void printTree(Node *n) {
  if (n != NULL) { // DFS走査においてpreOrder(行きがけ)処理を行う
    printNodeBST(n);
    printTree(n->left);
    printTree(n->right);
  }
}

void deleteTree(Node *n) {
  if (n != NULL) {
    // (ここに再帰呼び出しが必要かもしれない)
    if (n->data != NULL)
      free(n->data);
    // (ここに再帰呼び出しが必要かもしれない)
    free(n);
    // (ここに再帰呼び出しが必要かもしれない)
  }
}

static int idx = 0;

void saveKeyInOrder(Node *n, int *d) {
  if (n != NULL) { // DFS走査においてinOrder(通りがけ)処理を行う
    saveKeyInOrder(n->left, d);
    d[idx++] = n->id;
    saveKeyInOrder(n->right, d);
  }n