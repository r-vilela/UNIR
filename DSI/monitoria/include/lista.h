#ifndef LISTA_H

typedef struct tipo_elem{
    int n;
} Tipo_elem;

typedef struct no{
    Tipo_elem elem;
    struct no *prox;
} No;

typedef struct lista_d{
    int tam;
    No *head;
}Lista_d;

void criar(Lista_d *l);
Lista_d* criar2();
int destruir(Lista_d *l);
int destruir_rec(No* n, Lista_d *l);
int destruir2(Lista_d *l);

int vazia(Lista_d *l);
void exbir(Lista_d *l);
int tamanho(Lista_d *l);

int inserir_inicio(Lista_d *l,Tipo_elem valor);
int inserir_inicio(Lista_d *l,Tipo_elem valor);
int inserir_ordenado(Lista_d *l,Tipo_elem valor);
int remover_inicio(Lista_d *l);
int remover_final(Lista_d *l);
int remover_rec(Lista_d **l, int valor);
int buscar(Lista_d *l);

#endif // !LISTA_H
