#include <stdio.h>

int main(){
    // PONTEIROS armazena endereco de memoria
    // * -> faz referencia ao ponteiro utilizando  biblioteca stdlib.h

    //int idade;
    //int *p; // armazena o endereco de memoria
    //int **q; // armazena o endereco de memoria

    //p=&idade; // armazena o endereco de idade
    //q=&p; // armazenar o endereco de p

    // q == endereco de p
    // &q == endereco de q
    // *q == conteudo de p
    // **q == conteudo do endereco de p

    int i,j,k;

    printf("Endreco de i = %p\n", &i);
    printf("Endreco de j = %p\n", &j);
    printf("Endreco de k = %p\n", &k);

    return 0;

}
