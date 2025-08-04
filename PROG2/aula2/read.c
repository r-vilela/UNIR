#include <stdio.h>

int main(){
    FILE *f = fopen("teste.txt", "r");
    int i;
    while(fscanf(f, "%d", &i) == 1){
        printf("%d\n", i);
    }
    fclose(f);

    return 0;
}
