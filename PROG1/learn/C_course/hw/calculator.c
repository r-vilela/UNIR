#include <stdio.h>

int main()
{

    // CALCULATOR PROGRAM

    double num1 = 0.0f;
    double num2 = 0.0f;
    char operator = '\0';
    double result = 0.0f;

    printf("Enter the first number: ");
    scanf("%lf", &num1);

    printf("\nEnter the operator (+ - * /): ");
    scanf(" %c", &operator);

    printf("\nEnter the second number: ");
    scanf("%lf", &num2);

    switch (operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if(num2 == 0){
                printf("You cannot divide a number by 0!\n");
            }else{
                result = num1 / num2;
            }
            break;
        default:
            printf("Pease, enter + for adition, - for subtraction, * for multiplication or / for division.\n");
    }

    printf("\nResult: %.3lf", result);

    return 0;
}
