#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TF 15

typedef struct{
    char nome[10];
    char depto[10];
    float sal;
    char status;
}Func;

typedef struct no{
    int posdado;
    struct no *prox;
}No;

typedef struct{
    char depto[10];
    No *head;
}List;

void emptyList(List *list){
    for(int i=0;i<TF;i++){
        list[i].head=NULL;
    }
}

int addFunc(){
    Func func;

    FILE *arq = fopen("FUNCIONARIO.dat", "ab");
    if(arq==NULL){
        FILE *arq = fopen("FUNCIONARIO.dat", "wb");
    }

    printf("\nAdicionar Usuario:\n");

    printf("\tEntre com o nome: ");
    scanf(" %[^\n]", func.nome);

    printf("\tEntre com o departamento: ");
    scanf(" %[^\n]", func.depto);

    printf("\tEntre com o salario: ");
    scanf("%f", &(func.sal));

    printf("\tEntre com o status: ");
    scanf(" %c", &func.status);

    fwrite(&func, sizeof(Func), 1, arq);

    fclose(arq);
    return 1;
}

int exibirFunc(){
    Func func;
    int pos = 0;
    FILE *arq = fopen("FUNCIONARIO.dat", "rb");

    if(arq == NULL)
        return 0;

    fread(&func, sizeof(Func), 1, arq);
    printf("\nArquivo Funcionarios!\n");
    while(!feof(arq)){
        printf("\tPosicao: %d, Nome: %s, Departamento: %s, Salario: R$%.2f, Status: %c\n",
                pos,func.nome, func.depto, func.sal, func.status);
        pos++;
        fread(&func, sizeof(Func), 1, arq);
    }
    fclose(arq);
    return 1;
}

int hash(char nome[10]){
    int total=0;
    for(int i=0;nome[i]!='\0';total+=(int)nome[i],i++){
    }
    return (total%TF);
}

int criarTab(List *list){
    FILE *arq = fopen("FUNCIONARIO.dat","rb");
    int pos = 0;
    if(arq == NULL)
        return 0;
    emptyList(list);

    while(1){
        Func func;
        fread(&func, sizeof(Func), 1, arq);
        if(feof(arq))
            break;

        int end = hash(func.depto);

        No *no = (No *) malloc(sizeof(No));
        no->posdado = pos;
        no->prox = list[end].head;

        list[end].head = no;

        strcpy(list[end].depto, func.depto);
        pos++;
    }
    fclose(arq);
    return 1;
}

void exibirTab(List *list){
    No *no;
    Func func;
    FILE *arq = fopen("FUNCIONARIO.dat", "rb");
    if(arq == NULL)
        printf("Arquico \"FUNCIONARIO.dat\" nao encontrado!\n");
    else{
        for(int i=0;i<TF;i++){
            if(list[i].head!=NULL){
                printf("%s\n", list[i].depto);

                no = list[i].head;

                while(no!=NULL){
                    fseek(arq,sizeof(Func)*no->posdado,SEEK_SET);
                    fread(&func,sizeof(Func),1,arq);
                    printf("\tNome: %s, Departamento: %s, Salario: R$%.2f, Status: %c\n",
                            func.nome, func.depto, func.sal, func.status);
                    no = no->prox;
                }
            }
        }
        fclose(arq);
    }
}

void destroy(List *list){
    No *no;
    No *p;
    for(int i=0;i<TF;i++){
        if(list[i].head!=NULL){
            no = list[i].head;

            while(no!=NULL){
                p=no;
                no = no->prox;
                free(p);
            }
        }
    }
}

void searchDepto(List *list){
    char depto[10];
    No *no;
    Func func;

    printf("\nQual Departamento voce quer consultar? ");
    scanf(" %[^\n]", depto);

    int end = hash(depto);

    if(list[end].head!=NULL){
        if(!strcmp(depto, list[end].depto)){
            FILE *arq = fopen("FUNCIONARIO.dat", "rb");
            if(arq==NULL)
                printf("Erro ao ler arquivo!\n");
            else{
                printf("%s\n", list[end].depto);

                no = list[end].head;

                while(no!=NULL){
                    fseek(arq,sizeof(Func)*(no->posdado),SEEK_SET);
                    fread(&func,sizeof(Func),1,arq);
                    printf("\tNome: %s, Departamento: %s, Salario: R$%.2f, Status: %c\n",
                            func.nome, func.depto, func.sal, func.status);
                    no = no->prox;
                }
            }
            fclose(arq);
        }
    }


}

int main(){
    int opc;
    List list[TF];

    emptyList(list);

    printf("Departamento - Hash\n\n");
    do{
        printf("\n---------------------------\n1-Add funcionario\n");
        printf("2-Exibir funcionario\n");
        printf("3-Criar tabela por Depto\n");
        printf("4-Exibir tabela Depto\n");
        printf("5-Consulta Depto\n");
        printf("0-Sair\n");

        printf("Entre com a opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                if(addFunc())
                    printf("\nFuncionario Adicionado com sucesso!\n");
                else
                    printf("\nErro ao adicioanr Funcionario!\n");
                break;
            case 2:
                if(!exibirFunc())
                    printf("\nErro ao exibir funcionario!\nO arquivo \"FUNCIONARIO.dat\" existe?\n");
                break;
            case 3:
                if(criarTab(list))
                    printf("\nTabela criada com sucesso!\n");
                else
                    printf("\nErro ao criar tabela!\nO arquivo \"FUNCIONARIO.dat\" existe?\n");
                break;
            case 4:
                exibirTab(list);
                break;
            case 5:
                searchDepto(list);
                break;
            case 0:
                printf("\nFechando programa!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
        }

    }while(opc!=0);

    destroy(list);

    return 0;
}
