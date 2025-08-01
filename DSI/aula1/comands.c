#include <stdio.h>

int main(){
    int a = 10;
    int b = 15;

    a = a + b;
    b = a - b;
    a = a - b;

    //printf("%d e %d\n", a, b);

    int i = 2;

    while(i<=20){
        if(i>20){
            break;
        }
        //printf("%d\n", i);
        i=i+2;

    }

    int cont, idx;
    char s[] = "abracadabra";

    for(cont=0, idx=0; s[idx]!='\0';cont=cont+(s[idx++]=='a'));

    printf("%s tem %d letras \n", s, cont);

    return 0;
}
