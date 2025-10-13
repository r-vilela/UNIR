#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int chave;
    char nome[10];
    int elo;
}Elem;

void create(Elem *L, int tam){
    for(int i=0;i<tam;i++){
        L[i].chave=0;
        L[i].elo=-1;
    }
    printf("Lista criada!\n");
}

int hash(int chave, int tam){
    return (chave%tam);
}

void insert(Elem *L, int chave, char *nome, int qnt, int tam){
    int pos = hash(chave, qnt),i;
    if(L[pos].chave==0){
        L[pos].chave = chave;
        strcpy(L[pos].nome, nome);
    }else{
        for(i=qnt;i<tam;i++){
            if(L[i].chave==0){
                L[i].elo = L[pos].elo;
                L[pos].elo=i;
                L[i].chave = chave;
                strcpy(L[i].nome, nome);
                break;
            }
        }
        if(i=tam)
            printf("Nao foi possivel adicionar. Lista cheia!\nFaca um ReHashing\n\n");
    }

}

void show(Elem *L, int tam, int qnt){
    int i;
    for(i=0;i<qnt;i++)
        if(L[i].chave!=0)
            printf("\t%d - Chave: %d Nome: %s Elo: %d\n",
                    i, L[i].chave, L[i].nome, L[i].elo);
    if(L[i].chave!=0){
        printf("OVERFLOW\n");
        for( ;i<tam;i++)
            if(L[i].chave!=0)
                printf("\t%d - Chave: %d Nome: %s Elo: %d\n",
                        i, L[i].chave, L[i].nome, L[i].elo);
    }
}

void reHashing(Elem *L, int tam, Elem *NL, int nTam, int *reHash){
    int i, pos, nPos;

    if(*reHash==0){
        *reHash=1;
        for(i=0;i<tam;i++){
            if(L[i].chave!=0){
                nPos=nTam-(int)(nTam*0.3);
                pos = hash(L[i].chave,nPos);
                if(NL[pos].chave == 0){
                    NL[pos].chave = L[i].chave;
                    strcpy(NL[pos].nome, L[i].nome);
                    NL[pos].elo = -1;
                }else{
                    for( ;nPos<nTam;nPos++){
                        if(NL[nPos].chave==0){
                            NL[nPos].elo = NL[pos].elo;
                            NL[pos].elo=nPos;
                            NL[nPos].chave = L[i].chave;
                            strcpy(NL[nPos].nome, L[i].nome);
                            break;
                        }
                    }
                }
            }
        }
    }else
        printf("ReHash ja existe!\n");
}

int main(){
    int opc, chave, tam=17, qtd=tam-(int)(tam*0.3)+1, nvTam=tam*2, nvQtd=nvTam-(int)(nvTam*0.3), reHash=0;
    char nome[10];
    Elem L[tam];
    Elem NL[nvTam];

    create(L, tam);
    create(NL, nvTam);

    do{
        printf("Lista: \n");
        if(reHash){
            printf("ReHash\n");
            show(NL, nvTam, nvQtd);
        }else{
            show(L, tam, qtd);
        }

        printf("\n1-Inserir\n");
        printf("2-ReHash\n");

        printf("\nDigite a opcao: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Digite a chave: ");
                scanf("%d", &chave);
                printf("Digie o nome: ");
                scanf(" %[^\n]", nome);
                if(reHash)
                    insert(NL,chave,nome, nvQtd, nvTam);
                else
                    insert(L,chave,nome, qtd, tam);
                break;

            case 2:
                reHashing(L, tam, NL, nvTam, &reHash);
                break;

            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }

    }while(opc!=0);


    return 0;
}
