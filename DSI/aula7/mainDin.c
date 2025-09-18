#include "pdinamica.h"
#include <stdio.h>
#include <stdlib.h>


/*
 * PILHA - First In Last Out (FILO)
 *
 * Estatica Sequencial: final
 * Escadeada Dinamica: Inicio
 */

int editor(){
    Pilha p;
    criar(&p);
    tipo_elem c;
    int opc;

    printf("Estrura de Dados Pilha Dinamica - FILO\n");

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
        printf("# - para apagar\t@ - para limpar tudo\n");
        printf("-----------------------------------------------------------\n");
        if(!vazia(&p))
            exibir(&p);

    }while(1);

    return 0;
}

int main(){
    int opc;

    do{
        printf("1-Editor de Texto\n");
        printf("2-Palindromo\n");

        scanf("%d", &opc);
        system("clear");
        switch (opc) {
            case 1:
                editor();
                break;
            case 2:
                printf("Palindromo\n");
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(opc!=0);
    return 0;
}
