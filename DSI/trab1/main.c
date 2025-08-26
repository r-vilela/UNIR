#include <stdio.h>
#include <stdlib.h>

#include "static.h"

#define TM 4

int isList(int list, int nList){
    if(list<nList)
        return 1;
    printf("Not a valid List\n");
    return 0;
}

int main(){
    list L[TM];
    int opc=1, i, list, list2, list3, sorted, nList=0;
    typeElem elem;
    system("clear");

    do{
        printf("------------------------------\n");
        printf("\tSequencial Static List\n\n");
        for(i=0;i<nList;i++){
            printf("%d - ", i);
            show(&(L[i]));
        }

        printf("1-Create List\n");
        printf("2-Add Element to List\n");
        printf("3-Remove Element from List\n");
        printf("4-Is the list sorted?\n");
        printf("5-Copy list\n");
        printf("6-Copy unique values to list\n\n");

        printf("Enter a value:");
        scanf("%d", &opc);


        switch (opc) {
            case 1:
                if(nList<TM){
                    create(&(L[nList]));
                    nList++;
                    system("clear");
                }else{
                    system("clear");
                    printf("Maximun list limit reached!\n");
                }
                break;
            case 2:
                printf("Select a list: ");
                scanf("%d", &list);
                system("clear");
                if(isList(list,nList)){
                    printf("Enter the new value: ");
                    scanf("%d", &elem.key);

                    add(&(L[list]), elem);
                }
                break;
            case 3:
                printf("Select a list: ");
                scanf("%d", &list);
                system("clear");
                if(isList(list,nList)){
                    printf("Enter the value to be removed: ");
                    scanf("%d", &elem.key);

                    rmv(&(L[list]), elem);
                }
                break;
            case 4:
                printf("Select a list: ");
                scanf("%d", &list);
                system("clear");
                if(isList(list,nList)){
                    sorted = isSorted(&(L[list]));
                    if(sorted<0){
                        printf("List Sorted (Discending)\n");
                    }else if(sorted>0){
                        printf("List Sorted (Ascending)\n");
                    }else{
                        printf("Not sorted!\n");
                    }

                }
                break;
            case 5:
                printf("Select a list to copy: ");
                scanf("%d", &list);
                if(isList(list,nList)){
                    printf("Select a list to copy to: ");
                    scanf("%d", &list2);
                    system("clear");
                    if(isList(list2,nList)){
                        if(copy(&(L[list]), &(L[list2]))){
                            printf("Copied successfully!\n");
                        }else{
                            printf("List 1 is empty!\n");
                        }
                    }

                }
                break;
            case 6:
                printf("Select a list to copy: ");
                scanf("%d", &list);
                if(isList(list,nList)){
                    printf("Select a list to copy to: ");
                    scanf("%d", &list2);
                    system("clear");
                    if(isList(list2,nList)){
                        if(copyUnique(&(L[list]), &(L[list2]))){
                            printf("Copied successfully!\n");
                        }else{
                            printf("List 1 is empty!\n");
                        }
                    }

                }
                break;
            case 0:
                system("clear");
                printf("Ending Program . . .\n");
            default:
                system("clear");
                printf("Invalid Option!\n");
        }

    }
    while (opc!=0);


    return 0;
}
