#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    list l;
    int opc, a, resp;
    create(&l);

    do{
        printf("\n-----------------------------\n");
        printf("Lista:\n");
        show(&l);

        printf("\n\n1-Insert\n");
        printf("2-Delete\n");
        printf("3-Search\n");
        printf("4-Sentinel Search\n");

        printf("\nEnter a option:");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Enter a value insert: ");
                scanf("%d", &a);
                printf("\n");
                resp = insert(&l, a);
                if(resp==1)
                    printf("Added successfully!\n");
                else if(resp==-1)
                    printf("List is full!\n");
                else
                    printf("Value already on the list!\n");
                break;
            case 2:
                printf("Enter a value delete: ");
                scanf("%d", &a);
                printf("\n");
                resp = delete(&l, a);
                if(resp==1)
                    printf("Deleted successfully!\n");
                else if(resp==-1)
                    printf("List is empty!\n");
                else
                    printf("Value not found on the list!\n");
                break;
            case 3:
                printf("Enter a value to be searched: ");
                scanf("%d", &a);
                printf("\n");
                resp = search(&l, a);
                if(resp==-1)
                    printf("List is empty!\n");
                else if(resp==0)
                    printf("Value not found on the list!\n");
                else
                    printf("Value %d found at position %d!\n", a, resp);
                break;
            case 4:
                printf("Enter a value to be searched: ");
                scanf("%d", &a);
                printf("\n");
                resp = searchSent(&l, a);
                if(resp==-1)
                    printf("List is empty!\n");
                else if(resp==0)
                    printf("Value not found on the list!\n");
                else
                    printf("Value %d found at position %d!\n", a, resp);
                break;
            case 0:
                printf("Closing System!\n");
                break;
            default:
                printf("Invalid Option!\n");
        }

    }while(opc!=0);

    return 1;
}
