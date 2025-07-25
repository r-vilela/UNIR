#include <stdio.h>

int main(){

    int num;

    printf("Eh IMPAR ou PAR? \nEU VOU ADIVINHAR!!!\n\n\n");

    printf("Digite um numero: ");
    scanf("%d", &num);

    if(num%2){
        printf("O numero eh impar!\n");
    }else{
        printf("O numero eh par!\n");
    }

    printf("HaHa! Facil!!!");

    return 0;
}
