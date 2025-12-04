#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}Node;

typedef struct{
    Node *root;
}BST;

static void criar(BST *tree){
    tree->root = NULL;
}

static int insert(Node **node, int v){
    if(*node == NULL){
        Node *new = malloc(sizeof(Node));
        new->info = v;
        new->left = NULL;
        new->right = NULL;
        (*node) = new;
        return 1;
    }else if ((*node)->info > v)
        return insert(&((*node)->left), v);
    else if ((*node)->info < v)
        return insert(&((*node)->right), v);

    return 0;
}

static void higherOfLowers(Node **node){
    while((*node)->right != NULL)
        (*node) = (*node)->right;
}

static int delete(Node **node, int v){
    if((*node) == NULL)
        return 0;
    if((*node)->info > v)
        return delete(&((*node)->left), v);
    if((*node)->info < v)
        return delete(&((*node)->right), v);

    if((*node)->info == v){
        if((*node)->left == NULL && (*node)->left == NULL){
            free(*node);
            *node = NULL;
        }else if((*node)->left == NULL){
            Node *old = (*node);
            (*node) = old->right;
            free(old);
        }else if((*node)->right == NULL){
            Node *old = (*node);
            (*node) = old->left;
            free(old);
        }else{
            Node **oldN = &((*node)->left);
            higherOfLowers(oldN);
            (*node)->info = (*oldN)->info;
            free(*oldN);
            *oldN = NULL;
        }
        return 1;
    }
    return 0;
}

static void showInOrder(Node *n, int nvl){
    if(n == NULL)
        return;
    showInOrder(n->left, nvl+1);
    for(int i=0;i < nvl;i++)
        printf(".");
    printf("%d\n", n->info);
    showInOrder(n->right, nvl+1);
}

static void showPosOrder(Node *n, int nvl){
    if(n == NULL)
        return;
    showInOrder(n->left, nvl+1);
    showInOrder(n->right, nvl+1);
    for(int i=0;i < nvl;i++)
        printf(".");
    printf("%d\n", n->info);
}

static void showPreOrder(Node *n, int nvl){
    if(n == NULL)
        return;
    for(int i=0;i < nvl;i++)
        printf(".");
    printf("%d\n", n->info);
    showInOrder(n->left, nvl+1);
    showInOrder(n->right, nvl+1);
}

static int empty(Node *n){
    return !(n == NULL);
}

static void destroy();

static int search();

static int height();

static int countNodes();

static int countLeafs();

static int balanced();

static int perfectBalanced();

static int searchLevel();

int main()
{
    printf("Hello World!\n");
}

