#define MAX 10
#define NIL -1

// Objeto
typedef struct{
   int key;
}tipoElem;

typedef struct{
    tipoElem info;
    int next;
}node;

// Estrutura de Dados

typedef struct{
    node A[MAX];
    int start, avl;
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

int removeKey(list *L, int key);

int search(list *L, int key);

int binarySearch(list *L, int key);

int destroy(list *L);

void show(list *L);

int size(list *L);
