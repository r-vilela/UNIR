#include <stdio.h>

int main(){
    int vetor[10], i, j, media;

    printf("EU AMO NUMEROS PARES! S2\n");
    printf("Digite 10 numeros que eu retornarei a media apenas dos numeros pares S2\n\n");

    for(i=0;i<10;i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for(i=0, j=0, media=0;i<10;i++){
        if(!(vetor[i]%2)){
            j++;
            media+=vetor[i];
        }
    }
    //printf("%d\n", media/j);

    if(media>0){
        printf("A media dos numeros pares eh igual a %.2f S2!", (float) media/j);
    }else{
        printf("Nao teve nenhum numero par T-T");

    }

    return 0;
}
