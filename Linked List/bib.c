#include "bib.h"

void pause()
{

    printf("\n\t[ Press any key to continue ]\n");
    getchar();
}

void clear()
{

    system("cls || clear");
}

void clearList(LinkedList **head)
{
    LinkedList **tracer = head, *aux;

    while (*tracer)
    {
        aux = *tracer;
        *tracer = (*tracer)->next;
        free(aux->data.name);
        free(aux->data.address);
        free(aux->data.cpf);
        free(aux);
    }
}

int menu(LinkedList **head)
{

    clear();
    unsigned short int choice;

    printf("-----[ Menu ]-----\n");
    printf("1. Add\n");
    printf("2. Remove\n");
    printf("3. Search\n");
    printf("4. List\n");
    printf("5. Reverse\n");
    printf("6. Exit\n");
    printf("Pick one: ");
    scanf("%hd", &choice);
    setbuf(stdin, NULL);

    switch (choice)
    {
    case 1:
        push(head);
        break;
    case 2:
        pop(head);
        break;
    case 3:
        while (searchMenu(head))
            ;
        break;
    case 4:
        listContacts(head);
        break;
    case 5:
        //reverseList(head);
        testaDoublyLinked(head);
        break;
    case 6:
        clearList(head);
        return 0;
    default:
        printf("\n   [ Try an available option next time;) ]\n");
        pause();
        break;
    }

    return 1;
}

int searchMenu(LinkedList **head)
{

    clear();
    if (!(*head))
    {
        printf("\t\t[ Empty List ]\n");
        pause();
        return 0;
    }
    unsigned short int choice;

    printf("-----[ Search Menu ]-----\n");
    printf("1. Name\n");
    printf("2. Address\n");
    printf("3. Exit\n");
    printf("Pick one: ");
    scanf("%hd", &choice);
    setbuf(stdin, NULL);

    switch (choice)
    {
    case 1:
        searchName(head);
        break;
    case 2:
        searchAddress(head);
        break;
    case 3:
        return 0;
    default:
        printf("\n\t[ ... ]\n");
        pause();
        break;
    }

    return 1;
}

void fillData(LinkedList *body)
{
    clear();

    char aux[MAX];

    printf("\nName: ");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");
    body->data.name = (char *)malloc((strlen(aux) + 1) * sizeof(char));
    if (!body->data.name)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }
    strcpy(body->data.name, aux);

    printf("Address: ");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");
    body->data.address = (char *)malloc((strlen(aux) + 1) * sizeof(char));
    if (!body->data.address)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }
    strcpy(body->data.address, aux);

    printf("CPF: ");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");
    body->data.cpf = (char *)malloc((strlen(aux) + 1) * sizeof(char));
    if (!body->data.cpf)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }
    strcpy(body->data.cpf, aux);

    printf("Age: ");
    scanf("%d", &body->data.age);
    setbuf(stdin, NULL);
}

void push(LinkedList **head)
{

    LinkedList *body, **tracer = head;
    body = (LinkedList *)malloc(sizeof(LinkedList));
    if (!body)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }

    fillData(body);

    if (!(*tracer))
    {
        *tracer = body;
        body->previous = NULL;
        body->next = NULL;
    }
    else
    {
        while ((*tracer)->next)
        {
            tracer = &(*tracer)->next;
        }

        body->next = (*tracer)->next;
        body->previous = *tracer;
        (*tracer)->next = body;
    }
}

void pop(LinkedList **head)
{

    clear();

    BOOL exists = FALSE;
    LinkedList *old, **tracer = head;

    if (!(*tracer))
    {
        printf("\t\t[ Empty List ]\n");
        pause();
        return;
    }

    if (!((*tracer)->next))
    {
        clearList(head);
        return;
    }

    char name[MAX];
    printf("Type the name to be removed: ");
    fgets(name, MAX, stdin);
    strtok(name, "\n");

    while ((*tracer) && !(exists = (strcmp(name, (*tracer)->data.name) == 0)))
    {
        tracer = &(*tracer)->next;
    }

    if (exists)
    {
        old = *tracer;
        *tracer = (*tracer)->next;
        if ((*tracer))
            (*tracer)->previous = old->previous;

        free(old->data.name);
        free(old->data.address);
        free(old->data.name);
        free(old);
    }
    else
    {
        printf("\t  [ Record doesn't exist ]\n");
        pause();
    }
}

void searchName(LinkedList **head)
{

    clear();

    char aux[MAX];
    printf("Who are you looking for?\n");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");

    LinkedList **tracer = head;
    while (*tracer)
    {
        if (strcmp(aux, (*tracer)->data.name) == 0)
        {
            printf("\nName: %s\nAge: %d\nCPF: %s\nAddress: %s\n\n", (*tracer)->data.name, (*tracer)->data.age, (*tracer)->data.cpf, (*tracer)->data.address);
            pause();
            return;
        }
        tracer = &(*tracer)->next;
    }
    printf("\t  [ Record doesn't exist ]\n");
    pause();
}

void searchAddress(LinkedList **head)
{

    clear();

    char aux[MAX];
    printf("What's the address you are looking for?\n");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");

    LinkedList **tracer = head;
    while (*tracer)
    {
        if (strcmp(aux, (*tracer)->data.address) == 0)
        {
            printf("\nName: %s\nAge: %d\nCPF: %s\nAddress: %s\n\n", (*tracer)->data.name, (*tracer)->data.age, (*tracer)->data.cpf, (*tracer)->data.address);
            pause();
            return;
        }
        tracer = &(*tracer)->next;
    }
    printf("\t  [ Record doesn't exist ]\n");
    pause();
}

void listContacts(LinkedList **head)
{

    clear();

    LinkedList **tracer = head;
    if (!(*tracer))
    {
        printf("\t\t[ Empty List ]\n");
        pause();
        return;
    }

    int i = 1;
    while (*tracer)
    {
        printf("-----[ Record #%d ]-----", i);
        printf("\nName: %s\nAge: %d\nCPF: %s\nAddress: %s\n\n", (*tracer)->data.name, (*tracer)->data.age, (*tracer)->data.cpf, (*tracer)->data.address);
        i++;
        tracer = &(*tracer)->next;
    }
    pause();
}

void reverseList(LinkedList **head)
{
    LinkedList **tracer = head;
    if (!(*tracer))
    {
        printf("\t\t[ Empty List ]\n");
        pause();
        return;
    }

    if (!((*tracer)->next))
    {
        printf("\t [ There's only one record ]");
        pause();
        return;
    }

    

    printf("\t[ The process was completed ]\n");
    pause();
}

void testaDoublyLinked(LinkedList **head)
{
    clear();

    LinkedList **tracer = head;
    if (!(*tracer))
    {
        printf("\t\t[ Empty List ]\n");
        pause();
        return;
    }

    char aux[MAX];
    printf("Who are you looking for?\n");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");

    if (strcmp(aux, (*tracer)->data.name) == 0)
    {
        return;
    }

    while (*tracer)
    {
        if (strcmp(aux, (*tracer)->data.name) == 0)
        {
            printf("\nName: %s\nAge: %d\nCPF: %s\nAddress: %s\n\n", (*tracer)->previous->data.name, (*tracer)->previous->data.age, (*tracer)->previous->data.cpf, (*tracer)->previous->data.address);
            pause();
            return;
        }
        tracer = &(*tracer)->next;
    }
    printf("\t  [ Record doesn't exist ]\n");
    pause();
}