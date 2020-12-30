#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
  char name[20];
  char tel[20];
  struct _Node *next;
} Node;

Node *gen_node(void);

int main(void){
  Node *head, *p;
  
  head = NULL;
  while(p=gen_node(),scanf("%s %s",p->name,p->tel)!=EOF){
    p->next = head; 
    head = p;
  }
  p = head;
  while(p != NULL){
    printf("%15s %15s\n",p->name,p->tel); 
    p = p->next;
  }
  
  return 0; 
}

Node *gen_node(void)
{
  return (Node *)malloc(sizeof(Node));
}