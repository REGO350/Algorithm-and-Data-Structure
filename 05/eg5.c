// スタック(ポインタを用いたリスト構造による実現)
#include <stdio.h>
#include <stdlib.h>
// ノードを表す構造体
typedef struct _Node {
  int data;
  struct _Node *next;
} Node;
// スタックを表す構造体
typedef struct {
  Node *top; // スタックの頂上
} Stack;

Node *gen_node(void);
Stack *gen_stack(void);
int is_empty(Stack *s);
void push(Stack *s,int data); int pop(Stack *s);
void disp_stack(Stack *s);

int main() {
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
        printf("Data: "); scanf("%d",&data);
        push(s,data);
        printf("[ Push %d ]\n",data);
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

Stack *gen_stack(void) {
  Stack *s;

  s = (Stack *)malloc(sizeof(Stack));
  // s=(Stack *)calloc(1,sizeof(Stack));
  s->top = NULL; // 空のスタックで初期化
  return s;
}

int is_empty(Stack *s) {
  if (s->top == NULL){
    return 1;
  } else {
    return 0;
  }
}

void push(Stack *s,int data){
  Node *new;
  // 新しいノードを生成して，これまでの頂上に追加
  new = gen_node();
  new->data = data;
  new->next = s->top;
  // 頂上を追加ノードに更新
  s->top = new;
}

int pop(Stack *s)
{
  int data;
  Node *old;
  if (is_empty(s)){
    printf("In function pop: stack is empty.\n");
    exit(1);
  }
  old = s->top;
  data = old->data;
  s->top = old->next;
  free(old);

  return data;
}

void disp_stack(Stack *s) {
  Node *ptr;

  ptr = s->top;
  while(ptr != NULL){
    printf("%d ",ptr->data);
    ptr = ptr->next;
  }
}

Node *gen_node(void) {
  return (Node *)malloc(sizeof(Node));
}