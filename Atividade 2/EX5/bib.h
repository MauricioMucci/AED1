// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Estrutura
typedef struct{
    char nome[30];
    int idade;
    float altura;
} Pessoa;

// Lista Encadeada
typedef struct lista{
	Pessoa Contatos;
	struct lista *prox;
}LISTA;

// Assinaturas
void pause();
void clear();
int menu(void);
void lerString(char palavra[], int tamanho);
LISTA *cria(void);
int vazia(LISTA *le);
void insere(LISTA *head,Pessoa x);
void incluir(LISTA *head);
void imprimir(LISTA *tmp);
void listar(LISTA *head);
void libera(LISTA *head);