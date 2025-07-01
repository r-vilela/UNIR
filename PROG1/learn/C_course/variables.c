#include <stdio.h>
#include <stdbool.h>

int main() {
    // variables = reusable container for a variable.
    //
    // int = whole numbers (4 bytes in moderm systems)
    // float = single-precision decimar numbers (4 bytes)
    // double = double-precision decimal numbers (8 bytes)
    // char = single character (1 byte)
    // char[] = array of characters (size varies)
    // bool =  true or false (1 byte, requires <stdbool.h>)

    char name[] = "Zetsu";
    char team = 'B';
    int teamSize = 4;
    float time = 32.123;
    double pi = 3.141534234;
    bool pass = false;

    printf("Hello, %s, ", name);
    printf("and welcome to team %c.\n", team);
    printf("Now it fullfilled the need to have %d players.\n", teamSize);
    printf("Your discovered pi, %f", pi);
    printf(", in %f seconds. Congratulations.\n", time);

    if(pass){
        printf("Fortunate, everyone passed to the second test.\n");
    }else{
        printf("Unfortunate, you couldn't pass this time, googd luck on the next one.\n");
    }

    return 0;
}
