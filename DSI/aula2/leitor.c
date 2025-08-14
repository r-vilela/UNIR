#include <stdio.h>

int main(){
    int num[100];
    int count=0;
    int totalnums;

    do{
        printf("\n Entre com um numero (-999 p/ terminar): \n");
        scanf("%d", &num[count]);
        count++;
    }while(num[count-1] != -999);

    totalnums = count-1;
    printf("\n\n\nOs numeros que voce digitou foream: \n\n");

    for(count=0;count<totalnums;count++){
        printf(" %d", num[count]);
    }

    return 0;
}
