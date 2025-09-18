// Estrutura Pilha
//
// Inserir na pilha: Empilhar (Push)
// Remover da Pilha: Desempilhar (pop, popup(Remove e retornar))
//
// Verificar Primeiro Elemento: top
#define MAX 10
// Tipo de Dado
typedef char tipo_elem;

// Estrutra de Dados
typedef struct{
    tipo_elem A[MAX];
    int topo;
}Pilha;

// Operacoes
void criar(Pilha *P);

int vazia(Pilha *P);

int cheia(Pilha *P);

int push(Pilha *P, tipo_elem v);

tipo_elem pop(Pilha *P);

void popup(Pilha *P);

tipo_elem top(Pilha *P);

int esvaziar(Pilha *P);

void exibir(Pilha *P);
