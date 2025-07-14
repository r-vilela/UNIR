#include <stdio.h>
#include <string.h>

void birthdaySong(char name[], int age){
    printf("Happy Birthday to you!\n");
    printf("Happy Birthday to you!\n");
    printf("Happy Birthday dear %s!\n", name);
    printf("Happy Birthday to you!\n");
    printf("You are %d years old\n\n", age);

}

int main(){
    // Functions = are a reusable section of code that can be invoked "called"
    //              Arguments can be sent to a function so that it can use them

    char name[50] = "";
    int age = 0;

    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("\n");

    birthdaySong(name, age);


    return 0;
}
