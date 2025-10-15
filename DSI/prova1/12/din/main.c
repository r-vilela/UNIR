#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main(){
    Fila F;
    int opt, v;
    create(&F);

    do{
        printf("Fila: \n");
        show(&F);

        printf("\n1-Insert\n");
        printf("2-Is empty?\n");
        printf("3-First\n");
        printf("4-Delete first\n");

        printf("\nEnter option: ");
        scanf("%d", &opt);

        system("clear");

        switch (opt) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &v);
                insert(&F, v);
                printf("Inserted successfully!\n\n");
                break;

            case 2:
                if(isEmpty(&F))
                    printf("The queue is Empty!\n\n");
                else
                    printf("The queue is not Empty!\n\n");
                break;

            case 3:
                v = first(&F);
                if(v==-1)
                    printf("The queue is Empty!\n\n");
                else
                    printf("The first element of the queue is %d!\n\n",v);
                break;

            case 4:
                if(delete(&F)==0)
                    printf("The queue is Empty!\n\n");
                break;

            case 0:
                printf("Shuting down!\n");
                break;

            default:
                printf("Invalid Option!\n");
                break;
        }
    }while(opt!=0);

    destroy(&F);
    return 1;
}
