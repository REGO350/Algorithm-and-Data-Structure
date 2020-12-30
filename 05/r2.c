// キュー(ポインタを用いたリスト構造による実現)
#include <stdio.h>
#include <stdlib.h>

#define DATA_FILE "number.txt"

// ノードを表す構造体
typedef struct _Node {
  int data;
  struct _Node *next;
} Node;
// キューを表す構造体
typedef struct {
  Node *head;
  Node *tail;
} Queue;

Node *gen_node(void);
Queue *gen_queue(void);
int is_empty(Queue *q);
void enqueue(Queue *q, int data);
int dequeue(Queue *q);
void disp_queue(Queue *q);

int main() {
  Queue *q0, *q1, *q;
  FILE *fp;
  char *data_file = DATA_FILE;
  int menu1, menu2, data;

  q0 = gen_queue(); //偶数用のキュー
  q1 = gen_queue(); //奇数用のキュー
  if((fp = fopen(data_file, "r")) == NULL){
    printf("%s can not be open\n", data_file); //ファイルチェック
  }
  while(fscanf(fp, "%d", &data) != EOF){ //EOFになるまでファイルを1文字ずつ読む
    if(data % 2 == 0){
      enqueue(q0, data); //読んだデータdataが2で割り切れたらq0(偶数)にenqueue
    }else{
      enqueue(q1, data); //読んだデータdataが2で割り切れなかったらq1(奇数)にenqueue
    }
  }
  fclose(fp); //ファイルクローズ

  while(1){
    printf("Even: HEAD| "); disp_queue(q0); printf("|TAIL\n"); //q0プリント
    printf(" Odd: HEAD| "); disp_queue(q1); printf("|TAIL\n"); //q1プリント
    printf("(1) Enqueue (2) Dequeue (0) Quit : "); scanf("%d",&menu1); //操作を入力
    if (menu1 == 0) break;
    printf("(0) Even (1) Odd : "); scanf("%d", &menu2); //操作するのがq0かq1か
    switch (menu2) {
      case 0:
        q = q0; break; //qにq0のアドレスを代入
      case 1:
        q = q1; break; //qにq1のアドレスを代入
    }
    switch (menu1) {
      case 1:
        printf("Data: "); scanf("%d", &data);
        enqueue(q, data);
        printf("[ Enqueue %d ]\n", data);
        break;
      case 2:
        if (is_empty(q)){
          printf("[ Queue is empty ]\n");
        } else {
          data = dequeue(q);
          printf("[ Dequeue %d ]\n", data);
        }
        break;
      }
    }
  return 0;
}

Queue *gen_queue(void) {
  Queue *q;
  q = (Queue *)malloc(sizeof(Queue));
  // q=(Queue *)calloc(1,sizeof(Queue));
  q->head = q->tail = NULL;
  return q;
}

int is_empty(Queue *q) {
  if (q->head == NULL){
    return 1;
  } else {
    return 0;
  }
}

void enqueue(Queue *q, int data){
  Node *new;

  new = gen_node();
  new->data = data;
  new->next = NULL;
  if (is_empty(q)){
    q->head = q->tail = new;
  }else{
    q->tail->next = new;
    q->tail = new;
  }
}

int dequeue(Queue *q)
{
  int data;
  Node *old;
  if (is_empty(q)){
    printf("In function dequeue: queue is empty.\n");
    exit(1);
  }
  old = q->head;
  data = old->data;
  q->head = old->next;
  free(old);

  return data;
}

void disp_queue(Queue *q) {
  Node *ptr;

  ptr = q->head;
  while(ptr != NULL){
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
  // return (Node *)calloc(1,sizeof(Node));
}