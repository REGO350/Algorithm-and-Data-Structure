// スタック(配列による実現，構造体を利用)
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// スタックを表す構造体
typedef struct {
  int data[MAX];
  int sp; // スタックポインタ
  int max; // スタックの最大容量
} Stack;

Stack *gen_stack(); // スタックを生成
int is_empty(Stack *s); // スタック s が空ならば真を返す
int is_full(Stack *s); // スタック s が満杯ならば真を返す
void push(Stack *s,int data);
int pop(Stack *s);
void disp_stack(Stack *s);

int main(){
  // スタックの実体のアドレスを表すポインタ変数
  Stack *s;
  // スタックの実体をメモリに生成して，アドレスをポインタ変数sに格納
  s = gen_stack();

  while (1){
    int menu, data;
    printf("TOP| "); disp_stack(s); printf("|BOTTOM\n");
    printf("(1) Push (2) Pop (0) Quit : "); scanf("%d",&menu);
    if (menu == 0) break;
    switch (menu) {
      case 1:
        if (is_full(s)){
          printf("[ Stack is full ]\n");
        } else {
          printf("Data: "); scanf("%d",&data);
          push(s,data);
          printf("[ Push %d ]\n",data);
        }
        break;
      case 2:
        if (is_empty(s)){
          printf("[ Stack is empty ]\n");
        } else {
          data=pop(s);
          printf("[ Pop %d ]\n",data);
        }
        break;
      }
    }
  return 0;
}

Stack *gen_stack() {
  Stack *s;
  // スタックの実体をメモリに確保
  s = (Stack *)malloc(sizeof(Stack));
  // または s=(Stack *)calloc(1,sizeof(Stack));
  // 最初は空のスタックとして初期化:スタックポインタはゼロ
  s->sp = 0;
  s->max = MAX;
  return s;
}

// 以降は大域変数の配列と同様
int is_empty(Stack*s) {
  if (s->sp <= 0)
    return 1;
  else
    return 0;
}

int is_full(Stack*s) {
  if (s->sp >= s->max)
    return 1;
  else
    return 0;
}

void push(Stack*s, int data) {
  if(is_full(s)){
    printf("In function push: stack is full.\n");
    exit(1);
  }
  s->data[s->sp++]=data;
}

int pop(Stack*s) {
  if(is_empty(s)){
    printf("In function pop: stack is empty.\n");
    exit(1);
  }
  return s->data[--s->sp];
}

void disp_stack(Stack*s) {
  int ptr;
  ptr = s->sp;
  while(ptr>0)
    printf("%d ",s->data[--ptr]);
}