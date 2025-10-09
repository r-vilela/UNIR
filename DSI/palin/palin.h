
// Estrutura Pilha
//
// Inserir na pilha: Empilhar (Push)
// Remover da Pilha: Desempilhar (pop, popup(Remove e retornar))
//
// Verificar Primeiro Elemento: top

// Tipo de Dado
typedef char tipo_elem;

// Estrutra de Dados
typedef struct no{
    tipo_elem info;
    struct no *prox;
}No;

typedef struct{
    No *topo;
}Pilha;

// Operacoes
void criar(Pilha *P);

int vazia(Pilha *P);

int cheia(Pilha *P);

int push(Pilha *P, tipo_elem v);

tipo_elem pop(Pilha *P);

void popup(Pilha *P);

tipo_elem top(Pilha *P);

void esvaziar(Pilha *P);

void exibir(Pilha *P);

void exibirRec(No *n);
