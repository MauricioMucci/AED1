#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Assinatura das funcoes utilizadas
void add (void *pbff);
void rm (void *pbff);
void search (void *pbff);
void list_name (void *pbff);

// Uma funcao que pausa a tela do terminal
void pause(){
	printf("\nDigite qualquer tecla para continuar.");
	getchar();
}

// Altere essa função dependendo do SO
void clear(){
	//system("cls");
	system("clear");
}

typedef struct
{
    char name[MAX];
    int age, phone_number;
} Agenda;

typedef struct
{
    // size = capacidade atual da agenda, counter = posicoes utilizadas
    int counter, index, size, i;
    char aux[MAX];
    Agenda *people;
} Dados;


int main(int argc, char const *argv[])
{
    int choice;
    void *pbuffer;
    Dados *management;

    pbuffer = malloc(sizeof(Dados));
    if (!pbuffer)
    {
        printf("ERROR: IMPOSSIVEL REALOCAR MEMORIA\n");
        exit(1);
    }
    
    management = pbuffer;
    management->size = 1;
    management->counter = 0;

    for (;;)
    {
        clear();

        //Menu
        printf("----------------------\n");
        printf("1. Adiciona\n");
        printf("2. Remover\n");
        printf("3. Buscar\n");
        printf("4. Listar\n");
        printf("5. Sair\n");
        printf("Opcao: ");
            scanf("%d", &choice);
            setbuf(stdin,NULL);
        printf("----------------------\n");

        switch (choice)
        {
        case 1:
            add(pbuffer);
            break;
        case 2:
            rm(pbuffer);
            break;
        case 3:
            search(pbuffer);
            break;
        case 4:
            list_name(pbuffer);
            break;
        case 5:
            free(pbuffer);
            free(management->people);
            pbuffer = NULL;
            return 0;
        default:
            printf("Opcao invalida!!!\n");
            pause();
            break;
        }
    }
    
    return 0;
}

void add(void *pbff)
{
    Dados *management;
    management = pbff;

    if (management->counter >= management->size)
    {
        printf("Agenda cheia, espere...\n");

        management->size = management->size + 1;

        management->people = (Agenda*)realloc(management->people, management->size * sizeof(Agenda))
        if (!management->people)
        {
            printf("ERROR: IMPOSSIVEL REALOCAR MEMORIA\n");
            exit(1);
        }
        
        for (management->i = ; i < count; i++)
        {
            /* code */
        }
        
    }
    
}