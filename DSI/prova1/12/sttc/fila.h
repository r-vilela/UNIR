#define n 10
typedef struct{
    int v[n];
    int head;
    int tail;
}Fila;

void create(Fila *F);

int insert(Fila *F, int v);

int isFull(Fila *F);

int isEmpty(Fila *F);

int size(Fila *F);

int first(Fila *F);

int delete(Fila *F);

void show(Fila *F);

