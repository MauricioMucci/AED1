#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PESSOAS 10
#define MAX_NOME 10

void *pbuffer;
void *agenda;

typedef struct{
    char nome[MAX_NOME];
    int idade, numero;
} Pessoa;

typedef struct{
    int escolha, contador, tamanho_atual;
    char nome_aux[MAX_NOME];
} VAR;

// Assinaturas
void pause();
void clear();
void incluir();
void remover();
void buscar();
void listar();