#include <stdio.h>

int EPar(int);

int main(){
    int num;
    printf("%p\n", &num);

    printf("Entre co um nmero: ");
    scanf("%d", &num);
    // passagem por valor -> eh criado uma copia na outra funcao
    if(EPar(num)){
        printf("\n\nO numero eh par\n");
    }else{
        printf("\n\nO numero eh impar\n");
    }

    return 0;
}

int EPar(int num){
    printf("%p\n", &num);
    return !(num%2);
}
