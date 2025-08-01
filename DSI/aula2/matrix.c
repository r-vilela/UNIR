#include <stdio.h>
#define TAMANHO 5

float media( float lista[], int tamanho){
    int i;
    float m=0.0;
    for(i=0;i<tamanho;i++) m += *(lista++);

    lista = lista - i;
    printf("\nAs notas sao: ");
    for(i=0;i<tamanho;i++){
        printf("%.2f ", *(lista++));
    }
    return m/tamanho;
}

int main(){
    float notas[TAMANHO]={5.4,7.6,9.8}, m;
    int i=3;

    //do{
        //printf("Digite a nota do aluno %d ", i+1);
        //scanf("%f", notas + i);
    //}while (*(notas + i++) >= 0.0);

    m = media(notas, i);

    printf("\n\nMedia das notas:  %2.f", m);

    return 0;
}

