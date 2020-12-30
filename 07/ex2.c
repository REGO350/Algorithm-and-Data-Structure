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

Node *gen_node(void);

/* --- 要素数nの配列aからkeyと一致する要素を２分探索 --- */
int bin_search(const int a[], int n, int key)
{
 int left = 0; /* 探索範囲先頭の添字 */
 int right = n - 1; /* 〃 末尾の添字 */
 int center; /* 〃 中央の添字 */

  do{
    center = left + (right - left) / 2;
    if(a[center] == key)
      return (center); /* 探索成功 */
    else if ( a[center] < key )
      left = center + 1;
    else
      right = center - 1;
  } while(left <= right );
 return (-1); /* 探索失敗 */
}

int main(void){
  Node *p, *head, *tail;
  DlinkList *dlink;
  int i, ky, idx, nx;
  int x[7];

  printf("入力する整数の個数＞ "); scanf("%d", &nx);
  printf("%d個の整数を昇順に入力してください。\n", nx);
  head = NULL;
  tail = NULL;
  p = gen_node();
  printf("x[0] : "); scanf("%d", &p->data);
  p->next = head;
  p->prev = tail;
  head = p;
  for(i = 1; i < nx; i++){
    do{
      p = gen_node();
      printf("x[%d] : ", i); scanf("%d", &p->data);
      p->prev = p->next;
      p->next = head;
      head = p;
    } while(p->data < p->prev->data);
  }
  printf("探す値 : ");
  scanf("%d", &ky);

  printf("x[0] : ");
  scanf("%d", &x[0]);
  for(i = 1; i < nx; i++){
    do{
      printf("x[%d] : ", i);
      scanf("%d", &x[i]);
    } while (x[i] < x[i - 1]); /* 一つ前の値よりも小さければ再入力 */
  }
  printf("探す値 : ");
  scanf("%d", &ky);
  idx = bin_search(x, nx, ky); /* 配列xから値がkyである要素を２分探索 */
  if(idx == -1)
    printf("探索に失敗しました。\n");
  else
    printf("%dは%d番目にあります\n", ky, idx+1);
  return (0);
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
}