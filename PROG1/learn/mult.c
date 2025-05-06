#include <stdio.h>
#include <stdlib.h>

int multiply(int a, int b){
    int result = 0;

    while(b > 0){
        if(b & 1)
            result += a;
        a <<= 1;
        b >>= 1;

    }

    return result;
}

int main(){
    int a = 0b1101;
    int b = 0b101;

    printf("Digit 2 numbers: \n");
    //scanf("%d", &a);
    //scanf("%d", &b);

    int c = multiply(a, b);

    printf("a X b = %d", c);
}
