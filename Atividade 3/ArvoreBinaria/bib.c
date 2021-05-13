#include "bib.h"

void pause() {
	printf("\nClique no enter para continuar\n");
    getchar();
    setbuf(stdin, NULL);
}

void limpa() {
	system("cls || clear");
}

int menu(Pointer* root, Variaveis* var) {

    limpa();

	printf("-----[ Menu ]-----\n");
    printf("1 - Incluir\n");
    printf("2 - Remover\n");
    printf("3 - Listar\n");
    printf("4 - Buscar\n");
    printf("5 - Sair\n");
    printf("Digite: ");
        scanf("%hd", &var->escolha);
    setbuf(stdin, NULL);
    
    switch (var->escolha){
        case 1:
            limpa();
            printf("Digite o numero a ser inserido: ");
                scanf("%d", &var->numero);
            setbuf(stdin, NULL);
            push(root, var->numero);
            break;
        case 2:
            limpa();
            printf("Digite o numero a ser excluido: ");
                scanf("%d", &var->numero);
            setbuf(stdin, NULL);
            removeNo(root, var->numero);
            break;
        case 3:
            while(menu_print(root,var) == 1);
            break;
        case 4:
            limpa();
            printf("Digite o numero a ser procurado: ");
                scanf("%d", &var->numero);
                setbuf(stdin, NULL);
            search(*root, var->numero);
            break;
        case 5:
            limpa();
            clear(root);
            printf("\t[Arvore Deletada]\n");
            pause();
            return 0;
        default:
            printf("\nTente novamente!\n");
            pause();
            break;
    }

    return 1;
}

int menu_print(Pointer* root, Variaveis* var) {
    
    limpa();

	printf("-----[ Menu ]-----\n");
    printf("1 - Pre-order\n");
    printf("2 - Central\n");
    printf("3 - Pos-ordem\n");
    printf("4 - Voltar\n");
    printf("Digite: ");
        scanf("%hd", &var->escolha);
    setbuf(stdin, NULL);
    
    switch (var->escolha){
        case 1:
            limpa();
            preOrder(root);
            pause();
            break;
        case 2:
            limpa();
            inOrder(root);
            pause();
            break;
        case 3:
            limpa();
            posOrder(root);
            pause();
            break;
        case 4:
            return 0;
        default:
            printf("\nTente novamente!\n");
            pause();
            break;
    }
    return 1;
}

void reset(Pointer* root) {
    *root = NULL;  
}

void pop(struct tree* root) {
    if (!root)
        return;
    pop(root->pLeft);
    pop(root->pRight);
    free(root);
    root = NULL;
}

void clear(Pointer* root) {
    if (!root)
        return;
    
    pop(*root);
    free(root);   
}

void preOrder(Pointer* root) {
    if (!root)
        return;
    if (*root != NULL)
    {
        printf("%d\n", (*root)->data);
        preOrder(&(*root)->pLeft);
        preOrder(&(*root)->pRight);
    }
}

void inOrder(Pointer* root) {
    if (!root)
        return;
    if (*root != NULL)
    {
        inOrder(&(*root)->pLeft);
        printf("%d\n", (*root)->data);
        inOrder(&(*root)->pRight);
    }
}

void posOrder(Pointer* root) {
    if (!root)
        return;
    if (*root != NULL)
    {
        posOrder(&(*root)->pLeft);
        posOrder(&(*root)->pRight);
        printf("%d\n", (*root)->data);
    }
}

void push(Pointer* root, int num) {
    if (!(*root))
    {
        /*
            Aloca memoria do tipo ponteiro para cada no
            Pointer = struct tree*
        */
        *root = (Pointer)malloc(sizeof(struct tree)); 
        (*root)->data = num;                          
        (*root)->pLeft = NULL;
        (*root)->pRight = NULL;
        return;
    }
    if (num < (*root)->data)
    {
        push(&(*root)->pLeft, num);
        return;
    }
    if (num > (*root)->data)
    {
        push(&(*root)->pRight, num);
        return;
    } else {
        printf("\n\t[Valor Ja Existe]\n");
        pause();
    }
}

void removeNo(Pointer* root, int num) {
    Pointer aux;
    
    if (!(*root))
    {
        printf("\t[Arvore Vazia]\n");
        pause();
        return;
    }

    // Procura o no
    if (num < (*root)->data)
    {
        removeNo(&(*root)->pLeft, num);
        return;
    }
    if (num > (*root)->data)
    {
        removeNo(&(*root)->pRight, num);
        return;
    }

    // if(num == (*root)->data)
    // Exclui o no
    if (!((*root)->pRight)) // Se nao ha elemento a direita da "raiz", entao elimino o no "raiz" e "raiz" se torna o mais a esquerda
    {
        aux = *root;
        *root = (*root)->pLeft;
        free(aux);
        return; 
    }
    if ((*root)->pLeft != NULL) // Se existir um elemento a esquerda da "raiz"
    {
        exclui(*root, &(*root)->pLeft);
        return;
    }
    // if(!((*root)->pLeft)) --- Se nao ha elemento a esquerda da "raiz", entao elimino o no "raiz" e "raiz" se torna o mais a direita
    aux = *root;
    *root = (*root)->pRight;
    free(aux);
    
}

void exclui(Pointer noCentral, Pointer* no) {
    Pointer aux;

    if ((*no)->pRight != NULL) // Se existir um elemento a direita do filho a esquerda da "raiz"
    {
        exclui(noCentral, &(*no)->pRight); // Troca sempre sera feita com o mais a direita da esquerda
        return;
    }

    // Feita a substituicao do noCentral para o elemento mais a direita da esquerda
    noCentral->data = (*no)->data; 
    aux = *no;
    *no = (*no)->pLeft;
    free(aux);
}

void search(struct tree* root, int num) {

    if (root == NULL)
    {    
        printf("\n\t[Valor Nao Existe]\n");
        pause();
        return;
    }
    if (num < root->data)
    {
        search(root->pLeft,num);
        return;
    } 
    if (num > root->data)
    {
        search(root->pRight,num);
        return;
    } else {
        printf("\n\t[Valor Encontrado]\n");
        pause();
    }
}