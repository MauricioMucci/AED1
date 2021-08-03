#include "priority_queue.h"

int main(int argc, char const *argv[])
{

    Queue *fila = (Queue *)malloc(sizeof(Queue));
    if (!fila)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }

    reset(fila);
    while (menu(fila))
        ;

    free(fila);
    return 0;
}