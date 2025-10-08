#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){
    List L1, L2, L3;
    create(&L1);
    create(&L2);
    create(&L3);
    List lists[] = {L1,L2,L3};
    int opc, value, list1, list2, list3;

    do{
        printf("==========================\n");
        for(int l=0;l<3;l++){
            printf("List %d\n", l+1);
            show(&(lists[l]));
        }
        printf("\n1-Add\n");
        printf("2-Copy\n");

        printf("\nEnter an option: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                printf("Select a list: ");
                scanf("%d", &list1);
                add(&(lists[list1-1]), value);
                break;
            case 2:
                printf("Select a list to copy from: ");
                scanf("%d", &list1);
                printf("Select a list to copy to: ");
                scanf("%d", &list2);
                cp(&(lists[list1-1]), &(lists[list2-1]));
                break;
            case 0:
                printf("Shuting down!\n");
                break;
            default:
                printf("Invalid Option!\n");
                break;
        }

    }while (opc!=0);

    destroy(&L1);
    destroy(&L2);
    destroy(&L3);
    return 0;
}
