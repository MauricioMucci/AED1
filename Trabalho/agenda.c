#include "agenda.h"

void pause(){
	printf("\nClique no enter para continuar\n");
    getchar();
    setbuf(stdin, NULL);
}

void limpa()
{
	system("cls || clear");
}

void lerString(char palavra[], int tamanho, Variaveis *var){
    var->i = 0;

	var->c = getchar();
	while ((var->c != '\n') && (var->i < tamanho))
    {
		palavra[var->i++] = var->c;
		var->c = getchar();
	}
	palavra[var->i] = '\0';

	if (var->c != '\n')
    {
		var->c = getchar();
		while ((var->c != '\n') && (var->c != EOF))
        {
			var->c = getchar();
		}
	}
}

void reset(Fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
    fila->tamanho = 0;
}

int empty(Fila *fila){
    if (fila->tamanho == 0)
    {
        return 1;
    }
    return 0;    
}

void push(Fila *fila, Variaveis *var){
    TipoFila *no;
    no = malloc(sizeof(TipoFila));
    if (!no)
    {
        printf("ERROR: MEMORIA INSUFICIENTE");
        exit(1);
    }
    
    if (empty(fila))
    {
        fila->primeiro = no;
        fila->ultimo = no;
        fill_data(no, var);
        no->proximo = NULL;
        no->anterior = NULL;
    } else
    {
        TipoFila *tmp; //anterior
        tmp = fila->ultimo;
        tmp->proximo = no;
        no->anterior = tmp;
        fill_data(no, var);
        no->proximo = NULL;
        fila->ultimo = no;
    }
    
    fila->tamanho++;
}

void pop(Fila *fila){
    if (empty(fila))
    {
        printf("Lista de contatos esta vazia!\n");
        pause();
        return;
    }

    TipoFila *no;
    no = fila->primeiro;

    if(fila->primeiro == fila->ultimo)
    {
        free(no);
        fila->primeiro = NULL;
        fila->ultimo = NULL;
    } else
    {
        TipoFila *tmp; //proximo
        tmp = no->proximo;
        tmp->anterior = NULL;
        free(no);
        fila->primeiro = tmp;
    }

    fila->tamanho--;

    printf("Contato removido!\n");
    pause();
}

void clear(Fila *fila){
    while (!empty(fila))
    {
        pop(fila);
    }
}

void fill_data(TipoFila *nodo, Variaveis *var){

    printf("Digite o nome: ");
        lerString(nodo->conteudo.nome, MAX, var);
    printf("Digite a idade: ");
        scanf("%hd", &nodo->conteudo.idade);
    printf("Digite o telefone: ");
        scanf("%d", &nodo->conteudo.telefone);
    setbuf(stdin,NULL);
}

void imprimir(Fila *fila, Variaveis *var){
    if (empty(fila))
    {
        printf("Lista de contatos esta vazia!\n");
        pause();
        return;
    }

    TipoFila *tmp;
    var->i = 1;

    for(tmp = fila->primeiro; tmp != NULL; tmp = tmp->proximo)
    {
        printf("-----[ Contato %d ]-----\n",var->i++);
        printf("Nome: %s\nIdade: %d\nTelefone: %d\n", tmp->conteudo.nome, tmp->conteudo.idade, tmp->conteudo.telefone);
    }
    pause();
}