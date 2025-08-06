#include <stdio.h>
#include <stdlib.h>

int len(char str[]){
    int i;
    for(i=0;str[i]!='\0';i++);
    return i;
}

int main(){
    char pps[20];
    char choice;

    do{
        system("clear");
        printf("-------------------------\n");
        printf("Verificador de FBF\n");
        printf("-------------------------\n");
        printf("%s\n", pps);
        printf("\n1 - E\n");
        printf("2 - OU\n");
        printf("3 - NAO\n");
        printf("7 - VERIFICAR\n");
        printf("8 - SAIR\n");
        printf("Digite uma opcao ou uma proposicao(A, B, C,...: ");
        scanf("%c", &choice);


        switch (choice) {
            case '1':
                pps[len(pps)] = '^';
                break;
            case '2':
                pps[len(pps)] = 'v';
                break;
            case '3':
                pps[len(pps)] = '~';
                break;
            default:
                if(choice>='A'&&choice<='Z'){
                    pps[len(pps)] = choice;
                }else if(choice>='a'&&choice<='z'){
                    pps[len(pps)] = choice-('a'-'A');
                }
                break;
        }


    }while(choice!='8');
    return 0;
}
