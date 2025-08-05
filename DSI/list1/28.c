#include <stdio.h>

int main(){
    char str[20];
    int i;

    printf("Eu amo comer vogais!!\n\n");

    printf("Escreva uma frase para eu me alimentar: ");
    scanf("%[^\n]", &str);

    printf("NHAC! NHAC! NHAC!\n\n");

    for(i=0; str[i]!='\0';i++){
        if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'){
            printf("%c",str[i]);
        }
    }

    return 0;
}
