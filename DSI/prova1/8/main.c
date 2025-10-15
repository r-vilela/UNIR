#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *next;
}Node;

typedef struct{
    Node *head;
}List;

void create(List *L){
    L->head = NULL;
};

int insert(List *L, int v){
    Node *n = (Node *) malloc(sizeof(Node)), *p;
    n->info = v;
    if(L->head == NULL){
        L->head = n;
        return 1;
    }
    n->next = L->head;
    L->head = n;

    return 1;
};

void show(List *L){
    Node *n;
    int i;

    for(n=L->head,i=1;n!=NULL;i++,n=n->next)
        printf("\t%d - %d\n",i, n->info);
};

void destroy(List *L){
    Node *n, *p;
    for(n=L->head;n!=NULL;p=n,n=n->next,free(p));
}

void invert(List *L){
    Node *n, *p=NULL;

    for(n=(L->head)->next;n!=NULL;(L->head)->next=p,p=L->head,L->head=n,n=n->next);
    (L->head)->next = p;
}

int main(){
    List L;
    create(&L);
    int opc, v;

    do{
        printf("List: \n");
        show(&L);
        printf("\n--------------\n");
        printf("1-Insert\n");
        printf("2-Invert\n");
        printf("\nEnter an option: ");
        scanf("%d", &opc);
        system("clear");

        switch (opc) {
            case 1:
                printf("Enter value to insert value:");
                scanf("%d", &v);
                insert(&L, v);
                break;

            case 2:
                invert(&L);
                break;

            case 0:
                printf("Shutting down!\n");
            default:
                printf("Invalid Option!\n");
        }
    }while(opc!=0);

    destroy(&L);
    return 1;
}
