#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
  int data;
  struct _Node *next;
  struct _Node *prev;
} Node;

typedef struct _DlinkList{
  struct _Node *head;
  struct _Node *tail;
} DlinkList;

Node *gen_node(void);
DlinkList *gen_list(void);
int search(DlinkList *dlink, int key);

int main(void){
  DlinkList *dlink;
  int ky, idx;
  dlink = gen_list();

  printf("探す値を入力して下さい＞ "); scanf("%d", &ky);
  idx = search(dlink, ky);
  if(idx == -1)
    printf("探索に失敗しました\n");
  else
    printf("%dは%d番目にあります\n", ky, idx+1);
  return (0);
}

DlinkList *gen_list(void){
  Node *p, *head, *tail;
  DlinkList *dlink;
  int i, n;

  head = NULL;
  printf("入力する整数の個数＞ "); scanf("%d", &n);
  printf("整数を入力してください\n");

  for(i = 0;i < n; i++){
    p = gen_node();
    printf("x[%d] : ", i); scanf("%d", &p->data);
    p->next = head;
    head = p;
  }
  tail = NULL;
  p = head;
  while(p != NULL){
    p->prev = tail;
    tail = p;
    p = p->next;
  }

  dlink = (DlinkList *)malloc(sizeof(DlinkList));
  dlink->head = head;
  dlink->tail = tail;

  return dlink;
}

/*-- 要素数nの配列aからkeyと一致する要素を線形探索 ---*/
int search(DlinkList *dlink, int key){ /*const修飾子を利用することで変数の書換を抑止*/
  Node *p, *tail;
  int i = 0;

  tail = dlink->tail;
  p = tail;
  while(1){
    if(p == NULL){ /* 失敗 */
      return -1;
    }
    if(p->data == key){ /* 成功 */
      return i;
    }
    i++;
    p = p->prev;
  }
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
}