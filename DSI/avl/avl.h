// Estrutura de Dados
typedef struct node{
    int value;
    struct node *left;
    struct node *right;
    int RB;
}Node;

typedef struct{
    Node *root;
}AVL;

// Operacoes
void create(AVL *A);

void insert(AVL *A, int value);

void rmv(AVL *A, int value);

