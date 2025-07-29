#include <stdio.h>
#include <string.h>

int isPalindromo(char str[20]){
    int i;
    for(i=0;i<strlen(str); i++){
        if(!(str[i]-str[strlen(str)-i])){
            return 0;
        }
    }
    return 1;

}

int main(){

    char str[20] = "";

    printf("Eu reconheco qualquer palindromo!!\n");
    printf("Duvida?! Tente a sorte entao.\n");

    printf("Digite uma palavra: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';


    if(isPalindromo(str)){
        printf("Eh um palindromo!\n");
    }else{
        printf("Nao eh um palindromo!\n");
    }
    return 0;
}
