#include "bib.h"

void pause()
{
	printf("\nClique no enter para continuar\n");
	getchar();
}

void clear()
{
	system("cls || clear");
}

int menu(void)
{
	clear();
	int resposta;
		
	do{
		clear();
		printf("-----[ Menu ]-----\n");
        printf("1 - Incluir nome\n");
        printf("2 - Listar\n");
        printf("3- Sair\n");
        printf("Digite: ");
            scanf("%d", &resposta);
        setbuf(stdin,NULL);
	}while (resposta < 1 || resposta > 3 );	

	return resposta;
}

void lerString(char palavra[], int tamanho)
{
	int i = 0;
	char c;

	c = getchar();
	while ((c != '\n') && (i < tamanho))
    {
		palavra[i++] = c;
		c = getchar();
	}
	palavra[i] = '\0';

	if (c != '\n')
    {
		c = getchar();
		while ((c != '\n') && (c != EOF))
        {
			c = getchar();
		}
	}
}

LISTA *cria(void)
{
    LISTA *start;

    if((start=(LISTA *)malloc(sizeof(LISTA))) == NULL)
    {
        printf("Não foi possivel alocar memoria\n");
        exit(1);
    }

    start->prox = NULL;
    return start;
}

int vazia(LISTA *le)
{
	if(le->prox == NULL)
    {
		return 1;
	} else
    {
		return 0;
	}
}

void insere(LISTA *head,Pessoa x)
{
	LISTA *novo = (LISTA*)malloc(sizeof(LISTA));
	if(!novo)
    {
		printf("Sem memória disponível!\n");
		exit(1);
	}

	novo->Contatos = x;

	if(vazia(head))
    {
		head->prox = novo;
	} else
    {
		LISTA *tmp;

		for (tmp = head->prox; tmp->prox != NULL; tmp = tmp->prox);
		tmp->prox = novo;
	}
}

void incluir(LISTA *head)
{
    clear();

	Pessoa novo;

	printf("Digite o nome da pessoa: ");
	    lerString(novo.nome,30);
	printf("Digite a idade da pessoa: ");
        scanf("%d", &novo.idade);
	printf("Digite a altura da pessoa: ");
        scanf("%f", &novo.altura);
    setbuf(stdin,NULL);

	insere(head,novo);
}

void imprimir(LISTA *tmp)
{
    printf("\nNome: ");
	for(int i = 0; tmp->Contatos.nome[i] != '\0'; i++)
    {
		printf("%c",tmp->Contatos.nome[i]);
	}

	printf("\nIdade: %d", tmp->Contatos.idade);

	printf("\nNumero: %.2f\n\n", tmp->Contatos.altura);
}

void listar(LISTA *head)
{
    clear();

	if(vazia(head))
    {
		printf("Lista está vazia!\n\n");
		pause();
		return;
	}

	LISTA *tmp;
    int index = 1;

	for(tmp = head->prox;tmp != NULL; tmp = tmp->prox)
    {
        printf("-----[ Contato %d ]-----", index++);
		imprimir(tmp);
	}

    pause();
}

void libera(LISTA *head)
{
    LISTA *proxNo;

    if(!vazia(head))
    {
        head = head->prox;
		while(head != NULL)
        {
			proxNo = head->prox;
			free(head);
			head = proxNo;
		}
	}
}