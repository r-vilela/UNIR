#include <stdio.h>

int main(){
    int x,y;
    int *px = &x;

    *px = 14;
    y = *px;

    printf("y = %d\n", y);

    return 0;
}

