#include "bib.h"


int main(int argc, char const *argv[]){
    int escolha;

    LISTA *head;

    head = cria();

    for(;;){
        clear();

        escolha = menu();
        switch (escolha)
        {
            case 1:
                incluir(head);
                break;
            case 2:
                listar(head);
                break;
            case 3:
                libera(head);
				free(head);
				clear();
                return 0;
        }
    }
}
