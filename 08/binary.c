#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DATA_FILE "rand_bsearch.csv"

long count = 0;

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

//leftをn+1回右に動かしたアドレスを返す（centerのアドレスを求めるのに利用)
Location *locate(Node *left, int n){
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
  int r = n - 1; /* 末尾の添字 */
  int c; //中央
  int delta; //lとrの中央

  left = dlink->tail;
  right = dlink->head;
  do{
    delta = (r - l) / 2;
    // count++;
    c = l + delta;
    loc = locate(left, delta); //中央のアドレスを求める
    p = loc->center; //pをリストの中央を指す
    count++;
    if(p->data == key)
      return (c); /* 探索成功 */
    else if (p->data < key){
      left = p->prev; //中央の1つ右
      l = c + 1;
    }else{
      right = p->next; //中央の1つ左
      r = c - 1;
    }
  } while(l <= r);
  return (-1); /* 探索失敗 */
}

int main(void){
  Node *p, *head, *tail;
  DlinkList *dlink;
  FILE *fp;
  char *data_file = DATA_FILE;
  int i, ky, idx, nx = 0, x;

  if((fp = fopen(data_file,"r")) == NULL){
    printf("%s can not be open\n",data_file);
  }
  head = NULL;
  for(int j=0; j < 1000; j++){
    p = gen_node();
    fscanf(fp, "%d", &p->data);
    p->next = head;
    head = p;
    nx++; //要素数をカウント
  }
  // while(p = gen_node(), fscanf(fp, "%d", &p->data) != EOF){
  //   p->next = head;
  //   head = p;
  //   nx++; //要素数をカウント
  // }
  fclose(fp);
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
  printf("探す値を入力して下さい＞ ");
  scanf("%d", &ky);
  idx = bin_search(dlink, nx, ky); /* 配列xから値がkyである要素を２分探索 */
  if(idx == -1)
    printf("探索に失敗しました。\n");
  else
    printf("探索に成功しました.\n");
  printf("計算量：%ld\n", count);
  return 0;
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
}