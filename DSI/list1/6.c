#include <stdio.h>

int main(){

    int num, i=2;

    printf("Eu sei se um numero eh primo ou nao!!\n\n");

    printf("Se quiser me testar digite um numero: ");
    scanf("%d", &num);

    while(i<num){
        if(!(num%i++)){
            break;
        }
    }

    if(!(num-i)){
        printf("O numero %d eh primo!\n", num);
    }else{
        printf("O numero %d nao eh primo!\n", num);
    }

    return 0;
}
