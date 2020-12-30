typedef struct _node
{
  int id;
  char *data;
  struct _node *left, *right;
} Node;

Node *newNode(int id, char *data);
void printNode(Node *nList);