// キュー(配列とリングバッファによる実現)
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// キューを表す構造体
typedef struct { int data[MAX];
  int head; // キューの先頭
  int tail; // キューの最後尾
  int max; // キューの容量
  int num; // キューに格納されたデータ数
} Queue;

Queue *gen_queue();
int is_empty(Queue *q);
int is_full(Queue *q);
void enqueue(Queue *q,int data);
int dequeue(Queue *q);
void disp_queue(Queue *q);

int main(){
  Queue *q;
  q = gen_queue();

  while (1){
    int menu, data;

    printf(" HEAD| "); disp_queue(q); printf("|TAIL\n");
    printf(" q->head=%d, q->tail=%d, q->num=%d,q->max=%d\n", q->head, q->tail, q->num, q->max);
    printf(" (1) Enqueue (2) Dequeue (0) Quit : "); scanf("%d",&menu);

    if (menu == 0) break;
    switch (menu) {
      case 1:
        if (is_full(q)){
          printf("[ Queue is full ]\n");
        } else {
          printf("Data: "); scanf("%d",&data);
          enqueue(q, data);
          printf("[ Enqueue %d ]\n",data);
        }
        break;
      case 2:
        if (is_empty(q)){
          printf("[ Queue is empty ]\n");
        } else {
          data = dequeue(q);
          printf("[ Dequeue %d ]\n",data);
        }
        break;
      }
    }
  return 0;
}

Queue *gen_queue() {
  Queue *q;
  q=(Queue *)malloc(sizeof(Queue));
  // q=(Queue *)calloc(1,sizeof(Queue));
  q->head = q->tail = q->num = 0;
  q->max = MAX;
  return q;
}

int is_empty(Queue *q) {
  if (q->num == 0)
    return 1;
  else
    return 0;
}

int is_full(Queue *q) {
  if (q->num == q->max)
    return 1;
  else
    return 0;
}

void enqueue(Queue *q, int data){
  if(is_full(q)){
    printf("In function enqueue: queue is full.\n");
    exit(1);
  }
  q->data[q->tail] = data;
  q->tail = (q->tail + 1) % q->max; q->num++;
}

int dequeue(Queue *q){
  int data;
  if(is_empty(q)){
    printf("In function dequeue: queue is empty.\n"); exit(1);
  }
  data = q->data[q->head];
  q->head = (q->head + 1) % q->max; q->num--;
  return data;
}

void disp_queue(Queue *q) {
  int ptr, num, i;

  ptr = q->head;
  num = q->num;
  while(num>0){
    i=ptr % q->max;
    printf("data[%d]=%d ", i, q->data[i]);
    ptr++;
    num--;
  }
}