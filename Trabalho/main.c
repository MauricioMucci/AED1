#include "agenda.h"

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