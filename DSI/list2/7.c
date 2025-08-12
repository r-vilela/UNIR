#include <stdio.h>
#include <stdlib.h>
/*
 * Crie um programa que declare uma estrutura (registro) para o cadastro de alunos.
 * - Deverão ser armazenados, para cada aluno: matrícula, sobrenome (apenas um) e ano do  nascimento.
 * - Ao início do programa, o usuário deverá informar o número de alunos que serão  armazenados.
 * - O programa deverá alocar dinamicamente a quantidade necessária de memória para  armazenar os registros dos alunos.
 * - O programa deverá pedir ao usuário que entre com as informações dos alunos.
 * - Ao final, mostrar os dados armazenados e liberar a memória alocada.
 */

typedef struct{
    char matricula[5];
    char sobrenome[15];
    int anoNasc;
}registro;

int main(){
    registro *alunos;
    int qnt, i;

    printf("------ Sistema de cadastro de alunos ------\n\n");

    printf("Quantos alunos deseja cadastras? ");
    scanf("%d", &qnt);

    alunos = (registro *)malloc(qnt*sizeof(registro));

    printf("\nRegistrar alunos:\n");
    for(i=0;i<qnt;i++){
        printf("\nMatricula(5): ");

        scanf("%s", &alunos[i].matricula);

        printf("Sobrenome(15): ");
        scanf("%s", &alunos[i].sobrenome);

        printf("Ano de nascimento: ");
        scanf("%d", &alunos[i].anoNasc);

    }

    printf("\nAlunos cadastrados com sucesso!!!\n");

    for(i=0;i<qnt;i++){
        printf("Matricula: %s", alunos[i].matricula);

        printf("\tSobrenome: %s", alunos[i].sobrenome);

        printf("\tAno de nascimento: %d\n", alunos[i].anoNasc);

    }

    free(alunos);

    return 0;
}
