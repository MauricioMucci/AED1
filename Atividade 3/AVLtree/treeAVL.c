#include "treeAVL.h"

void pause() {
	printf("\nClique no enter para continuar\n");
    getchar();
}

void clear() {
	system("cls || clear");
}

Tree **reset() {
    Tree **root = (Tree**)malloc(sizeof(Tree*));
    if (!root)
    {
        printf("ERROR: IMPOSSIVEL ALOCAR MEMORIA!");
        pause();
        exit(1);
    }
    *root = NULL;
    return root;
}

void nodeClear(Tree *node) {
    if (!node)
        return;
    
    nodeClear(node->pLeft);
    nodeClear(node->pRight);
    free(node); 
}

void treeClear(Tree **root) {
    if (!root)
        return;

    nodeClear(*root);
    free(root);
}

int height(Tree *node) {
    if (!node)
        return 0;

    int heightLeft = height(node->pLeft);
    int heightRight = height(node->pRight);

    return (heightLeft > heightRight) ? (heightLeft + 1) : (heightRight + 1);
}

int balanceFactor(Tree *node) {
    if (!node)
        return 0;

    return height(node->pLeft) - height(node->pRight);
}

void simpleRotationLeft(Tree **root) {
    Tree *aux;

    aux = (*root)->pRight;
    (*root)->pRight = aux->pLeft;
    aux->pLeft = (*root);
    (*root) = aux;
}

void simpleRotationRight(Tree **root) {
    Tree *aux;

    aux = (*root)->pLeft;
    (*root)->pLeft = aux->pRight;
    aux->pRight = (*root);
    (*root) = aux;
}

// "Pesado" na esquerda ou "Joelho" apontando a esquerda
int leftBalance(Tree **root) {
    int leftFB = balanceFactor((*root)->pLeft);

    if (leftFB > 0)
    {
        simpleRotationRight(root);
        return 1;
    } else
    {
        if (leftFB < 0)
        {
            //Rotacao Dupla a Direita
            simpleRotationLeft(&(*root)->pLeft);
            simpleRotationRight(&(*root));
            return 1;
        }
    }
    return 0;
}

// "Pesado" na direita ou "Joelho" apontando a direita
int rightBalance(Tree **root) {
    int rightFB = balanceFactor((*root)->pRight);

    if (rightFB < 0)
    {
        simpleRotationLeft(root);
        return 1;
    } else
    {
        if (rightFB > 0)
        {
            //Rotacao Dupla a Esquerda
            simpleRotationRight(&(*root)->pRight);
            simpleRotationLeft(&(*root));
            return 1;
        }
    }
    return 0;
}

int balance(Tree **root) {
    int FB = balanceFactor(*root);

    if (FB > 1)
    {
        return leftBalance(root);
    } else 
    {
        if (FB < -1)
        {
            return rightBalance(root);
        }
    }
    return 0;
}

Tree *smallest(Tree *node) {
    Tree *aux1 = node;
    Tree *aux2 = node->pLeft;

    while (aux2)
    {
        aux1 = aux2;
        aux2 = aux2->pLeft;
    }
    
    return aux1;
}

// veterano Hector me ajudou com o codigo de impressao
void printTree(Tree *node, int tmp) {
    if (!node)
        return;

    int i;
    tmp += 1;
    printTree(node->pRight, tmp);

    for (i = 0; i < tmp; i++)
        printf("\t");

    printf("%d\n", node->data);
    
    printTree(node->pLeft, tmp);

    return;
}

int push(Tree **root, int num) {
    if (!(*root))
    {
        Tree *node = (Tree*)malloc(sizeof(Tree));
        if (!node)
        {
            printf("ERROR: IMPOSSIVEL ALOCAR MEMORIA!");
            pause();
            exit(1);
        }

        node->data = num;
        node->pLeft = NULL;
        node->pRight = NULL;

        *root = node;

        return 1;
    } else
    {
        if((*root)->data > num)
        {
            if (push(&(*root)->pLeft, num))
            {
                if (balance(root))
                    return 0;
                else
                    return 1;
            }
        } else
        {
            if ((*root)->data < num)
            {
                if (push(&(*root)->pRight, num))
                {
                    if (balance(root))
                        return 0;
                    else
                        return 1;
                }
            } else
            {
                printf("\n\t[Valor ja inserido!]\n");
                pause();
                return 0;
            }
        }
    } 
    return 0;
}

int pop(Tree **root, int num) {
    if (!(*root))
        return 0;

    if (num < (*root)->data)
    {
        if (pop(&(*root)->pLeft, num))
        {
            if (balance(root))
                return 0;
            else
                return 1;
        
        }         
    } else
    {
        if (num > (*root)->data)
        {
            if (pop(&(*root)->pRight, num))
            {
                if (balance(root))
                    return 0;
                else
                    return 1;
            }
        }
    }

    if (num == (*root)->data)
    {
        if ((*root)->pLeft == NULL || (*root)->pRight == NULL)
        {
            Tree *aux = *root;

            if ((*root)->pRight)
                (*root) = (*root)->pRight;
            else
                (*root) = (*root)->pLeft;

            free(aux);
            return 1;
        } else
        {
            Tree *aux = smallest((*root)->pRight);

            (*root)->data = aux->data;

            pop(&(*root)->pRight, aux->data);

            balance(root);
        }
        return 1;
    }
    
    return 1;
}

void search(Tree **root, int num) {

    if (!(*root))
    {    
        printf("\n\t[Valor Nao Existe]\n");
        pause();
        return;
    }
    if (num < (*root)->data)
    {
        search(&(*root)->pLeft,num);
        return;
    } 
    if (num > (*root)->data)
    {
        search(&(*root)->pRight,num);
        return;
    } else {
        printf("\n\t[Valor Encontrado]\n");
        pause();
        return;
    }
}