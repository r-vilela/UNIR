#include <stdio.h>

int main(){
    int i=0, total=0;
    char str[20];

    printf("PROGRAMADOR - Contador de 'e'\n");

    printf("\n\nEscreva uma frase e eu contarei qntos e aparecem: ");
    scanf("%[^\n]", &str);

    while(str[i]!='\0'){
        if(str[i++]=='e'){
            total++;
        }
    }

    printf("O total de 'e' nessa frase sao %d\n", total);

    return 0;
}
