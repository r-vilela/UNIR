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
        printf("2-Add end\n");
        printf("3-Copy\n");
        printf("4-Copy unique\n");
        printf("5-Join Sorted\n");
        printf("7-Invert\n");
        printf("8-Is Sorted?\n");

        printf("\nEnter an option: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc){
            case 1:
                printf("Enter a value: ");
                scanf("%d", &value);
                printf("Select a list: ");
                scanf("%d", &list1);
                add(&(lists[list1-1]), value);
                break;
            case 2:
                printf("Enter a value: ");
                scanf("%d", &value);
                printf("Select a list: ");
                scanf("%d", &list1);
                addEnd(&(lists[list1-1]), value);
                break;
            case 3:
                printf("Select a list to copy from: ");
                scanf("%d", &list1);
                printf("Select a list to copy to: ");
                scanf("%d", &list2);
                cp(&(lists[list1-1]), &(lists[list2-1]));
                break;
            case 4:
                printf("Select a list to copy from: ");
                scanf("%d", &list1);
                printf("Select a list to copy to: ");
                scanf("%d", &list2);
                cpUnique(&(lists[list1-1]), &(lists[list2-1]));
                break;
            case 5:
                printf("Select a list to copy from: ");
                scanf("%d", &list1);
                printf("Select a list to copy to: ");
                scanf("%d", &list2);
                printf("Select a list to copy to: ");
                scanf("%d", &list3);
                joinSort(&(lists[list1-1]), &(lists[list2-1]), &(lists[list3-1]));
                break;
            case 7:
                printf("Select a list to invert from: ");
                scanf("%d", &list1);
                printf("Select a list to invert to: ");
                scanf("%d", &list2);
                invert(&(lists[list1-1]), &(lists[list2-1]));
                break;
            case 8:
                printf("Select a list to invert from: ");
                scanf("%d", &list1);
                int sort = isSort(&(lists[list1-1]));
                if(sort==1)
                    printf("Increasingly Ordered!\n");
                else if(sort==-1)
                    printf("Decreasingly Ordered!\n");
                else
                    printf("Not ordered!\n");
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
