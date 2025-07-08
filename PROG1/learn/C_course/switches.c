#include <stdio.h>

int main() {
    // switches = An alternative to using many if-else statements
    //          More efficient w/ fixed integer values

    char dayWeek = '\0';

    printf("Enter a day of the Week (M, T, W, H, F, S, U): ");
    scanf("%c", &dayWeek);

    switch (dayWeek) {
        case 'M':
            printf("It is Monday!\n");
            break;
        case 'T':
            printf("If is Tuesday!");
            break;
        case 'W':
            printf("If is Wednesday!");
            break;
        case 'H':
            printf("If is Thursday!");
            break;
        case 'F':
            printf("If is Friday!");
            break;
        case 'S':
            printf("If is Saturday!");
            break;
        case 'U':
            printf("If is Sunday!");
            break;
        default:
            printf("Please, enter a character (M, T, W, H, F, S, U)");
    }

    return 0;
}
