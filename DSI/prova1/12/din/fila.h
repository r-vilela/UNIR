typedef struct node {
    int info;
    struct node *next;
}Node;

typedef struct{
    Node *head;
    Node *tail;
}Fila;

void create(Fila *F);

void insert(Fila *F, int v);

int isEmpty(Fila *F);

int first(Fila *F);

int delete(Fila *F);

void destroy(Fila *F);

void show(Fila *F);

