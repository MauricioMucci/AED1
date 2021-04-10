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

void incluir()
{
    Pessoa *nova;
    VAR *controle;
    controle = pbuffer;

    if (controle->tamanho_atual == MAX_PESSOAS)
    {
        printf("Numero limite atingido!\n");
        pause();
        return;
    }

    if ((agenda = (Pessoa*)realloc(agenda, sizeof(Pessoa) * (controle->tamanho_atual + 1))) == NULL)
    {
        printf("ERROR: IMPOSSIVEL ALOCAR MEMORIA!\n");
        pause();
        exit(1);
    }
    nova = agenda + (sizeof(Pessoa) * controle->tamanho_atual);

    printf("Digite o nome: ");
        scanf("%s", nova->nome);
    printf("Digite a idade: ");
        scanf("%d", &nova->idade);
    printf("Digite o telefone: ");
        scanf("%d", &nova->numero);
    setbuf(stdin,NULL);
    controle->tamanho_atual++;
}

void listar()
{
    VAR *controle;
    Pessoa *tmp;

    controle = pbuffer;
    tmp = agenda;

    if (controle->tamanho_atual == 0)
    {
        printf("Agenda vazia!\n");
        pause();
        return;
    }
    
    for (controle->contador = 0; controle->contador < controle->tamanho_atual; controle->contador++)
    {
        printf("-----[ Contato %d ]-----\n", controle->contador + 1);
        printf("Nome: %s\n", tmp->nome);
        printf("Idade: %d\n", tmp->idade);
        printf("Telefone: %d\n", tmp->numero);
        tmp++;
    }
    pause();
}

void remover()
{
    VAR *controle;
    Pessoa *inicio, *fim;

    controle = pbuffer;
    
    listar();
    if (controle->tamanho_atual == 0)
        return;

    printf("Qual contato sera removido?\nOpcao: ");
        scanf("%d", &controle->escolha);

    if (controle->escolha > controle->tamanho_atual)
    {
        printf("Tente novammente!\n");
        pause();
        return;
    }
    if (controle->escolha == controle->tamanho_atual)
    {
        agenda = (Pessoa*)realloc(agenda, sizeof(Pessoa) * controle->tamanho_atual);
        controle->tamanho_atual--;
        return;
    }

    inicio = agenda + (sizeof(Pessoa) * (controle->escolha - 1));
    fim = agenda + (sizeof(Pessoa) * controle->escolha);

    memcpy(inicio, fim, (sizeof(Pessoa) * controle->tamanho_atual) - (sizeof(Pessoa) * controle->escolha));

    controle->tamanho_atual--; 
}

void buscar()
{
    VAR *controle;
    Pessoa *tmp;

    controle = pbuffer;
    tmp = agenda;

    if (controle->tamanho_atual == 0)
    {
        printf("Agenda vazia!\n");
        pause();
        return;
    }

    printf("Nome da pessoar a ser procurada: ");
        scanf("%s", controle->nome_aux);
        setbuf(stdin,NULL);

    for (controle->contador = 0; controle->contador < controle->tamanho_atual; controle->contador++)
    {
        if (strcmp(controle->nome_aux,tmp->nome) == 0)
        {
            printf("\nNome: %s\n", tmp->nome);
            printf("Idade: %d\n", tmp->idade);
            printf("Telefone: %d\n", tmp->numero);
            pause();
            return;
        }
        tmp++;
    }
    printf("Tente novamente!\n");
    pause();
}