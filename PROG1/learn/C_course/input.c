#include <stdio.h>
#include <string.h>

int main() {

    int age = 0;
    float gpa = 0.0f;
    char grade = '\0';
    char name[12] = "";

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your gpa: ");
    scanf("%f", &gpa);

    printf("Enter your grade: ");
    scanf(" %c", &grade); // space to avoid the \n from the buffer

    getchar(); // get the value from the buffer
    printf("Enter your full name: ");
    fgets(name , sizeof(name), stdin);// get spaces from the input
    name[strlen(name) - 1] = '\0';// remove \n from the end

    printf("%s\n", name);
    printf("%d\n", age);
    printf("%.2f\n", gpa);
    printf("%c\n", grade);

    return 0;

}
