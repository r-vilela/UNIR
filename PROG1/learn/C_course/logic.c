#include <stdio.h>
#include <stdbool.h>

int main(){
    // LOGICAL OPERATORS =  Used to combine or modify boolean expressions.

    // && = AND
    // || = OR
    // ! = NOT

    int temp = 31;

    if(temp <= 0 || temp >= 30){
        printf("The temperature is BAD\n");
    //}else if(temp > 30){
        //printf("The temperature is HOT\n");
    }else{
        printf("The temperature is GOOD\n");
    }

    printf("\n\n\n");

    bool isSunny = true;

    if(!isSunny){
        printf("It is cloudy outside");
    }else{
        printf("Is is sunny outside");
    }

    return 0;
}
