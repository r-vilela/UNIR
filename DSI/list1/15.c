#include <stdio.h>

int strlng(char str[]){
    int i;

    for(i=0;str[i]!='\0';i++);

    return i;
}

int main(){
    char str[40];
    int i;

    printf("Trocarei as letras \'a\' por \'b\'!\n");
    printf("Escreva sua frase: ");
    scanf("%[^\n]", str);

    for(i=0;i<strlng(str);i++){
        if(str[i]=='a'){
            str[i]='b';
        }
    }

    printf("Essa eh a nova frase: \n%s\n", str);

    return 0;
}
