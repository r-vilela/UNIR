#define TF 7
// Estruta de Dado
typedef struct{
    int chave;
}elem;

typedef struct{
    elem A[TF];
    int tam;
}list;

typedef struct{
    elem info;
    int count;
}count_list;

// Operacoes
void create(list *L1);

int isSorted(list *L1);

int insert(list *L1,elem v);

int search(list *L1,elem v);

void copy(list *L1,list *L2);

void copyUnq(list *L1,list *L2);

void invert(list *L1,list *L2);

void join(list *L1,list *L2,list *L3);

void countElem(list *L1);

void extreme(list *L1);
