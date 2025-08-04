#include <stdio.h>

int main(){
    char nome[20];
    float nota1, nota2, nota3;
    FILE *arq = fopen("notas.txt", "r");
    if(arq==NULL){
        printf("Erro: Nao foi possivel abrir o arquivo!\n");
    }else{
        while(!feof(arq)){
            fscanf(arq, "%s %f %f %f\n",nome,&nota1,&nota2,&nota3 );
            float media = (nota1+nota2+nota3)/3;
            printf("%s obteve media de %.2f\n", nome, media);
        }
        fclose(arq);
    }
    return 0;
}
