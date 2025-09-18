#include "pdinamica.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * PILHA - First In Last Out (FILO)
 *
 * Estatica Sequencial: final
 * Escadeada Dinamica: Inicio
 */

int main(){
    Pilha p;
    criar(&p);
    tipo_elem c;
    int opc;

    printf("Estrura de Dados Pilha - FILO\n");

    do{

        scanf(" %c", &c);
        switch (c) {
            case 0x0d:
                printf("SAIR\n");
                return 0;
            case '#':
                popup(&p);
                break;
            case '@':
                esvaziar(&p);
                break;
            default:
                if(!push(&p, c)){
                    printf("Erro\n");
                    return 0;
                }
        }
        system("clear");
        exibir(&p);
    }while(1);



    return 0;
}
