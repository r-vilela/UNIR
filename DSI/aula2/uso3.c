#include <stdio.h>

int main(){
    unsigned int x=5, y=6;
    unsigned int *px, *py;

    px = &x;
    py = &y;

    if(px < py){
        printf("py-px= %u\n", (py-px));
    }else{
        printf("px-py= %u\n", (px-py));
    }

    printf("\n\npx = %p, ", px);
    printf("*px = %d, ", *px);
    printf("&px = %p", &px);

    printf("\n\npy = %p, ", py);
    printf("*py = %d, ", *py);
    printf("&py = %p", &py);

    py++;
    px++;

    printf("\n\n\n\npx = %p, ", px);
    printf("*px = %d, ", *px);
    printf("&px = %p", &px);

    printf("\n\npy = %p, ", py);
    printf("*py = %d, ", *py);
    printf("&py = %p", &py);

    return 0;
}
