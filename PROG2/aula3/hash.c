#include <stdio.h>
#include <stdlib.h>

#define TF 8

typedef struct{
    char status;
    int chave;
}registro;

void criar(registro p[TF]){
    int i;
    for(i=0;i<TF;i++){
        p[i].status = 'L';
        p[i].chave = 0;
    }
    printf("Tabela Hash criada com sucesso!\n");
}

int end(int chave){
    return chave%TF;
}

void inserir(registro p[TF]){
    int chave;
    printf("Digite a chave a ser inserida: ");
    scanf("%d", &chave);
    int ender = end(chave), vezes;

    for(vezes=0;vezes<TF;vezes++){
        if(p[ender].status=='L'||p[ender].status=='R'){
            p[ender].status='O';
            p[ender].chave=chave;
            break;
        }
        ++ender;
        if(ender==TF){
            ender=0;
        }
    }
    if(vezes==TF){
        printf("Nao foi possivel adicionar a chave!\n");
    }else{
        printf("Inserido com sucesso na posicao %d!\n", ender);
    }
}

void exibir(registro p[TF]){
    int i;
    printf("Exibindo Tabela!\n");
    printf("Pos \t| Status| Chave\n");
    for(i=0;i<TF;i++){
        printf("%d\t| '%c'\t| %d\n",i, p[i].status, p[i].chave);
    }
}

void remover(registro p[TF]){
    int chave;
    printf("Digite a chave a ser removida: ");
    scanf("%d", &chave);
    int i, ender = end(chave);
    for(i=0;i<TF;i++){
        if(p[ender].status=='O'&&p[ender].chave==chave){
            p[ender].status='R';
            break;
        }
        ++ender;
        if(ender==TF){
            ender=0;
        }
    }
    if(i==TF){
        printf("Chave nao encontrada!\n");
    }else{
        printf("Removido com sucesso!\n");
    }
}

int main(){
    int opc=1;
    registro p[TF];

    criar(p);

    while(opc!=0){

        printf("-------------------------------\n");
        printf("\tTabela Hash\n\n");

        printf("1-Inserir\n");
        printf("2-Exibir\n");
        printf("3-Remover\n");
        printf("0-Sair do programa\n");

        printf("Digite a opcao: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                inserir(p);
                break;
            case 2:
                printf("Exibindo Tabela\n");
                exibir(p);
                break;
            case 3:
                remover(p);
                break;
            case 0:
                printf("Saindo do programa . . .\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }


    return 0;
}
