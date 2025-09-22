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
    scanf(" %[^\n]", name);

    node *new = (node *) malloc(sizeof(node));
    strcpy(new->name, name);
    int ender = hash(name);
    if(tab[ender].head==NULL){
        tab[ender].head=new;
    }else{
        new->next = tab[ender].head;
        tab[ender].head = new;
    }
    printf("\tAdded!\n\n");
}

void rmv(pairTab *tab){
    char name[10];
    printf("Enter a name to be removed:");
    scanf(" %[^\n]", name);

    int ender = hash(name);
    node *cur = tab[ender].head;
    node *bef = NULL;

    while(cur!=NULL&&strcmp(name, cur->name)!=0){
        bef=cur;
        cur=cur->next;
    }

    if(cur==NULL){
        printf("\tNot found\n\n");
    }else{
        if(bef==NULL){
            tab[ender].head = cur->next;
        }else{
            bef->next = cur->next;
        }
        free(cur);
        printf("\tRemoved!\n\n");
    }
}

void search(pairTab *tab){
    char name[10];
    printf("Enter a name to be searched:");
    scanf(" %[^\n]", name);

    int ender = hash(name);
    node *cur = tab[ender].head;

    while(cur!=NULL&&strcmp(name, cur->name)!=0){
        cur=cur->next;
    }

    if(cur==NULL){
        printf("\tNot found\n\n");
    }else{
        printf("\tFound %s at letter %c\n\n", cur->name, tab[ender].letter);
    }
}

void searchLetter(pairTab *tab){
    char let[1];
    printf("Enter a letter:");
    scanf(" %[^\n]", let);

    int ender = hash(let);
    node *cur = tab[ender].head;

    if(cur!=NULL){
        printf("\tLetter %c found\n", let[0]);
        while(cur!=NULL){
            printf("\t\t- %s\n", cur->name);
            cur=cur->next;
        }
    }else{
        printf("Letter %c not found\n", let[0]);
    }

}

void destroy(pairTab *tab){
    node *n;
    node *p;
    for(int i=0;i<TF;i++){

        if(tab[i].head!=NULL){
            n = tab[i].head;
            while(n!=NULL){
                p = n;
                n = n->next;
                free(p);
            }
        }
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
        printf("4-Search Letter\n");
        printf("5-Show\n");
        printf("0-Exit Program\n\n");

        printf("Enter an option: ");
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
                search(tab);
                break;
            case 4:
                searchLetter(tab);
                break;
            case 5:
                show(tab);
                break;
            case 0:
                printf("Shutdown now!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    }while(opc!=0);

    destroy(tab);

}

