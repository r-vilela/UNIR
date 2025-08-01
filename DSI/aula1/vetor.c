#include <stdio.h>

int main(){
    //FUNCAO DE COMPARACAO COM 2 STRINGS

    char s1[] = "AMAR";
    char s2[] = "AMAR";

    int i;

    for(i=0; s1[i]!='\0'&&s2[i]!='\0'&&s1[i]==s2[i]; i++);

    if(s1[i] == s2[i]){// return 0
        printf("As palavras sao iguais!\n");
    } else if(s1[i]-s2[i]<0){
        printf("%s %s", s1, s2);
    }else{
        printf("%s %s", s2, s1);

    }


    return 0;
}
