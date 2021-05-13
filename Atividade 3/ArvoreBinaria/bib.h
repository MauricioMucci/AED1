#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    int height;
    struct tree *pLeft;
    struct tree *pRight;
};

typedef struct tree* Pointer; // Tipo q cria ponteiro para ponteiro

typedef struct var {
    int numero;
    short int escolha;
} Variaveis;

// Sistema
void pause();
void limpa();
int menu(Pointer* root, Variaveis* var);
int menu_print(Pointer* root, Variaveis* var);

// Funcionamento da arvore binaria
void reset(Pointer* root);
void pop(struct tree* root);
void clear(Pointer* root);
void push(Pointer* root, int num);
void removeNo(Pointer* root, int num);
void exclui(Pointer ant, Pointer* atual);
void search(struct tree* root, int num);

// Impressao
void preOrder(Pointer* root);
void inOrder(Pointer* root);
void posOrder(Pointer* root);

// Funcionamento da arvore avl