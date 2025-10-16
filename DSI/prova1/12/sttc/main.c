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
        printf("3-Is full?\n");
        printf("4-First\n");
        printf("5-Delete first\n");
        printf("6-Size\n");

        printf("\nEnter option: ");
        scanf("%d", &opt);

        system("clear");

        switch (opt) {
            case 1:
                printf("Enter a value to insert: ");
                scanf("%d", &v);
                if(insert(&F, v))
                    printf("Inserted successfully!\n\n");
                else
                    printf("List Full!\n\n");
                break;

            case 2:
                if(isEmpty(&F))
                    printf("The queue is Empty!\n\n");
                else
                    printf("The queue is not Empty!\n\n");
                break;

            case 3:
                if(isFull(&F))
                    printf("The queue is Full!\n\n");
                else
                    printf("The queue is not Full!\n\n");
                break;

            case 4:
                v = first(&F);
                if(v==-1)
                    printf("The queue is Empty!\n\n");
                else
                    printf("The first element of the queue is %d!\n\n",v);
                break;
            case 5:
                if(delete(&F)==0)
                    printf("The queue is Empty!\n\n");
                break;

            case 6:
                v = size(&F);

                if(v==0)
                    printf("The queue is Empty!\n\n");
                else
                    printf("The queue size is %d\n\n",v);
                break;

            case 0:
                printf("Shuting down!\n");
                break;

            default:
                printf("Invalid Option!\n");
                break;
        }
    }while(opt!=0);

    return 1;
}
