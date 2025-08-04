#include <stdio.h>

void exibir(char str[40], int ini, int fin){

    for( ;ini<fin; ini++){
        printf("%c", str[ini]);
    }
    printf("\n");
}

int main(){
    char str[40];
    int i, f;

    printf("Escreva uma frase, que eu retornarei apenas as palavras com mais de 5 letras\n");

    printf("Escreva a frase: ");
    scanf("%[^\n]", &str);

    for(i=0, f=0; ;f++){
        if(str[f]=='\0'){
            exibir(str,i,f);
            break;
        }
        if(str[f]==' '){
            if(f-i>=5){
                exibir(str,i,f);
            }
            i=f+1;
        }
    }
}
