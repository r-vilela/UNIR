#define MAX 10

typedef struct{
    int key;
}typeElem;

typedef struct{
    typeElem A[MAX];
    int nElem;
}list;

int create(list *L);

int add(list *L, typeElem elem);

int rmv(list *L, typeElem elem);

void show(list *L);

int isSorted(list *L);

int copy(list *L1, list *L2);

int find(list *L, typeElem elem);

int copyUnique(list *L1, list *L2);

int copyInvert(list *L1, list *L2);
