#include <stdio.h>

int main(){
    int vetor[5],i,hgh=0,secHgh=0;

    printf("Digite as notas do seus alunos, que eu direi qual foi a segunda maior nota!\n\n");

    printf("Notas:\n");
    for(i=0;i<5;i++){
        printf("\tAluno %d:",i+1);
        scanf("%d", &vetor[i]);
    }

    for(i=0;i<5;i++){
        if(vetor[i]>hgh){
            secHgh=hgh;
            hgh=vetor[i];
        }else if(vetor[i]<hgh&&vetor[i]>secHgh){
            secHgh=vetor[i];
        }
    }

    printf("O segundo maior valor do velor eh %d\n", secHgh);

}
