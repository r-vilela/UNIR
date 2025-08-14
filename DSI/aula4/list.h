#define MAX 10

// Objeto
typedef struct{
    int key;
}tipoElem;

// Estrutura de Dados
typedef struct{
    tipoElem A[MAX];
    int nelem;
}lista;

// Operacoes

int create(lista *L);

int isFull(lista *L);

int isEmpty(lista *L);

int insertSort(lista *L, tipoElem newElem);

int insertStart(lista *L, tipoElem newElem);

int insertEnd(lista *L, tipoElem newElem);

int removeStart(lista *L);

int removeEnd(lista *L);

int removeKey(lista *L, int key);

int search(lista *L, int key);

int destroy(lista *L);

void show(lista *L);

int size(lista *L);
