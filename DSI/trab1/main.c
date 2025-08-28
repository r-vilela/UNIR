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
    cntElem cnt[10];
    int opc=1, i, nCnt=0, list, list2, list3, sorted, nList=0;
    typeElem elem;
    system("clear");

    do{
        printf("-------------------------------------\n");
        printf("\tSequencial Static List\n\n");
        for(i=0;i<nList;i++){
            printf("%d - ", i);
            show(&(L[i]));
        }
        printf("\n");

        if(nCnt){
            printf("List Count- \n");
            showCount(cnt,nCnt);
            printf("\n");
        }

        printf("1-Create List\n");
        printf("2-Add Element to List\n");
        printf("3-Remove Element from List\n");
        printf("4-Is the list sorted?\n");
        printf("5-Copy list\n");
        printf("6-Copy unique values to list\n");
        printf("7-Invert list\n");
        printf("8-Combined sorted lists\n");
        printf("9-Count list\n");
        printf("10-Binary search\n");
        printf("0-To exit the system\n\n");

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

                }else{
                    printf("List 1 is empty!\n");
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
                            printf("List 2 is empty!\n");
                        }
                    }

                }else{
                    printf("List 1 is empty!\n");
                }
                break;
            case 7:
                printf("Select a list to invert: ");
                scanf("%d", &list);
                if(isList(list,nList)){
                    printf("Select a list to invert to: ");
                    scanf("%d", &list2);
                    system("clear");
                    if(isList(list2,nList)){
                        if(copyInvert(&(L[list]), &(L[list2]))){
                            printf("List inverted successfully!\n");
                        }else{
                            printf("List 2 is empty!\n");
                        }
                    }
                }else{
                    printf("List 1 is empty!\n");
                }
                break;
            case 8:
                printf("Select a list to combine: ");
                scanf("%d", &list);
                if(isList(list,nList)){
                    printf("Select a list to combine with: ");
                    scanf("%d", &list2);
                    if(isList(list2,nList)){
                        printf("Select a list to paste the combined list: ");
                        scanf("%d", &list3);
                        system("clear");
                        if(isList(list3,nList)){
                            if(cmbSorted(&(L[list]), &(L[list2]),&(L[list3]))){
                                printf("List combined successfully!\n");
                            }else{
                                printf("List 1 or 2 is empty!\n");
                            }
                        }
                    }
                }
                break;
            case 9:
                printf("Select a list count: ");
                scanf("%d", &list);
                system("clear");
                if(isList(list,nList)){
                    if(countList(&(L[list]),cnt, &nCnt)){
                        printf("Count List made successfully!\n");
                    }else{
                        printf("List 1 is empty!\n");
                    }
                }
                break;
            case 10:
                printf("Select a list: ");
                scanf("%d", &list);
                system("clear");
                if(isList(list,nList)){
                    printf("Enter the value to search: ");
                    scanf("%d", &elem.key);

                    i = binarySearch(&(L[list]), elem.key);
                    if(i==10){
                        printf("Value not found!\n");
                    }else if(i==0){
                        printf("Empty list!\n");
                    }else if(i<0){
                        printf("List not sorted!\n");
                    }else{
                        printf("Value found at %d!\n", i-1);
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
