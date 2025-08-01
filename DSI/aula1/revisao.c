#include <stdio.h>

int main(){
    int a,b,c;

    //scanf("%d", &a);
    // Caso a entrada seja 23.4 ele vai pegar apenas o que eh interessante a variavel sendo o 23

    //printf("%d \a elevado ao quadrado eh igual a %d\n",a,a*a);
    //printf("%d \a mais 3 eh igual a %d\n",a,a+3);

    // multiplas atribuicoes x=y=z=0
    b=c=a;

    //printf("%d\n", b);
    //printf("%d\n", c);

    // Modeladores (casts)

    int num;
    float f;

    num = 10;
    f = (float) num/7;
    printf("%f",f);

    return 0;
}
