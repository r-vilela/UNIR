#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 10

typedef struct{
    char status;
    char placa[9];
    int dia, mes, ano;
    int infra;
}registro;

void criar(registro *p){
    int i;
    for (i=0; i<TF; i++){
        p[i].status = 'L';
        strcpy(p[i].placa, "");
        p[i].dia=0;
        p[i].mes=0;
        p[i].ano=0;
        p[i].infra=0;

    }
    printf("Tabela criada!");
}

void exibir(registro *p){
    int i;
    for (i=0; i<TF; i++){
        printf("\tStatus: %c - Placa[%d]: %s \n\t\tInfracao: %d Data: %d/%d/%d\n",
                p[i].status, i, p[i].placa, p[i].infra, p[i].dia, p[i].mes, p[i].ano );
    }
}

int hash(char *placa){
    int total;
    for(int i=0;placa[i]!='\0';i++){
        total += placa[i];
    }
    return total%TF;
}

void inserir(registro *p, char *placa, int dia, int mes, int ano, int infra, int pos, int k){
    if(k<=TF){
        //printf("pos = %d,tenta = %d,prox %d\n", pos, k, (pos+k)%TF);
        if(p[pos].status == 'O'){
            inserir(p, placa, dia, mes, ano, infra, (pos+k)%TF, k+1);
        } else {
            p[pos].status = 'O';
            strcpy(p[pos].placa, placa);
            p[pos].dia = dia;
            p[pos].mes = mes;
            p[pos].ano = ano;
            p[pos].infra = infra;
        }
    }else{
        printf("Nao foi possivel inserir");
    }
}

void buscar(registro *p, char *placa){
    for(int pos=0;pos<TF;pos++){
        if(strcmp(p[pos].placa, placa) == 0 && p[pos].status == 'O'){
            printf("\tStatus: %c - Placa[%d]: %s \n\t\tInfracao: %d Data: %d/%d/%d\n",
                    p[pos].status, pos, p[pos].placa, p[pos].infra, p[pos].dia, p[pos].mes, p[pos].ano );
        }
    }
}

void remover(registro *p, int chave){
    /*int ender = buscar(p, chave, hash(chave), 1);

    if(ender<0){
        printf("Nao foi possivel encontrar a chave");
    }else{
        printf("Chave[%d]: %d ", ender, p[ender].chave, p[ender].status);
        printf(" Removido com sucesso!");
        p[ender].status='R';
    }
    */
}

int main()
{
    registro p[TF];
    char placa[9];
    int opc, dia, mes, ano, infra;
    criar(p);

    printf("Lista Hash - Tentativa Quadratica");

    do{
        printf("\n1-Exibir");
        printf("\n2-Inserir");
        printf("\n3-Buscar");
        printf("\n0-Sair do programa");

        printf("\n\nEscreva sua opcao: ");
        scanf("%d", &opc);
        system("clear");

        switch(opc){
            case 1:
                exibir(p);
                break;
            case 2:
                printf("Digite a placa: ");
                getchar();
                fgets(placa, sizeof(placa), stdin);

                printf("Digite a data\n");

                printf("Dia: ");
                scanf("%d", &dia);

                printf("Mes: ");
                scanf("%d", &mes);

                printf("Ano: ");
                scanf("%d", &ano);

                printf("Digita a infracao: \n");
                scanf("%d", &infra);

                inserir(p, placa, dia, mes, ano, infra, hash(placa), 1);
                break;
            case 3:
                printf("Digite a placa: ");
                getchar();
                fgets(placa, sizeof(placa), stdin);

                printf("Procurando infracoes . . .\n");
                buscar(p, placa);
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
