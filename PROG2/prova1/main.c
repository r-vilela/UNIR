#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod;
    char desc[40];
    float price;
    char dosa[10];
}remedio;

typedef struct {
    int cod;
    char name[40];
    char cpf[20];
    char celular[20];
}cliente;

typedef struct{
    int cod;
    int posender;
}ind;

void addRem(){
    remedio rem;

    FILE *arq = fopen("remedio.dat", "ab");
    if(arq==NULL){
        FILE *arq = fopen("remedio.dat", "wb");
    }

    printf("Adding Medicine\n");

    printf("\tEnter the code: ");
    scanf("%d", &rem.cod);

    printf("\tEnter the description: ");
    scanf(" %[^\n]", rem.desc);

    printf("\tEnter the price: ");
    scanf(" %f", &rem.price);

    printf("\tEnter the dosage: ");
    scanf(" %[^\n]", rem.dosa);

    fwrite(&rem, sizeof(remedio), 1, arq);

    printf("Added successfully!\n\n");

    fclose(arq);
};

void addCli(){
    cliente cli;
    FILE *arq = fopen("cliente.dat","ab");
    if(arq==NULL){
        FILE *arq=fopen("cliente.dat", "wb");
    }

    printf("Enter client code: ");
    scanf("%d", &cli.cod);

    printf("Enter client name: ");
    scanf(" %[^\n]", cli.name);

    printf("Enter client CPF: ");
    scanf(" %[^\n]", cli.cpf);

    printf("Enter client code: ");
    scanf(" %[^\n]", cli.celular);

    fwrite(&cli, sizeof(cliente), 1, arq);

    printf("Cliente added successfully!\n\n");

    fclose(arq);
}

void showRem(){
    remedio rem;
    int pos=0;
    FILE *arq = fopen("remedio.dat", "rb");
    if(arq==NULL){
        printf("Medicine file doesn`t exist!\n\n");
    }else{
        printf("Medicine Table\n");
        fread(&rem, sizeof(remedio), 1, arq);
        while(!feof(arq)){
            printf("\tPosition: %d \n\t\tCode: %d \n\t\tDescription: %s \n\t\tPrice: R$%.2f \n\t\tDosage: %s\n",
                    pos, rem.cod, rem.desc, rem.price, rem.dosa);
            pos++;
            fread(&rem, sizeof(remedio), 1, arq);
        }
        fclose(arq);

    }
};

void showCli(){
    cliente cli;
    int pos=0;
    FILE *arq = fopen("cliente.dat", "rb");

    if(arq==NULL){
        printf("Client file doesn`t exist!\n\n");
    }else{
        printf("Reading Client file!\n");
        fread(&cli, sizeof(cliente), 1, arq);
        while(!feof(arq)){
            printf("\tPosition %d\n\t\tCode: %d\n\t\tName: %s\n\t\tCPF: %s\n\t\tTelephone: %s\n",
                    pos, cli.cod, cli.name,cli.cpf,cli.celular);
            pos++;
            fread(&cli,sizeof(cliente),1,arq);
        }
        fclose(arq);
    }
}

void showSortRem(ind *indRemTab, int *tl){
    remedio rem;
    int i;
    if((*tl)==0){
        printf("Index Table is empty!\n\n");
    }else{
        FILE *arq = fopen("remedio.dat", "rb");
        if(arq==NULL){
            printf("Error when reading file!\n\n");
        }else{
            printf("Medicine Table Sorted\n");
            for(i=0;i<(*tl);i++){
                fseek(arq,(indRemTab[i].posender)*sizeof(remedio),SEEK_SET);
                fread(&rem,sizeof(remedio),1,arq);
                printf("\tPosition: %d \n\t\tCode: %d \n\t\tDescription: %s \n\t\tPrice: R$%.2f \n\t\tDosage: %s\n",
                        i, rem.cod, rem.desc, rem.price, rem.dosa);
            }
            fclose(arq);
        }
    }
}

void showSortCli(ind *indCliTab, int *tl){
    cliente cli;
    if((*tl)==0){
        printf("Index Table is empty!\n\n");
    }else{
        FILE *arq = fopen("cliente.dat", "rb");
        if(arq==NULL){
            printf("Error when reading file!\n\n");
        }else{
            printf("Client Table Sorted\n");
            for(int i=0;i<(*tl);i++){
                fseek(arq,(indCliTab[i].posender)*sizeof(cliente),SEEK_SET);
                fread(&cli, sizeof(cliente), 1, arq);
                printf("\tPosition %d\n\t\tCode: %d\n\t\tName: %s\n\t\tCPF: %s\n\t\tTelephone: %s\n",
                        i, cli.cod, cli.name,cli.cpf,cli.celular);
            }
            fclose(arq);
        }
    }
}

void createIndRem(ind *indRemTab, int *tl){
    remedio rem;
    ind remInd;
    int pos=0;
    FILE *arq = fopen("remedio.dat", "rb");
    if(arq==NULL){
        printf("Medicine file doesn`t exist!\n\n");
    }else{
        fread(&rem, sizeof(remedio), 1, arq);
        while(!feof(arq)){
            remInd.cod = rem.cod;
            remInd.posender = pos;
            indRemTab[pos] = remInd;

            pos++;
            fread(&rem, sizeof(remedio), 1, arq);
        }
        fclose(arq);
        printf("Table created!\n\n");

        int i, j;

        for(i=0;i<pos;i++){
            for(j=0;j<pos-1;j++){
                if(indRemTab[j].cod>indRemTab[j+1].cod){
                    remInd = indRemTab[j+1];
                    indRemTab[j+1] = indRemTab[j];
                    indRemTab[j]=remInd;
                }
            }
        }
        printf("Table sorted!\n\n");

        *tl = pos;
    }
}

void createIndCli(ind *indCliTab, int *tl){
    cliente cli;
    ind cliInd;
    int pos=0;

    FILE *arq = fopen("cliente.dat", "rb");
    if(arq==NULL){
        printf("Client file doesn`t exist!\n\n");
    }else{
        fread(&cli,sizeof(cliente),1,arq);
        while(!feof(arq)){
            indCliTab[pos].cod = cli.cod;
            indCliTab[pos].posender = pos;
            pos++;
            fread(&cli,sizeof(cliente),1,arq);
        }
        printf("Table created!\n\n");
        fclose(arq);

        for(int i=0;i<pos;i++){
            for(int j=0;j<pos-1;j++){
                if(indCliTab[j].cod>indCliTab[j+1].cod){
                    cliInd = indCliTab[j+1];
                    indCliTab[j+1] = indCliTab[j];
                    indCliTab[j] = cliInd;
                }
            }
        }
        printf("Table sorted!\n\n");

        *tl = pos;
    }

};

void showInd(ind *indTab, int *tl){
    int i;
    if((*tl)==0){
        printf("Index Table is empty!\n\n");
    }else{
        printf("Readig table\n");
        for(i=0;i<(*tl);i++){
            printf("\t%d - Positios %d Code %d\n", i, indTab[i].posender, indTab[i].cod);
        }
    }
}

int binarySearch(int inc, int fim, ind *tab, int cod){
    int meio = (inc+fim)/2;
    if(inc>fim)
        return -1;

    if(tab[meio].cod==cod){
        return meio;
    }else if(tab[meio].cod>cod){
        return binarySearch(inc, meio-1, tab, cod);
    }else{
        return binarySearch(meio+1, fim, tab, cod);
    }
}

void searchMed(ind *indTab, int *tl){
    int cod, pos;
    if((*tl)==0){
        printf("Index Table is empty!\n\n");
    }else{
        remedio rem;
        printf("Enter the code to be searched: ");
        scanf("%d", &cod);

        pos = binarySearch(0, (*tl)-1, indTab, cod);
        if(pos>=0){
            FILE *arq = fopen("remedio.dat", "rb");
            if(arq==NULL){
                printf("Error when reading file!\n\n");
            }else{
                fseek(arq, (indTab[pos].posender)*sizeof(remedio),SEEK_SET);
                fread(&rem, sizeof(remedio),1,arq);
                printf("Medicine Found!\n");
                printf("\tPosition: %d \n\t\tCode: %d \n\t\tDescription: %s \n\t\tPrice: R$%.2f \n\t\tDosage: %s\n\n",
                        pos, rem.cod, rem.desc, rem.price, rem.dosa);
            }
            fclose(arq);
        }else{
            printf("\tNot Found\n\n");
        }
    }
}

void searchCli(ind *indCliTab, int *tl){
    int cod, pos;
    cliente cli;
    if((*tl)==0){
        printf("Index Table is empty!\n\n");
    }else{
        printf("Enter the client code to be searched: ");
        scanf("%d", &cod);

        pos = binarySearch(0,(*tl)-1, indCliTab,cod);
        if(pos>=0){
            FILE *arq = fopen("cliente.dat", "rb");
            if(arq==NULL){
                printf("Error when reading file!\n\n");
            }else{
                fseek(arq,(indCliTab[pos].posender)*sizeof(cliente),SEEK_SET);
                fread(&cli,sizeof(cliente),1,arq);
                printf("\tPosition %d\n\t\tCode: %d\n\t\tName: %s\n\t\tCPF: %s\n\t\tTelephone: %s\n",
                        pos, cli.cod, cli.name,cli.cpf,cli.celular);
            }
            fclose(arq);
        }else{
            printf("\nNot Found!\n\n");
        }
    }
}

int main(){
    int opc;
    ind indRemTab[20];
    int tlRem=0;
    ind indCliTab[20];
    int tlCli=0;

    do{
        printf("1-Add medicine\n");
        printf("2-Add client\n");
        printf("3-Show medicines\n");
        printf("4-Show clients\n");
        printf("5-Show medicines sorted\n");
        printf("6-Show clients sorted\n");
        printf("7-Create medicines index\n");
        printf("8-Create clients index\n");
        printf("9-Show medicines index\n");
        printf("10-Show clients index\n");
        printf("11-Search medicines\n");
        printf("12-Search Clients\n");
        printf("0-Exit program\n");

        printf("\nEnter option: ");
        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                addRem();
                break;
            case 2:
                addCli();
                break;
            case 3:
                showRem();
                break;
            case 4:
                showCli();
                break;
            case 5:
                showSortRem(indRemTab, &tlRem);
                break;
            case 6:
                showSortCli(indCliTab, &tlCli);
                break;
            case 7:
                createIndRem(indRemTab, &tlRem);
                break;
            case 8:
                createIndCli(indCliTab, &tlCli);
                break;
            case 9:
                showInd(indRemTab, &tlRem);
                break;
            case 10:
                showInd(indCliTab, &tlCli);
                break;
            case 11:
                searchMed(indRemTab, &tlRem);
                break;
            case 12:
                searchCli(indCliTab, &tlCli);
                break;
            case 0:
                printf("Exiting program!\n");
                break;
            default:
                printf("Invalid option!\n");
                break;

        }
    }while(opc!=0);

    return 0;
}
