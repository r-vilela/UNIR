#include <stdio.h>

int main(){

    int num, i;

    printf("Tabuada de 1 a 10\n\n\n");

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("\n\nTabuada do %d\n", num);
    for(i=1;i<=10;i++){
        printf("%d X %d = %d\n", i, num, i*num);
    }

    return 0;
}
