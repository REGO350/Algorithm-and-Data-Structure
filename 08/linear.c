#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DATA_FILE "rand_bsearch.csv"

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
void search(DlinkList *dlink, int key);

int main(void){
  DlinkList *dlink;
  int ky, idx;

  dlink = gen_list(); //リストの生成（ファイルを読み、head, tailの情報を返す）
  printf("探す値を入力して下さい＞ "); scanf("%d", &ky);
  search(dlink, ky);
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
  for(int j=0; j<1000; j++){
    p = gen_node();
    fscanf(fp, "%d", &p->data);
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
void search(DlinkList *dlink, int key){
  Node *p, *tail;
  int i = 0;
  long count = 0;
  bool flag = false;

  tail = dlink->tail;
  p = tail;
  for(i = 0; p != NULL; i++, p = p->prev){
    count++;
    if(p->data == key){ /* 成功 */
      if(flag == false){
        flag = true; //一度発見したことを記憶
        // printf("%dは", key); //初回のみ
      }
      // printf("%d", i+1); //要素の位置を出力
      break;
    }
  }
  if(flag == false){
    printf("探索に失敗しました\n"); //一度も発見せず
  }else{
    printf("探索に成功しました.\n");
  }
  printf("計算量：%ld\n", count);
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
}