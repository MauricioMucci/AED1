#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node *pLeft;
    struct node *pRight;
} Tree;

// Sistema
void pause();
void clear();

// Arvore AVL
Tree **reset();
Tree *smallest(Tree *node);

int height(Tree *node);
int push(Tree **root, int num);
int balanceFactor(Tree *node);
int leftBalance(Tree **root);
int rightBalance(Tree **root);
int pop(Tree **root, int num);
int balance(Tree **root);
void search(Tree **root, int num);

void treeClear(Tree **root);
void simpleRotationLeft(Tree **root);
void simpleRotationRight(Tree **root);
void nodeClear(Tree *node);
void printTree(Tree *node, int tmp);