#include "treeAVL.h"

int EhArvoreArvl(Tree *node) {
    int fb;
    
    if (node == NULL)
        return 1;
    
    if (!EhArvoreArvl(node->pLeft))
        return 0;
    
    if (!EhArvoreArvl(node->pRight))
        return 0;
    
    fb = balanceFactor(node);
    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;
    else
        return 1;
}

int main(int argc, char const *argv[])
{
    int i, qnt, randNum;
    time_t t;

    Tree **root;

    root = reset();

    srand((unsigned)time(&t));

    printf("Quantos nos serao colocados?\nR: ");
        scanf("%d", &qnt);

    clear();
    for (i = 0; i < qnt; i++)
    {
        randNum = rand()%100;
        push(root, randNum);
    }
    
    i = 0;
    printTree(*root, i);

    printf("\n\t[Altura = %d]\n", height(*root));

    if (EhArvoreArvl(*root))
        printf("\n\t  [AVL OK]\n");
    else
        printf("\n\t  [ERROR]\n");

    treeClear(root);

    return 0;
}