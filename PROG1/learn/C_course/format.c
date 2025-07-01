#include <stdio.h>

int main() {
    // Format Specifier = token that begin with a % symbol.
    //                    followe by a character that specifies the data type.
    //                    and optional modifiers(width, precision, flags).
    //                    Ther control how data is displayed or interpreted.

    // width precision flags

    int num1 = 1;
    int num2 = 10;
    int num3 = 100;
    int num4 = -100;

    printf("%4d\n", num1);//asign a minimal size
    printf("%-4d\n", num2);//justify it to the left
    printf("%06d\n", num3);//adds 0's to empty space
    printf("%+7d\n", num4);//display + for positive and - for negative

    float price1 = 19.99;
    float price2 = 1.50;
    float price3 = -100.00;

    printf("%.2f\n", price1);// set size after point
    printf("%7.2f\n", price2);// set minimuin character size
    printf("%+7.2f\n", price3);// display + or -

}
