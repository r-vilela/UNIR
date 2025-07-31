#include <stdio.h>

int strleng(char str[]){
    int i;

    for(i=0;str[i]!='\0';i++);

    return i;
}

int main(){
    int i, j, aux=-1;
    char str[40];
    char substr[] = "casa";

    printf("Ola! Escreva uma frase com ate 40 caracteres.\n");
    printf("\bATENCAO!! Eh proibido escrever \"casa\". EU SABEREI!\n");

    printf("Escreva sua frase: ");
    //fgets(str, sizeof(str), stdin);
    //str[strleng(str) -1] = '\0';
    //scanf("%s", str);
    scanf("%[^\n]", str);

    if(strleng(str)>=4){
        for(i=0;i<strleng(str);i++){
            if(aux==-1){
                for(j=0;j<strleng(substr);j++){
                    if(str[i]==substr[j]){
                        aux=i;
                        i++;
                        continue;
                    }
                    break;
                }
            }else{
                break;
            }
        };
    }

    printf("\nVoce escreveu: %s\nE...\n\n", str);

    if(i>=0){
        printf("Tem \"casa\" escrito!\n MALDITU SEJAA!!!!");
    }else{
        printf("Nao tem \"casa\" escrito!\n");
    }

    return 0;
}
