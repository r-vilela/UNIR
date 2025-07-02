#include <stdio.h>
#include <string.h>

int main(){

    // Shopping Cart Program

    char product[17] = "";
    char currency = '$';
    float price = 0.0f;
    int qntt = 0;
    float total = 0.0f;

    printf("What item would you like to buy? ");
    fgets(product, sizeof(product), stdin);
    product[strlen(product) -1] = '\0';

    printf("What is the price for each? ");
    scanf(" %f", &price);

    printf("How many would you like to buy? ");
    scanf("%d", &qntt);

    total = price * qntt;

    printf("You have bought %d %s/s \n", qntt, product);

    printf("The total is: %c%.2f", currency, total);

}
