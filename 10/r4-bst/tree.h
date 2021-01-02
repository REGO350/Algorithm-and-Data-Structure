typedef struct _node
{
  int id;
  int key;
  char *data;
  struct _node *left, *right;
  unsigned char flag; // 追加した新メンバー
} Node;

Node *newNode(int id, char *data);
Node *newNodeBST(int key);
void printNodeBST(Node *v);
void printNode(Node *nList);
void printTree(Node *n);
void deleteTree(Node *n);