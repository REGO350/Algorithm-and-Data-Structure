// スタック(配列による実現，大域変数を使用)
#include <stdio.h>
#include <stdlib.h> // malloc, 強制終了 exit(1) で必要

#define MAX 5
int stack[MAX]; // スタックを表現する配列
int sp = 0; // スタック・ポインタ

int is_empty(void); // スタックが空であれば真を返す
int is_full(void); // スタックが満杯であれば真を返す
void push(int n);
int pop(void);
void disp_stack(void); // スタックを表示する

int main(){
  while (1){
    int menu, data;
    // スタックの表示:(例)TOP| 33 22 11 |BOTTOM
    printf("TOP| "); disp_stack(); printf("|BOTTOM\n");
    // Push, Pop, 終了を選択
    printf("(1) Push (2) Pop (0) Quit : "); scanf("%d",&menu);
    if (menu==0) break;
    switch (menu) {
      case 1:
        if (is_full()){
          printf("[ Stack is full ]\n");
        } else {
          printf("Data: "); scanf("%d",&data);
          push(data);
          printf("[ Push %d ]\n",data);
        }
        break;
      case 2:
        if (is_empty()){
          printf("[ Stack is empty ]\n");
        } else {
          data=pop();
          printf("[ Pop %d ]\n",data);
        }
        break;
      }
    }
  return 0;
}

int is_empty(void) {
  if (sp<=0)
    return 1;
  else
    return 0;
}

int is_full(void){
  if (sp>=MAX)
    return 1;
  else
    return 0;
}

void push(int data) {
  if(is_full()){ // main 関数で確認しているので，実際には以下は実行されない
    printf("In function push: stack is full.\n");
    exit(1);
  }
  stack[sp++]=data;
  // 後値インクリメント sp++ は値を評価した後にインクリメントされる //(例)sp=2のとき，
  // stack[2]にdataが代入される，spはインクリメントされてsp=3になる
}

int pop(void) {
  if(is_empty()){ // main 関数で確認しているので，実際には以下は実行されない
    printf("In function pop: stack is empty.\n");
    exit(1);
  }
  return stack[--sp];
  // 前値デクリメント --sp はデクリメントされた後に値が評価される
  //(例)sp=2のとき，
  // spがデクリメントされてsp=1になり，stack[1]の値がreturnされる
}

void disp_stack(void) {
  int ptr;

  ptr = sp;
  while(ptr > 0)
    printf("%d ",stack[--ptr]);
}