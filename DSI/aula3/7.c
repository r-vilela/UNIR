#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char matricula[10];
    char sobrenome[50];
    int ano;
}aluno;

int main(){
    aluno *a;
    int num,i;

    printf("Cadastro de alunos\n");
    printf("-------------------\n\n");

    printf("Digite o numero de alunos a serem cadastrados: ");
    scanf("%d", &num);

    a = (aluno *)malloc(num*sizeof(aluno));

    for(i=0;i<num;i++){
        printf("--------------------------------------------\n");
        printf("Matricula: ");
        scanf("%s",&a[i].matricula);
        printf("Sobrenome: ");
        scanf("%s",&a[i].sobrenome);
        printf("Ano: ");
        scanf("%d",&a[i].ano);
    }

    printf("\n\n\nLista dos alunos:\n");
    for(i=0;i<num;i++){
        printf("Matricula = %s\t", a[i].matricula);
        printf("Sobrenome = %s\t", a[i].sobrenome);
        printf("Ano = %d\t", a[i].ano);
        printf("\n");
    }

    free(a);
    return 0;
}
