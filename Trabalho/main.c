#include "agenda.h"


int menu(Variaveis *var, Fila *fila){

    limpa();

	printf("-----[ Menu ]-----\n");
    printf("1 - Incluir\n");
    printf("2 - Remover\n");
    printf("3 - Listar\n");
    printf("4 - Esvaziar\n");
    printf("5- Sair\n");
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
            limpa();
            imprimir(fila, var);
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

int main(int argc, char const *argv[]){
    
    Variaveis *var;
    Fila *fila;

    pBuffer = malloc(sizeof(Variaveis) + sizeof(Fila));
    var = pBuffer;
    fila = pBuffer + sizeof(Variaveis);

    if (!pBuffer)
    {
        printf("ERROR: MEMORIA INSUFICIENTE");
        exit(1);
    }

    reset(fila);
    
    while(menu(var,fila) == 1);

    clear(fila);
    free(pBuffer);

    return 0;
}