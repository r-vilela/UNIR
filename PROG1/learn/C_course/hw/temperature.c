#include <stdio.h>

int main(){
    char choice = '\0';
    float celsius = 0.0f;
    float fah = 0.0f;

    printf("Temperature Conversion Program\n");
    printf("C. Celsius to Fahrenheit.\n");
    printf("F. Fahrenheit to Celsius.\n");

    printf("Is the temperature in Celsius(C) or in Fahrenheit(F): ");
    scanf(" %c", &choice);

    if(choice == 'C'){
        printf("Enter the temperature in Celsius: ");
        scanf(" %f", &celsius);

        printf("%f\n", celsius);
        fah = (celsius * 9/5) + 32;
        printf("%f\n", fah);

        printf("%.1f Celsius is equals to %.1f Fahrenheit.\n", celsius, fah);
    }else if(choice == 'F'){
        printf("Enter the temperature in Fahrenheit: ");
        scanf(" %f", &fah);

        celsius = (fah - 32) * 5/9;

        printf("%.1f Fahrenheit is equals to %.1f Celsius.\n", fah, celsius);
    }else{
        printf("Value Invalid! Enter C or F.\n");
    }


}
