#include <stdio.h>
#include "tree.h"

int parserCBT(Node **nList) {
  char data[128], line[128];
  int nNodes=0, i, n1, n2;

  while (fgets(line, sizeof(line), stdin)) {
    switch(line[0]) {
      case 'N':
        sscanf(&line[1], "%d %s", &i, data);
        nList[i] = newNode(i, data);
        ++nNodes;
        break;
      case 'L':
        sscanf(&line[1], "%d %d", &n1, &n2);
        nList[n1]->left = nList[n2];
        break;
      case 'R':
        sscanf(&line[1], "%d %d", &n1, &n2);
        nList[n1]->right = nList[n2];
        break;
    }
  }
  return nNodes;
}