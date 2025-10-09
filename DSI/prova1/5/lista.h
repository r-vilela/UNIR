#define TF 15
// Estruta de Dado
typedef struct{
    int chave;
}elem;

typedef struct{
    elem A[TF];
    int tam;
}list;

typedef struct{
    int chave;
    int count;
}cnt_elem;

typedef struct{
    cnt_elem C[TF];
    int tam;
}cnt_list;

// Operacoes
void create(list *L1);

int isSorted(list *L1);

int insert(list *L1,elem v);

int search(list *L1,elem v);

void copy(list *L1,list *L2);

void copyUnq(list *L1,list *L2);

void invert(list *L1,list *L2);

void join(list *L1,list *L2,list *L3);

int countElem(list *L1,int v);

int inCount(cnt_list *C1, int v);

void createCount(list *L1, cnt_list *C1);

void extreme(cnt_list *L1);
