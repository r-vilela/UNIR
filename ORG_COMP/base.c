#include <stdio.h>
#include <stdlib.h>

int main(){
    int opc=1, num, numOrg[10], numDest[10], i=0, baseDest = 0, baseOrg = 0;

    while(opc!=0){
        printf("======================================\n");
        printf("\tSistema de trocas de bases: \n\n");

        printf("1-Escolha a base de origem: %d\n", baseOrg);
        printf("2-Escolha a base desejada: %d\n", baseDest);
        printf("3-Fazer a conversao\n");
        printf("0-Para sair do Sistema\n\n");

        printf("Digite a opcao:");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Digite a base de origem: ");
                scanf("%d", &baseOrg);
                break;
            case 2:
                printf("Digite a base de destino: ");
                scanf("%d", &baseDest);
                break;
            case 3:
                printf("Digite o numero na base %d: ", baseOrg);
                scanf("%d", &num);
                printf("O numero %d na base %d eh: ", num, baseDest);
                if(baseOrg == 10){
                    while(num>=baseDest){
                        numDest[i++]=num%baseDest;
                        num = num/baseDest;
                    }
                    numDest[i]=num;
                    while(i>=0){
                        printf("%d", numDest[i--]);
                    }
                    printf("\n\n");
                }else{
                }
                break;
            default:
                printf("Opcao Invalida!\n");
                break;
        }





    }

    return 0;
}
