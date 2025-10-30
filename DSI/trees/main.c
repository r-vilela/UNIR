#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main(){
    Tree T;
    int opc, val;
    create(&T);

    do{
        printf("------------------------------\n");
        printf("\tBinary Tree\n");

        show(&T);

        printf("\n1-Add\n");
        printf("2-Remove\n");
        printf("3-Search\n");
        printf("0-Exit\n");

        printf("Enter the option: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Enter the new value: ");
                scanf("%d", &val);

                if(add(&T, val))
                    printf("Added successfuly!\n");
                else
                    printf("Failed to add!\n");
                break;
            case 2:
                printf("Enter the value to remove: ");
                scanf("%d", &val);

                if(rmv(&T, val))
                    printf("Remove successfuly!\n");
                else
                    printf("Failed to remove!\n");
                break;
            case 3:
                printf("Enter the value to search for: ");
                scanf("%d", &val);

                Node *n = search(&T, val);
                if(n==NULL)
                    printf("Value not found!\n");
                else
                    printf("Value %d found!\n", n->info);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Option!");
                break;
        }
    }while(opc!=0);
    destroy(&T);

    return 0;
}
