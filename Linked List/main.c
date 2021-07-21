#include "bib.h"

int main(int argc, char const *argv[]) {

    LinkedList *head;
    head = (LinkedList*)malloc(sizeof(LinkedList));
    if (!head)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }
    
    reset(head);
    while (menu(head));

    return 0;
}