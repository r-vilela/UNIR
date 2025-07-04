#include <stdio.h>
#include <string.h>

int main(){

    // MAD LIBS GAME

    char zooAdj[15] = "";
    char noun[15] = "";
    char nounAdj[15] = "";
    char verb[15] = "";
    char myAdj[15] = "";

    printf("Enter an adjective (description): ");
    fgets(zooAdj, sizeof(zooAdj), stdin);
    zooAdj[strlen(zooAdj) - 1] = '\0';

    printf("Enter a noun (animal or person): ");
    fgets(noun, sizeof(noun), stdin);
    noun[strlen(noun) - 1] = '\0';

    printf("Enter an adjective (description): ");
    fgets(nounAdj, sizeof(nounAdj), stdin);
    nounAdj[strlen(nounAdj) - 1] = '\0';

    printf("Enter a verb (ending w/ -ing): ");
    fgets(verb, sizeof(verb), stdin);
    verb[strlen(verb) - 1] = '\0';

    printf("Enter an Adjective (description): ");
    fgets(myAdj, sizeof(myAdj), stdin);
    myAdj[strlen(myAdj) - 1] = '\0';

    printf("\nToday I went to a %s zoo.\n", zooAdj);
    printf("In an exhibit, I saw %s.\n", noun);
    printf("%s was %s and %d.\n",noun, nounAdj, verb);
    printf("I was %s.\n", myAdj);


}

