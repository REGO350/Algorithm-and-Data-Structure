#include <stdio.h>
#include <stdlib.h>
#define DATA_FILE "rand10000.csv"

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
  FILE *fp;
  char *data_file = DATA_FILE;
  int i;

  if((fp = fopen(data_file,"r")) == NULL){
    printf("%s can not be open\n",data_file);
  }
  head = NULL;
  while(p = gen_node(), fscanf(fp, "%d", &p->data) != EOF){
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