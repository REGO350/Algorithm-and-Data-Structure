typedef struct _node
{
  int id;
  char *data;
  struct _node *left, *right;
  unsigned char flag; // 追加した新メンバー
} Node;

Node *newNode(int id, char *data);
void printNode(Node *nList);