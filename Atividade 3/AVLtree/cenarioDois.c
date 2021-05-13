#include "treeAVL.h"

int main(int argc, char const *argv[])
{
    int escolha, numero, i;

    Tree **root;
    root = reset();

    for(;;) {
        clear();
        printf("-----[ Menu ]-----\n");
        printf("1 - Incluir\n");
        printf("2 - Remover\n");
        printf("3 - Listar\n");
        printf("4 - Buscar\n");
        printf("5 - Sair\n");
        printf("Digite: ");
            scanf("%d", &escolha);
        setbuf(stdin, NULL);
        
        switch (escolha){
            case 1:
                clear();
                printf("Digite o numero a ser inserido: ");
                    scanf("%d", &numero);
                setbuf(stdin, NULL);
                push(root, numero);
                break;
            case 2:
                clear();
                printf("Digite o numero a ser excluido: ");
                    scanf("%d", &numero);
                setbuf(stdin, NULL);
                pop(root, numero);
                break;
            case 3:
                i = 0;
                printf("\n");
                printTree(*root,i);
                pause();
                break;
            case 4:
                clear();
                printf("Digite o numero a ser procurado: ");
                    scanf("%d", &numero);
                    setbuf(stdin, NULL);
                search(root, numero);
                break;
            case 5:
                clear();
                treeClear(root);
                printf("\t[Arvore Deletada]\n");
                pause();
                return 0;
            default:
                printf("\nTente novamente!\n");
                pause();
                break;
        }
    }
}
