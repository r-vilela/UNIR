#define TF 1000000 // Tamanho Fisico do vetor
#define MAX 999 // Valor MAXimo para um numero
                // Tamanho Logico usado na ordenacao para guardar as posicoes ocupadas

#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void cria(int vetor[TF]){
    int i;
    for(i=0;i<TF;i++){
        vetor[i]=rand()%MAX;
    }
}

void exibe(int vetor[TF]){
    int i;
    for(i=0;i<TF;i++){
        printf("vetor[%d]: %d\n", i, vetor[i]);
    }
}

int buscaExaustiva(int vetor[TF], int numprocurado){
    int i=-1;
    for(i=0;i<TF&&numprocurado!=vetor[i];i++);
    if(i<TF)return i;
    return -1;
}

int buscaSequencial(int vetor[TF], int numprocurado){
    int i=-1;
    for(i=0;i<TF&&numprocurado>vetor[i];i++);
    return i;
}

void ordena(int vetor[TF]){
    int fim, i, aux;
    for(fim=TF-1;fim>0;fim--){
        for(i=0;i<fim;i++){
            if(vetor[i]>vetor[i+1]){
                aux = vetor[i];
                vetor[i]=vetor[i+1];
                vetor[i+1]=aux;
            }
        }
    }
}
int buscaBinaria(int vetor[TF], int numprocurado){
    int meio, inicio, fim;

    for(inicio=0, fim=TF;inicio<TF&&vetor[meio]!=numprocurado; ){
        meio=(inicio+fim)/2;

        if(vetor[meio]<numprocurado){
            inicio = meio+1;
        }else if(vetor[meio]>numprocurado){
            fim = meio-1;
        }
    }

    return meio;
}

int main(){
    int opcao=0, posicao=-1, numprocurado;
    int vetor[TF];
    bool ordenado = false;

    while(opcao != 8){
        printf("\n\n1-Criar vetor");
        printf("\n2-Exibir vetor");
        printf("\n3-Ordena o vetor");
        printf("\n4-Busca Exaustiva - vetor desordenado");
        printf("\n5-Busca Sequencial - vetor ordenado");
        printf("\n6-Busca Binaria - vetor ordenado");

        printf("\nEntre c/ a opcao:");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                srand(time(NULL));
                cria(vetor);
                ordenado = false;
                printf("\n\nVetor gerado %d!", TF);
                break;
            case 2:
                exibe(vetor);
                break;
            case 3:
                ordena(vetor);
                ordenado=true;
                printf("\nVetor ordenado!");
                break;
            case 4:
                printf("Entre c/ um numero:");
                scanf("%d", &numprocurado);
                posicao = buscaExaustiva(vetor, numprocurado);
                if(posicao==-1){
                    printf("Valor %d nao encontrado no vetor!", numprocurado);
                }else{
                    printf("Numero encontrado na posicao %d", posicao);
                }
                break;
            case 5:
                if(ordenado){
                    printf("Entre c/ um numero:");
                    scanf("%d", &numprocurado);
                    posicao = buscaSequencial(vetor, numprocurado);
                    if(vetor[posicao]==numprocurado&&posicao<TF){
                        printf("Numero encontrado na posicao %d", posicao);
                    }else{
                        printf("O velor deveria ser adicionado na posicao %d!", posicao);
                    }
                }else{
                    printf("Vetor nao ordenado!");
                }
                break;
            case 6:
                if(ordenado){
                    printf("Entre c/ um numero:");
                    scanf("%d", &numprocurado);
                    posicao = buscaBinaria(vetor, numprocurado);
                    if(vetor[posicao]==numprocurado&&posicao<TF){
                        printf("Numero encontrado na posicao %d", posicao);
                    }else{
                        printf("O velor deveria ser adicionado na posicao %d!", posicao);
                    }
                }else{
                    printf("Vetor nao ordenado!");
                }
                break;
        }

    }


    return 0;
}
