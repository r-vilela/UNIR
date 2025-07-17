#include <stdio.h>
#include <stdbool.h>

double cube(double num){
    return num * num * num;
}

double square(double num){
    return num * num;
}

bool ageCheck(int age){
    if(age >= 18){
        return true;
    }else{
        return false;
    }
}

int getMax(int x, int y){
    if(x > y){
        return x;
    }else if(x < y){
        return y;
    }else{
        return x;
    }
}

int main (){

    // Return = return a value back to where you call a function

    double x = cube(2);
    double y = cube(3);
    double z = cube(4);

    printf("%lf\n", x);
    printf("%lf\n", y);
    printf("%lf\n", z);

    int age = 18;

    if(ageCheck(age)){
        printf("You may sign up!\n");
    }else{
        printf("You must be 18 or older to sign up!\n");
    }

    int num1 = 1;
    int num2 = 0;

    printf("%d\n", getMax(num1, num2));

    return 0;
}
