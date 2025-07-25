#include <stdio.h>

int main(){

    float nota, total;

    printf("Sera se vc passou?\nVamos descobrir!\n\n\n");

    printf("Digite a nota do primeiro bimestre: ");
    scanf("%f", &nota);

    total+=nota;

    printf("Digite a nota do segundo bimestre: ");
    scanf("%f", &nota);

    total+=nota;

    printf("Digite a nota do terceiro bimestre: ");
    scanf("%f", &nota);

    total+=nota;

    printf("\nVoce ficou com %.2f na media!\n", total/3);
    if(total/3<6){
        printf("Ai que burro! Da zero para ele!!!\n");
    }else{
        printf("Parabens! Voce passou!!");
    }

    return 0;
}
