#include <stdio.h>

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
  int br; // Balance Rate
} Node;

typedef struct {
  Node *root;
} Tree;

void rightRotation(Node **n) {
  Node *s; // Son
  s = (*n)->left->right;
  (*n)->left->right = (*n)->right;
  (*n)->right->left = s;
  (*n)->right->br -= 1;
  (*n) = (*n)->left;
  (*n)->br += 1;
}

void leftRotation(Node **n) {
  Node *s; // Son
  s = (*n)->right->left;
  (*n)->right->left = (*n)->left;
  (*n)->left->right = s;
  (*n)->left->br += 1;
  (*n) = (*n)->right;
  (*n)->br -= 1;
}

void add(Node **root, Node *new) {
  if ((*root)->value >= new->value) {
      printf("Esquerda\n");
    if ((*root)->left == NULL) {
      (*root)->left = new;
    } else {
      add(&(*root)->left, new);
    }
    (*root)->br -= 1;
  } else if ((*root)->value < new->value) {
      printf("Direita\n");
    if ((*root)->right == NULL) {
      (*root)->right = new;
    } else {
      add(&(*root)->right, new);
    }
    (*root)->br += 1;
  }

  printf("%d\n",(*root)->br < -1);
  if ((*root)->br < -1) {
    rightRotation(root);
  }
  if ((*root)->br > 1) {
    leftRotation(root);
  }
}

void addNode(Tree *T, Node *n) {
  n->right = NULL;
  n->left = NULL;
  n->br = 0;
  if (T->root == NULL) {
    T->root = n;
  } else
    add(&(T->root), n);
}

void showRec(Node *n, int nvl) {
  if (n == NULL)
    return;

  showRec(n->left, nvl + 1);
  for (int i = 0; i < nvl; i++)
    printf(". . ");
  printf("%d-%d\n", n->value, n->br);
  showRec(n->right, nvl + 1);
}

void show(Tree *T) { showRec(T->root, 0); }

int main() {
  Tree T;
  T.root = NULL;

  Node n1;
  n1.value = 1;

  Node n2;
  n2.value = 2;

  Node n3;
  n3.value = 3;

  Node n4;
  n4.value = 4;

  addNode(&T, &n4);
  addNode(&T, &n2);
  addNode(&T, &n1);
  //addNode(&T, &n3);

  show(&T);
}
