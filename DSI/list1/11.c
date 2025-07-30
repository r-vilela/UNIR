#include <stdio.h>
#include <string.h>

int main(){
    int i, size;
    char str[40];

    printf("Ola! Escreva uma frase com ate 40 caracteres.\n");
    printf("\bATENCAO!! Eh proibido escrever \"casa\". EU SABEREI!\n");

    printf("Escreva sua frase: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) -1] = '\0';

    size = strlen(str)-3;

    if(size>=4){
        for(i=0;i<size&&!(str[i]=='c'&&str[i+1]=='a'&&str[i+2]=='s'&&str[i+3]=='a');i++);
    }

    printf("\nVoce escreveu: %s\nE...\n\n", str);

    if(i==size){
        printf("Nao tem \"casa\" escrito!\n");
    }else{
        printf("Tem \"casa\" escrito!\n MALDITU SEJAA!!!!");
    }

    return 0;
}
