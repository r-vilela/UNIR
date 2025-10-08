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

int add(List *L, int key);

void show(List *L);

int cp(List *L1, List *L2);

int cpUnique(List *L1, List *L2);

int invert(List *L1, List *L2);

void destroy(List *L);
