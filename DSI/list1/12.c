#include <stdio.h>

int strleng(char str[]){
    int i;

    for(i=0;str[i]!='\0';i++);

    return i;
}

int main(){
    char str[40];
    int qnt, i;

    printf("CONTADOR DE VOGAIS\n\n");
    printf("Escreva uma frase que eu contarei as vogais: ");
    scanf("%[^\n]", str);

    for(i=0;i<strleng(str);i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            qnt++;
        }
    }

    printf("Nessa frase tem %d vogais!\n", qnt);

    return 0;
}
