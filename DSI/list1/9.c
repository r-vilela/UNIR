#include <stdio.h>

int main(){
    int matrix[3][3], i, j, total;

    printf("Sei fazer a media aritmatica de uma matrix.\n\n");
    printf("Se duvida tente a sorte!\n\n");


    for(i=0;i<sizeof(matrix)/4/3;i++){
        for(j=0;j<sizeof(matrix)/4/3;j++){
            printf("Digite o valor %d da linha %d: ",j+1,i+1);
            scanf("%d", &total);
            matrix[i][j] = total;
        }
    }

    for(i=0;i<sizeof(matrix)/4;i++){
        for(j=0;j<sizeof(matrix)/4;j++){
            printf("%d", matrix[i][j]);
            total+=matrix[i][j];
        }
    }

    printf("A media aritmetica da matrix eh %d\n", total/sizeof(matrix)/4);

    return 0;
}
