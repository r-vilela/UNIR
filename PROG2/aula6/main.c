#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 30

typedef struct{
    char status;
    char letra;
    char nome[10];
    int elo;
}elem;

void create(elem *ls){
    char letra = 'N';
    int i=0;
    elem e;
    e.elo = -1;
    e.status = 'L';
    strcpy(e.nome," ");

    for(int c=0;c<TF;c++){
        if(i==13)
            letra='A';

        if(c<26){
            e.letra = letra++;
        }else{
            e.letra = ' ';
        }

        ls[i++]=e;
    }
}

void show(elem *ls){
    printf("Exibindo tabela\n");
    for(int i=0;i<TF;i++){
        printf("\tPos: %d Status: %c Letra: %c Nome: %s Elo: %d\n",
                i, ls[i].status, ls[i].letra, ls[i].nome, ls[i].elo);
    }
}

int hash(char l){
    return (l%26);
}

int add(elem *ls, char *nome){
    int pos = hash(nome[0]);
    int i;

    if(ls[pos].status!='O'){
        strcpy(ls[pos].nome, nome);
        ls[pos].status = 'O';
        return 1;
    }else{
        for(i=26;i<TF;i++)
            if(ls[i].status!='O')
                break;
        if(i<TF){
            ls[i].status = 'O';
            ls[i].letra = nome[0];
            strcpy(ls[i].nome, nome);
            if(ls[pos].elo!=-1){
                ls[i].elo = ls[pos].elo;
                ls[pos].elo = i;
            }else{
                ls[pos].elo = i;
            }
            return 1;
        }
    }
    return 0;
}

void showLetter(elem *ls, char letra){
    int pos = hash(letra);

    printf("Exibindo tabela por letra %c\n", letra);
    while(pos!=-1){
        printf("\tPos: %d Status: %c Letra: %c Nome: %s Elo: %d\n",
                pos, ls[pos].status, ls[pos].letra, ls[pos].nome, ls[pos].elo);
        pos = ls[pos].elo;
    }
}

int rmv(elem *ls, char *nome){
    int pos = hash(nome[0]), ant=-1;

    while(strcmp(ls[pos].nome, nome)&&pos!=-1){
        ant = pos;
        pos = ls[pos].elo;
    }

    if(!strcmp(ls[pos].nome, nome)){
        ls[pos].status='R';
        if(ant!=-1)
            ls[ant].elo = ls[pos].elo;
        return 1;
    }
    return 0;
}

int main(){
    elem list[TF];
    char nome[10], letra;
    int opc;

    create(list);

    do{
        printf("-------------------------------\n");
        printf("1-Adicionar\n");
        printf("2-Exibir\n");
        printf("3-Exibir Nomes por letra\n");
        printf("4-Remover\n");
        printf("0-Sair\n");

        printf("\nEntre com a opcao: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc) {
            case 1:
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", nome);
                if(add(list,nome))
                    printf("Adicionado com Sucesso!\n\n");
                else
                    printf("Erro ao adicionar!\n\n");
                break;
            case 2:
                show(list);
                break;
            case 3:
                printf("Digite uma letra para ser exibida: ");
                scanf(" %c", &letra);
                showLetter(list,letra);
                break;
            case 4:
                printf("Digite o novo nome: ");
                scanf(" %[^\n]", nome);
                if(rmv(list,nome))
                    printf("Removido com Sucesso!\n\n");
                else
                    printf("Erro ao remover!\n\n");
                break;
            case 0:
                printf("Fechando sistema!\n");
            default:
                printf("Opcao invalida!\n");
        }
    }while(opc!=0);

    return 0;
}

