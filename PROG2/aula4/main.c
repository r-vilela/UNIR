#include <stdio.h>
#include <stdlib.h>
#define TF 8

typedef struct{
    char status;
    int chave;
}registro;

void criar(registro *p){
    int i;
    for (i=0; i<TF; i++){
        p[i].status = 'L';
        p[i].chave = 0;
    }
    printf("Tabela criada!");
}

void exibir(registro *p){
    int i;
    for (i=0; i<TF; i++){
        printf("Chave[%d]: %d Status: %c \n", i, p[i].chave, p[i].status);
    }
}

int hash(int chave){
    return chave%TF;
}

void inserir(registro *p, int chave, int pos, int k){
    if(k<=TF){
        printf("pos = %d,tenta = %d,prox %d\n", pos, k, (pos+k)%TF);
        if(p[pos].status == 'O'){
            inserir(p, chave, (pos+k)%TF, k+1);
        } else {
            p[pos].status = 'O';
            p[pos].chave = chave;
        }
    }else{
        printf("Nao foi possivel inserir");
    }
}

int buscar(registro *p, int chave, int pos, int k){
    if(k<=TF){
        if(p[pos].chave == chave && p[pos].status == 'O'){
            return pos;
        } else {
            buscar(p, chave, (pos+k)%TF, k++);
        }
    }else{
        return -1;
    }
}

void remover(registro *p, int chave){
    int ender = buscar(p, chave, hash(chave), 1);

    if(ender<0){
        printf("Nao foi possivel encontrar a chave");
    }else{
        printf("Chave[%d]: %d ", ender, p[ender].chave, p[ender].status);
        printf(" Removido com sucesso!");
        p[ender].status='R';
    }
}

int main()
{
    registro p[TF];
    int opc, chave;
    criar(p);

    printf("Lista Hash - Tentativa Quadratica");

    do{
        printf("\n1-Exibir");
        printf("\n2-Inserir");
        printf("\n3-Remover");
        printf("\n0-Sair do programa");

        printf("\n\nEscreva sua opcao: ");
        scanf("%d", &opc);
        system("clear");

        switch(opc){
            case 1:
                exibir(p);
                break;
            case 2:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                inserir(p, chave, hash(chave), 1);
                break;
            case 3:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                remover(p, chave);
                break;
            case 0:
                printf("Encerrando o programa....");
                break;
            default:
                printf("Opcao invalida");
        }
    }while(opc!=0);

    return 0;
}
