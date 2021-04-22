#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct{
    char nome[MAX];
    short int idade;
    int telefone;
} Dados;

typedef struct nodo{
    Dados conteudo;
    struct nodo *proximo;
    struct nodo *anterior;
} TipoFila;

typedef struct{
    TipoFila *primeiro;
    TipoFila *ultimo;
    short int tamanho;
} Fila;

typedef struct{
    char c;
    short int i;
} Variaveis;

void *pBuffer;

void pause();
void limpa();
int menu(Variaveis *var, Fila *fila);
int menu_imprimir(Variaveis *var, Fila *fila);
void lerString(char palavra[], int tamanho, Variaveis *var);

void reset(Fila *fila);
int empty(Fila *fila);
void push(Fila *fila, Variaveis *var);
void pop(Fila *fila);
void clear(Fila *fila);
void fill_data(TipoFila *nodo, Variaveis *var);
void imprimir(Fila *fila, Variaveis *var);
void imprimir_inverso(Fila *fila, Variaveis *var);