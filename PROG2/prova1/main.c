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

typedef struct{
    int note;
    char date[11];
    int codCli;
    int codRem;
    int qnt;
}venda;

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

int addSale(ind *indCliTab, int tlCli, ind *indRemTab, int tlRem){
    venda sal;
    if(tlCli==0||tlRem==0){
        printf("Error with Index Tables!\n\n");
    }else{
        printf("Enter sale informations:\n");

        printf("\tEnter the receipt: ");
        scanf("%d", &sal.note);

        printf("\tEnter the date: ");
        scanf(" %[^\n]", &sal.date);

        printf("\tEnter the Client Code: ");
        scanf("%d", &sal.codCli);
        if(binarySearch(0,tlCli,indCliTab, sal.codCli)<0){
            printf("Error when client code!\n\n");
            return 0;
        }

        printf("\tEnter the Medicine Code: ");
        scanf("%d", &sal.codRem);
        if(binarySearch(0,tlRem,indRemTab, sal.codRem)<0){
            printf("Error when medicine code!\n\n");
            return 0;
        }

        do{
            printf("\tEnter the quantity: ");
            scanf("%d", &sal.qnt);
            if(sal.qnt>0)
                break;

            printf("\tYou cannot enter a quantity below 1!\n\n");
        }while(1);

        FILE *arq = fopen("vendas.bin", "ab");

        if(arq==NULL){
            FILE *arq = fopen("vendas.dat", "wb");
        }

        fwrite(&sal,sizeof(venda),1,arq);
        fclose(arq);
        printf("Sale added successfully!\n\n");
        return 1;
    }
}

void showSale(){
    venda sal;
    int pos=0;
    FILE *arq = fopen("vendas.bin","rb");
    if(arq == NULL){
        printf("Sale file doesn`t exist!\n\n");
    }else{
        printf("Reading Sales\n");
        fread(&sal, sizeof(venda),1,arq);
        while(!feof(arq)){
            printf("\tPosition %d\n\t\tSale Receipt: %d\n\t\tDate: %s\n\t\tClient Code: %d\n\t\tMedicine Code: %d\n\t\tQuantity: %d\n",
                    pos,sal.note,sal.date,sal.codCli,sal.codRem,sal.qnt);
            pos++;
            fread(&sal,sizeof(venda),1,arq);
        }
        fclose(arq);
    }
}

int main(){
    int opc;
    ind indRemTab[20];
    int tlRem=0;
    ind indCliTab[20];
    int tlCli=0;

    do{
        printf("1-Add Medicine\n");
        printf("2-Add Client\n");
        printf("3-Add Sale\n");
        printf("4-Show Medicines\n");
        printf("5-Show Clients\n");
        printf("6-Show Sales\n");
        printf("7-Show medicines sorted\n");
        printf("8-Show clients sorted\n");
        printf("9-Create medicines index\n");
        printf("10-Create clients index\n");
        printf("11-Show medicines index\n");
        printf("12-Show clients index\n");
        printf("13-Search medicines\n");
        printf("14-Search Clients\n");
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
                addSale(indCliTab, tlCli, indRemTab, tlRem);
                break;
            case 4:
                showRem();
                break;
            case 5:
                showCli();
                break;
            case 6:
                showSale();
                break;
            case 7:
                showSortRem(indRemTab, &tlRem);
                break;
            case 8:
                showSortCli(indCliTab, &tlCli);
                break;
            case 9:
                createIndRem(indRemTab, &tlRem);
                break;
            case 10:
                createIndCli(indCliTab, &tlCli);
                break;
            case 11:
                showInd(indRemTab, &tlRem);
                break;
            case 12:
                showInd(indCliTab, &tlCli);
                break;
            case 13:
                searchMed(indRemTab, &tlRem);
                break;
            case 14:
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
