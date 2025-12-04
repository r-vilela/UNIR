#include "trees.h"
#include <stdlib.h>
#include <stdio.h>

void create(Tree *T){
    T->root = NULL;
};

int add(Tree *T, int new){
    return addRec(&(T->root), new);
}

int addRec(Node **node, int val){
    if(*node == NULL){
        *node=(Node *) malloc(sizeof(Node));
        (*node)->info = val;
        (*node)->right = NULL;
        (*node)->left = NULL;
        return 1;
    }

    if((*node)->info < val)
        return addRec(&(*node)->right, val);
    else if((*node)->info > val)
        return addRec(&(*node)->left, val);
    return 0;
}

void show(Tree *T){
    showRec(T->root, 0);
}

void showRec(Node *n, int nvl){
    if(n==NULL)
        return;

    showRec(n->left, nvl+1);
    for(int i=0;i<nvl;i++)
        printf(". . ");
    printf("%d\n", n->info);
    showRec(n->right, nvl+1);
}

int rmv(Tree *T, int val){
    return rmvRec(&(T->root), val);
}

int rmvRec(Node **node, int val){
    if(*node == NULL)
        return 0;

    if((*node)->info > val)
        return rmvRec(&(*node)->left, val);
    else if((*node)->info < val)
        return rmvRec(&(*node)->right, val);

    Node *n = *node;
    if((*node)->left==NULL && (*node)->right==NULL){
        free(*node);
        *node = NULL;
    }else if((*node)->left==NULL){
        *node = n->right;
        free(n);
    }else if((*node)->right==NULL){
        *node = n->left;
        free(n);
    }else{
        Node **m;
        for(m=&(*node)->left;(*m)->right!=NULL;m=&(*m)->right);
        (*node)->info=(*m)->info;
        //*m = NULL;
        //return 1;
        return rmvRec(m, (*m)->info);
    }
    return 1;


}

void destroy(Tree *T){
    destroyRec(&(T->root));
}

void destroyRec(Node **node){
    if(*node == NULL)
        return;

    destroyRec(&(*node)->left);
    destroyRec(&(*node)->right);
    free(*node);
}

Node * search(Tree *T, int val){
    Node *n;
    for(n=T->root;n!=NULL&&n->info != val; ){
        if(n->info>val)
            n=n->left;
        else
            n=n->right;
    }
    return n;
}

