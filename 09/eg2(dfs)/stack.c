#include <stdio.h>
#include <stdlib.h>

static char **S; // a stack of node pointers
static int indexS; // the number of elements in the stack
static int maxsize; // max. size of stack

/* スタックの初期化 */
void initStack(int size) {
  indexS=0;
  maxsize = size;
  S = (char **)malloc(maxsize*sizeof(char *));
}

/* ポップ関数　*/
char *popStack(void) {
  if (--indexS<0) {
  printf("STACK: empty.\n");
  exit(1);
  } else
  return S[indexS];
}

/* プッシュ関数 */
void pushStack(char *p) {
  if (indexS<maxsize-1)
    S[indexS++]=p;
  else {
    printf("STACK: overflow.\n");
    exit(1);
  }
}
/* スタックが空なら~0を，そうでなければ0を返す関数 */
int emptyStackQ(void) {
  if (indexS == 0)
    return ~0;
  else
    return 0;
}