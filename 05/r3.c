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
  Stack *s0, *s1, *s2;
  int menu, data;
  // スタックの実体をメモリに生成して，アドレスをポインタ変数sに格納
  s0 = gen_stack();
  s1 = gen_stack();
  s2 = gen_stack();

  while (1){
    printf("TOP| "); disp_stack(s0); printf("|BOTTOM\n");
    printf("(1) Push (2) Pop (3) Rearrange (0) Quit : ");
    if(scanf("%d", &menu) != 1){
      scanf("%*[^\n]%*c");
      menu = -1;
    }
    if (menu == 0) break;
    switch (menu) {
      case 1:
        printf("Data: "); scanf("%d",&data);
        push(s0, data);
        printf("[ Push %d ]\n", data);
        break;
      case 2:
        if (is_empty(s0)){
          printf("[ Stack is empty ]\n");
        } else {
          data = pop(s0);
          printf("[ Pop %d ]\n",data);
        }
        break;
      case 3:
        data = pop(s0); //s0のn項目をpopしてdataに保存
        push(s1, data); //s1にdataをpush
        while(!is_empty(s0)){ //s0が空になるまで
          data = pop(s0); //s0のi項目（n-1 -> 0)をpopしてdataに保存
          push(s2, data); //s2にdataをpush
        } //s0が空になり、s1にはs0のn項目、s2にはs0の0項からn-1項まで
        data = pop(s1);
        push(s0, data); //s1(元はs0のn項目)をs0にpush
        while(!is_empty(s2)){ //s2が空になるまで
          data = pop(s2);
          push(s0, data); //s2のTOPから順にs0にpush
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

int pop(Stack *s){
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