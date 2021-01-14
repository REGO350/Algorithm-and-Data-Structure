#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "data.h"
#include "clock.h"

#define NMAX 2000000
extern void buildBST(Node *n, int key);

int main(int argc, char **argv) {
  int i, j, n, dArray[NMAX];
  int test[10] = {1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000};

  for(j=0; j<10; j++){
    Node *root;
    n = test[j];
    printf("data length: %d\n", n);
    generateRandomData(dArray, n);
    root = newNodeBST(dArray[0]);
    for (i = 1; i < n; i++) {
      buildBST(root, dArray[i]);
    }
    startClock();
    saveKeyInOrder(root, dArray);
    stopClock();
    printClock();
    deleteTree(root);
    puts("#############");
  }
}
