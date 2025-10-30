
typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}Node;

typedef struct{
    Node *root;
}Tree;


void create(Tree *T);

int add(Tree *T, int val);

int addRec(Node **node, int val);

void show(Tree *T);

void showRec(Node *n, int nvl);

int rmv(Tree *T, int val);

int rmvRec(Node **node, int val);

void destroy(Tree *T);

void destroyRec(Node **node);

Node * search(Tree *T, int val);

