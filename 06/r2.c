#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
void search(DlinkList *dlink, int key1, int key2);

int main(void){
  DlinkList *dlink;
  int ky1, ky2, idx;

  dlink = gen_list();
  printf("探す値の範囲\n");
  printf("from> "); scanf("%d", &ky1);
  printf("to> "); scanf("%d", &ky2);
  search(dlink, ky1, ky2);
  return 0;
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

  return dlink;
}

/*--線形探索 ---*/
void search(DlinkList *dlink, int key1, int key2){
  Node *p, *tail;
  int i = 0;
  bool flag = false;

  tail = dlink->tail;
  p = tail;
  for(i = 0; p != NULL; i++, p = p->prev){
    if(key1 <= p->data && p->data <= key2){ /* 成功 */
      if(flag == false){
        flag = true; //一度発見したことを記憶
        printf("%d以上%d以下の値は", key1, key2); //初回のみ
      }
      printf("、%d", i+1); //要素の位置を出力
    }
  }
  if(flag == false){
    printf("探索に失敗しました\n"); //一度も発見せず
  }else{
    printf("番目にあります\n");
  }
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
}