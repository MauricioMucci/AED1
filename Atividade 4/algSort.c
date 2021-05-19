#include "bib.h"

int main(int argc, char const *argv[]) {
    
    Variaveis *var;

    var = (Variaveis*)malloc(sizeof(Variaveis));
    if (!var)
    {
        printf("\n\t[ERROR: IMPOSSIVEL ALOCAR MEMORIA]\n");
        exit(1);
    }
    
    clearScreen();
    printf("Qual o tamanho do vetor?\nR: ");
        scanf("%d", &var->tamanho);
    
    var->vetor = (int*)malloc(var->tamanho * sizeof(int));
    if (!var->vetor)
    {
        printf("\n\t[ERROR: IMPOSSIVEL ALOCAR MEMORIA]\n");
        exit(1);
    }
    
    srand((unsigned)time(&var->t));

    reset(var);

    if (!verifyArray(var))
		printf("\n\t\t  [DESORDENADO]\n");
	
	pause();

    while (menu(var));

    return 0;
}
