#include <stdio.h>

int mystrlen(char *);
void mystrcp(char *, char *);
int mystrcmp(char *, char *);

int main(){

    int x;
    char str[]="bom";
    char str1[]="boa";

    printf("%d letras\n", mystrlen(str));

    //printf("s1 antes: %s\n", str1);
    //mystrcp(str1, str);
    //printf("s1 depois: %s\n", str1);

    x = mystrcmp(str1,str);

    if(x<0){
        printf("%s %s\n", str1, str);
    }else if(x==0){
        printf("\nsao iguais\n");
    }else{
        printf("%s %s\n", str, str1);
    }

    return 0;
}

int mystrlen(char *s){
    int i;
    for(i=0;*s!='\0';s++, i++);
    return i;
}

void mystrcp(char *s1, char *s2){
    for( ;*s2!='\0'; s1++, s2++){
        *s1 = !s2;
    }
    *s1='\0';
}

int mystrcmp(char *s1, char *s2){

    while(*s1!='\0' && *s2!='\0' && *s1==*s2){
        s1++;
        s2++;
    }
    return ((*s1)-(*s2));

}
