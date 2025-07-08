#include <stdio.h>
#include <stdbool.h>

int main(){

    float price = 10.0;
    bool isStudent = false;
    bool isSenior = false;

    if(isStudent){
        if(isSenior){
            printf("Get a Student discount of 20%\n");
            printf("Get a Student discount of 10%\n");
            price = price  - price * 0.3;
        } else {
            printf("Get a Student discount of 10%\n");
            price = price  - price * 0.1;
        }
    }else if(isSenior){
        printf("Get a Student discount of 20%\n");
        price = price - price * 0.2;
    }else{
        printf("You get no discount!");
    }

    printf("The price of a ticket is: $%.2f\n", price);

    return 0;
}
