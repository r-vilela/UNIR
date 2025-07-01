#include <stdio.h>
#include <stdbool.h>

int main(){

    // minute 35:05

    bool isOnline = true;
    bool isStudent = false;
    bool forSale = true;

    if(forSale){
        printf("This item is for sale.\n");
    }else{
        printf("This item is not for sale.\n");
    }
    printf("%d\n", isOnline);

    return 0;
}
