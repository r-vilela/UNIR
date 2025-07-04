#include <stdio.h>

int main(){

    // WEIGHT CONVERTER PROGRAM

    int choice = 0;
    float weight = 0.0f;
    float total = 0.0f;
    float converter = 0.0f;

    printf("Weight Conversion Calculator.\n");
    printf("1. Kilograms to Pounds\n");
    printf("2.Pounds to Kilograms\n");

    printf("Enter your choice(1 or 2): ");
    scanf("%d", &choice);

    if(choice == 1){
        converter = 2.204623;

        printf("Enter the weight in Kilograms: ");
        scanf("%f", &weight);

        total = weight * converter;

        printf("%.2f kilograms is equals to to %.2f pounds\n", weight, total);
    }else if(choice == 2){
        converter = 0.4535924;

        printf("Enter the weight in Pounds: ");
        scanf("%f", &weight);

        total = weight * converter;

        printf("%.2f pounds is equals to to %.2f kilograms\n", weight, total);
    }else{
        printf("Invalid choice! Please enter 1, or 2");

    }
}
