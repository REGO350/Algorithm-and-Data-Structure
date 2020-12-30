// キュー(ポインタを用いたリスト構造による実現)
#include <stdio.h>
#include <stdlib.h>

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
void enqueue(Queue *q,int data);
int dequeue(Queue *q);
void disp_queue(Queue *q);

int main() {
  Queue *q;
  q = gen_queue();
  while (1){
    int menu, data;
    printf("HEAD| "); disp_queue(q); printf("|TAIL\n");
    printf("(1) Enqueue (2) Dequeue (0) Quit : "); scanf("%d",&menu);
    if (menu == 0) break;
    switch (menu) {
      case 1:
        printf("Data: "); scanf("%d", &data);
        enqueue(q, data);
        printf("[ Enqueue %d ]\n", data);
        break;
      case 2:
        if (is_empty(q)){
          printf("[ Queue is empty ]\n");
        } else {
          data=dequeue(q);
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
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
}

Node *gen_node(void){
  return (Node *)malloc(sizeof(Node));
  // return (Node *)calloc(1,sizeof(Node));
}