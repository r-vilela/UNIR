#include <stdio.h>

int main(){
    char str[20], cp[20];
    int i,j=0;

    printf("Verificarei se a frase eh um palindromo ignorando os espacos e pontuacoes!\n");
    printf("Entre sua frase: ");
    scanf("%[^\n]", &str);


    for(i=0;str[i]!='\0';i++){
        if(str[i]>=97&&str[i]<=122){
            cp[j++] = str[i];
        }
    }

    cp[j]='\0';

    for(i=0;i<j;i++){
        if(cp[i]!=cp[j-i-1]){
            i=-1;
            break;
        }
    }

    if(i==-1){
        printf("Nao eh um palindromo!\n");
    }else{
        printf("Eh um palindromo!\n");
    }

    return 0;
}
