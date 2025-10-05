
typedef int tipo_elem;

typedef struct no{
    tipo_elem info;
    struct no *prox;
}No;

typedef struct{
    No *inicio, *fim;
}Fila;

void definir(Fila *F);
int inserir(Fila *F, tipo_elem c);
int remover(Fila *F);
int vazia(Fila *F);
int tamanho(Fila *F);
void esvaziar(Fila *F);
void exibir(Fila *F);

