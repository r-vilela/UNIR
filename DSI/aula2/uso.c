#include <stdio.h>

int main(){
    int x=4, y=7;
    int *px, *py;

    printf("&x = %p\t x = %d\n", &x, x);
    printf("&y = %p\t y = %d\n", &y, y);

    px = &x;
    py = &y;

    printf("\n\n&px = %p\t x = %d\n", px, *px);
    printf("&py = %p\t y = %d\n", py, *py);

    return 0;
}
