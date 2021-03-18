#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximo numero de caracters
#define MAX 30 

//Assinaturas das funcoes utilizadas
char *add(char *str);
char *rm(char *str);
void list_name(char *str);

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

int main(int argc, char const *argv[])
{
    int choice;

    char *string = (char*)malloc(sizeof(char));

    string[0] = '\0';

    for(;;)
    {
        clear();

        //Menu
        printf("----------------------\n");
        printf("1. Adicionar nome\n");
        printf("2. Remover nome\n");
        printf("3. Listar\n");
        printf("4. Sair\n");
        printf("Opcao: ");
            scanf("%d", &choice);
            setbuf(stdin,NULL);
        printf("----------------------\n");

        switch (choice)
        {
        case 1:
            string = add(string);
            break;
        case 2:
            string = rm(string);
            break;
        case 3:
            list_name(string);
            break;
        case 4:
            free(string);
            string = NULL;
            return 0;
        default:
            printf("Opcao invalida!!!\n");
            break;
        }
    }
}

//Funcao que adiciona os nomes
char *add(char *str)
{
    char aux[MAX];
    int size_added_name, size_string;

    printf("Informe o nome: ");
        scanf("%s", aux);
        strcat(aux, ".");
    
    size_added_name = strlen(aux) + 1;
    size_string = strlen(str) + 1;

    if((str = (char*)realloc(str, (size_string + size_added_name) * sizeof(char))) == NULL)
    {
        printf("ERROR: IMPOSSIVEL REALOCAR MEMORIA\n");
        exit(1);
    }

    strcat(str, aux);

    return str;
}

// Funcao que remove os nomes
char *rm(char *str)
{
    clear();

    if (str[0] == '\0')
    {
        printf("Nenhum nome foi adicionado!\n");
        pause();
        return str;
    }
    
    list_name(str);

    int choice, counter = 1, deleted_size = 0;
    int size_string = strlen(str) + 1;
    char *remnant;

    printf("\nQual nome sera removido? Escolha um numero: ");
        scanf("%d", &choice);

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.')
        {
            if (counter == choice)
            {
                str[i] = '@';
                remnant = &str[i+1];
            }
            counter++;
        } else
        {
            if (counter == choice)
            {
                str[i] = '@';
            }
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '@')
        {
            deleted_size++;
        }
    }
    
    
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '@')
        {
            strcpy(&str[i],remnant);
        }
    }

    if ((str = (char*)realloc(str, (size_string - deleted_size) * sizeof(char))) == NULL)
    {
        printf("ERROR: IMPOSSIVEL REALOCAR MEMORIA\n");
        exit(1);
    }

    return str;
}

//Funcao que imprime os nomes
void list_name(char *str)
{
    int index = 1;
    
    printf("Lista de Nome:\n");
        if (str[0] == '\0')
    {
        printf("Nenhum nome foi adicionado!\n");
        pause();
        return;
    } else
    {
        printf("%d. ", index);
        index++;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '.')
        {
            printf("%c", str[i]);
        } else
        {
            printf("\n");
            if (str[i + 1] != '\0')
            {
                printf("%d. ", index);
                index++;
            }
        }
    }
    pause();
}