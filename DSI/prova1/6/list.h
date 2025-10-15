#define n 100

typedef struct{
    int v[n+1];
    int ult;
}list;

void create(list *l);

int empty(list *l);

int full(list *l);

int insert(list *l, int a);

int delete(list *l, int a);

int search(list *l, int a);

int searchSent(list *l, int a);

void show(list *l);

