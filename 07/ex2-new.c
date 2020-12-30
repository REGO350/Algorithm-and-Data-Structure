#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node{
  int data;
  struct _Node *next;
  struct _Node *prev;
} Node;

typedef struct _DlinkList{
  struct _Node *head;
  struct _Node *tail;
} DlinkList;

typedef struct _Location{
  struct _Node *center;
} Location;

Node *gen_node(void);

Location *locate(Node *left, Node *right, int n){ //centerのアドレス
  Location *loc;
  Node *p, *center;
  int i;

  center = left;
  p = left;
  for(i = 0; i < n + 1; i++){
    p->next = center;
    center = p;
    p = p->prev;
  }
  loc = (Location *)malloc(sizeof(Location));
  loc->center = center;
  return loc;
}

/* --- 要素数nの配列aからkeyと一致する要素を２分探索 --- */
int bin_search(DlinkList *dlink, int n, int key)
{
  Node *p, *tail;
  Node *left, *right;
  Location *loc;
  int l = 0; /* 探索範囲先頭の添字 */
  int r = n - 1; /* 〃 末尾の添字 */
  int c, delta;

  left = dlink->tail;
  right = dlink->head;

  do{
    delta = (r - l) / 2;
    c = l + delta;
    loc = locate(left, right, delta);
    p = loc->center;
    if(p->data == key)
      return (c); /* 探索成功 */
    else if (p->data < key){
      left = p->prev;
      l = c + 1;
    }else{
      right = p->next;
      r = c - 1;
    }
  } while(l <= r);
  return (-1); /* 探索失敗 */
}

int main(void){
  Node *p, *head, *tail;
  DlinkList *dlink;
  int i, ky, idx, nx, x;

  printf("入力する整数の個数＞ "); scanf("%d", &nx);
  printf("%d個の整数を昇順に入力してください。\n", nx);
  head = NULL;
  p = gen_node();
  printf("x[0] : "); scanf("%d", &p->data);
  p->next = head;
  head = p;
  for(i = 1; i < nx; i++){
    do{
      printf("x[%d] : ", i); scanf("%d", &x);
    } while(x < p->data);
    p = gen_node();
    p->data = x;
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

  // disp_dlink_list(dlink);

  printf("探す値 : ");
  scanf("%d", &ky);
  idx = bin_search(dlink, nx, ky); /* 配列xから値がkyである要素を２分探索 */
  if(idx == -1)
    printf("探索に失敗しました。\n");
  else
    printf("%dは%d番目にあります\n", ky, idx+1);
  return 0;
}

// void disp_dlink_list(DlinkList *dlink) {
//   Node *p,*head,*tail;

//   head = dlink->head;
//   tail = dlink->tail;
//   p = tail; //pを末尾に指すようにする
//   printf("\n");
//   while(p != NULL){
//     printf("%d\n", p->data);
//     p = p->prev; //前に戻る
//   }
// }

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
}