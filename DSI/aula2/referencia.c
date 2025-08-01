#include <stdio.h>

void Troca(int *a, int *b);

int main(){
    int num1, num2;
    num1=100;
    num2=50;
    Troca(&num1,&num2);

    printf("\n\n Eles agora valem %d %d \n", num1, num2);
    return 0;
}

void Troca(int *a, int *b){
    *a = *b+*a;
    *b = *a-*b;
    *a = *a-*b;
}
