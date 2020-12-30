#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

extern void searchBST(Node *n, int x);

Node *buildBST(Node *n, int key);

int main() {
  char line[512], *s;
  int key;
  Node *root;

  printf("key values entered:\n");
  root = NULL;
  while (fgets(line, 512, stdin) != NULL) {
    s = strtok(line, ",");
    sscanf(s, "%d", &key);
    printf(" %2d", key);

    root = buildBST(root, key);

    while (s != NULL) {
      // 2回目以降は第１引数はNULL
      s = strtok(NULL, ",");
      if (s != NULL) {
        sscanf(s, "%d", &key);
        printf(" %2d", key);
        root = buildBST(root, key);
      }
    }
  }
  printf("\nthe BST:\n");
  printTree(root);
  // key search
  freopen("/dev/tty", "r", stdin); // 標準入力をターミナルに戻す

  printf("enter a key: ");
  scanf("%d", &key);

  searchBST(root, key);

  deleteTree(root);

  return 0;
}