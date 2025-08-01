#include <stdio.h>

int mystrlen(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

int main(){
    char str[20], cpstr[20];
    int i,j;

    printf("Digite uma frase que exibirei ela ao contrario!\n");

    printf("Frase: ");
    scanf("%[^\n]", &str);

    i=mystrlen(str)-1;

    while(i>=0){
        cpstr[j++]=str[i--];
    }

    cpstr[j+1]='\0';

    printf("A frase ao contrario eh: \n\" %s \"\n", cpstr);

    return 0;
}
