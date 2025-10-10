// Tipo de Dado
typedef struct elem{
    int key;
    struct elem *next;
}Elem;

typedef struct{
    Elem *head;
}List;

// Operacoes

void create(List *L);

void add(List *L, int key);

void addEnd(List *L, int key);

void addSort(List *L, int sort, int key);

void show(List *L);

int size(List *L);

int cp(List *L1, List *L2);

int isList(List *L1, int key);

int isSort(List *L1);

int cpUnique(List *L1, List *L2);

int joinSort(List *L1, List *L2, List *L3);

int invert(List *L1, List *L2);

void destroy(List *L);
