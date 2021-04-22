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

int menu(Variaveis *var, Fila *fila){

    limpa();

	printf("-----[ Menu ]-----\n");
    printf("1 - Incluir\n");
    printf("2 - Remover\n");
    printf("3 - Listar\n");
    printf("4 - Esvaziar\n");
    printf("5 - Sair\n");
    printf("Digite: ");
        scanf("%hd", &var->i);
    setbuf(stdin,NULL);
    switch (var->i){
        case 1:
            limpa();
            push(fila, var);
            break;
        case 2:
            limpa();
            pop(fila);
            break;
        case 3:
            while(menu_imprimir(var, fila) == 1);
            break;
        case 4:
            limpa();
            clear(fila);
            printf("Lista apagada com sucesso!\n");
            pause();
            break;
        case 5:
            limpa();
            return 0;
        default:
            printf("\nTente novamente!\n");
            pause();
            break;
    }

    return 1;
}

int menu_imprimir(Variaveis *var, Fila *fila){
    
    limpa();
    
    printf("-----[ Listando ]-----\n");
    printf("1 - Ordem de escrita\n");
    printf("2 - Ordem inversa\n");
    printf("3- Voltar\n");
    printf("Digite: ");
        scanf("%hd", &var->i);
    setbuf(stdin,NULL);

    switch (var->i)
    {
    case 1:
        limpa();
        imprimir(fila, var);
        break;
    case 2:
        limpa();
        imprimir_inverso(fila, var);
        break;
    case 3:
        return 0;
    default:
        printf("\nTente novamente!\n");
        pause();
        break;
    }

    return 1;
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

void imprimir_inverso(Fila *fila, Variaveis *var){
    if (empty(fila))
    {
        printf("Lista de contatos esta vazia!\n");
        pause();
        return;
    }

    TipoFila *tmp;
    var->i = fila->tamanho;

    for(tmp = fila->ultimo; tmp != NULL; tmp = tmp->anterior)
    {
        printf("-----[ Contato %d ]-----\n",var->i--);
        printf("Nome: %s\nIdade: %d\nTelefone: %d\n", tmp->conteudo.nome, tmp->conteudo.idade, tmp->conteudo.telefone);
    }
    pause();
}