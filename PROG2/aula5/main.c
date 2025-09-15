#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TF 26

typedef struct node{
    char name[10];
    struct node *next;
}node;

typedef struct{
    char letter;
    node *head;
}pairTab;

void create(pairTab *tab){
    char letter = 65;
    int i=13;
    pairTab p;
    p.letter = letter;
    p.head = NULL;

    for( int cont=0; cont<TF;cont++){
        tab[i]=p;
        letter++;
        i++;
        p.letter = letter;
        if(i==26)
            i=0;
    }

}

int hash(char *nome){
    return (nome[0]%TF);
}

void show(pairTab *tab){
    node *n;
    for(int i=0;i<TF;i++){

        if(tab[i].head!=NULL){
            printf("Letter %c\n", tab[i].letter);
            n = tab[i].head;
            while(n!=NULL){
                printf("\t- %s\n", n->name);
                n = n->next;
            }
        }
    }
    printf("End of table\n");
}

void insert(pairTab *tab){
    char name[10];
    printf("Enter the new name:");
    getchar();
    fgets(name,sizeof(name), stdin);

    node *new = (node *) malloc(sizeof(node));
    strcpy(new->name, name);
    int ender = hash(name);
    if(tab[ender].head==NULL){
        tab[ender].head=new;
    }else{
        new->next = tab[ender].head;
        tab[ender].head = new;
    }
    printf("Adicionado\n");
}

void rmv(pairTab *tab){
    char name[10];
    printf("Enter the new name:");
    getchar();
    fgets(name,sizeof(name), stdin);

    int ender = hash(name);
    node *cur = tab[ender].head;
    node *bef = NULL;

    while(cur!=NULL&&strcmp(name, cur->name)!=0){
        bef=cur;
        cur=cur->next;
    }

    if(cur==NULL){
        printf("Not found\n");
    }else{
        bef->next = cur->next;
        free(cur);
    }
}

void main(){
    pairTab tab[TF];
    int opc;
    char name[10];

    create(tab);

    do{
        printf("1-Add\n");
        printf("2-Remove\n");
        printf("3-Search\n");
        printf("4-Show\n");
        printf("0-Exit Program\n");

        scanf("%d", &opc);

        system("clear");

        switch (opc) {
            case 1:
                insert(tab);
                break;
            case 2:
                rmv(tab);
                break;
            case 3:
                printf("Searching Name\n");
                break;
            case 4:
                show(tab);
                break;
            case 0:
                printf("Closing system!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }while(opc!=0);


}

