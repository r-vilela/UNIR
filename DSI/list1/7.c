#include <stdio.h>
#include <string.h>

int main(){

    int i;
    char str[20] = "";

    printf("Eu reconheco qualquer palindromo!!\n");
    printf("Duvida?! Tente a sorte entao.\n");

    printf("Digite palavra: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';

    for(i=0; i>strlen(str), i++){
        if(i-(strlen(str)-1)){
            printf("Nao eh um palindromo!\n");
            break;
        }
    }

    printf("Aqui esta a palavra %s", str);

    return 0;
}
