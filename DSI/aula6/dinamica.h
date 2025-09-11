// Objeto
typedef struct{
   int key;
}tipoElem;

typedef struct node{
    tipoElem info;
    struct node *next;
}node;

// Estrutura de Dados

typedef struct{
    node *head;
}list;

// Operacoes

int create(list *L);

int isFull(list *L);

int isEmpty(list *L);

int insertSort(list *L, tipoElem newElem);

int insertStart(list *L, tipoElem newElem);

int insertEnd(list *L, tipoElem newElem);

int removeStart(list *L);

int removeEnd(list *L);

int removeEndRec(list *L, node **n, node **m);

int removeKey(list *L, int key);

int search(list *L, int key);

int binarySearch(list *L, int key);

void destroy(list *L);

void destroyRec(node **n);

void show(list *L);

int size(list *L);

int sizeRec(node *n);

