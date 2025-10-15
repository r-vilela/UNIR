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

    printf("\t");
    for(n=L->head,i=1;n!=NULL;i++,n=n->next)
        printf("%d ",n->info);
    printf("\n");
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

void par_impar(List *L, List *par, List *impar){
    Node *p, *i;

    for( ;L->head!=NULL;L->head=(L->head)->next){
        if((L->head)->info%2){
            if(impar->head==NULL){
                impar->head = L->head;
            }else{
                i->next = L->head;
            }
            i = L->head;
        }else{
            if(par->head==NULL){
                par->head = L->head;
            }else{
                p->next = L->head;
            }
            p = L->head;
        }
    }
    p->next = NULL;
    i->next = NULL;
}

int main(){
    List L, par, impar;
    create(&L);
    create(&par);
    create(&impar);
    int opc, v;

    do{
        printf("List: \n");
        show(&L);
        if(par.head !=NULL){
            printf("Par\n");
            show(&par);
            printf("Impar\n");
            show(&impar);
        }
        printf("\n--------------\n");
        printf("1-Insert\n");
        printf("2-Invert\n");
        printf("3-Separate\n");
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

            case 3:
                par_impar(&L, &par, &impar);
                break;

            case 0:
                printf("Shutting down!\n");
            default:
                printf("Invalid Option!\n");
        }
    }while(opc!=0);

    destroy(&L);
    destroy(&par);
    destroy(&impar);
    return 1;
}
