#include <stdio.h>
#include <stdlib.h>

static char **Q; // a stack of node pointers
static int headQ; // the number of elements in the stack
static int maxsize; // max. size of stack
static int sizeQ;

/* キューの初期化 */
void initQueue(int size) {
  headQ=sizeQ=0;
  maxsize = size;
  Q =(char **)malloc(maxsize*sizeof(char *));
}

/* キューからデータを出す */
char *deQueue(void) {
  char *a;

  if (sizeQ==0) {
    printf("QUEUE: empty.\n");
    exit(1);
  } else {
    --sizeQ;
    a = Q[headQ++];
    if (headQ == maxsize)
      headQ = 0;
    return a;
  }
}

/* キューにデータを格納する　*/
void enQueue(char *p) {
  int addr;

  if (sizeQ<maxsize) {
    addr = (headQ+sizeQ) % maxsize;
    Q[addr] = p;
    ++sizeQ;
  } else {
    printf("QUEUE: full.\n");
    exit(1);
  }
}
/* キューが空かどうかを判定する関数 */
int emptyQueueQ(void) {
  if (sizeQ == 0)
  return ~0;
  else
  return 0;
}