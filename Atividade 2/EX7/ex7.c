#include "bib.h"

int main(int argc, char const *argv[])
{
    VAR *controle;

    if ((pbuffer = malloc(sizeof(VAR))) == NULL)
    {
        printf("ERROR: IMPOSSIVEL ALOCAR MEMORIA!");
        pause();
        exit(1);
    }
    
    controle = pbuffer;
    controle->tamanho_atual = 0;
    for (;;)
    {
        clear();

		printf("-----[ Menu ]-----\n");
        printf("1 - Incluir\n");
        printf("2 - Remover\n");
        printf("3 - Buscar\n");
        printf("4 - Listar\n");
        printf("5- Sair\n");
        printf("Digite: ");
            scanf("%d", &controle->escolha);
        setbuf(stdin,NULL);
        switch (controle->escolha)
        {
        case 1:
            clear();
            incluir();
            break;
        case 2:
            clear();
            remover();
            break;
        case 3:
            clear();
            buscar();
            break;
        case 4:
            clear();
            listar();
            break;
        case 5:
            free(agenda);
            free(pbuffer);
            return 0;
        default:
            printf("Tente novamente!\n");
            pause();
            break;
        }
    }
}