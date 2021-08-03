#include "priority_queue.h"

void pause()
{

    printf("\n\t[ Press any key to continue ]\n");
    getchar();
}

void clear()
{

    system("cls || clear");
}

int menu(Queue *fila)
{

    clear();
    unsigned short int choice;

    printf("-----[ Menu ]-----\n");
    printf("1. Add\n");
    printf("2. Remove\n");
    printf("3. List\n");
    printf("4. Search\n");
    printf("5. Exit\n");
    printf("Pick one: ");
    scanf("%hd", &choice);
    setbuf(stdin, NULL);

    switch (choice)
    {
    case 1:
        push(fila);
        break;
    case 2:
        pop(fila);
        break;
    case 3:
        listQueue(fila);
        break;
    case 4:
        search(fila);
        break;
    case 5:
        clearQueue(fila);
        return 0;
    default:
        printf("\n   [ Try an available option next time;) ]\n");
        pause();
        break;
    }

    return 1;
}

void fillData(TypeQueue *nodo)
{
    clear();

    char aux[MAX];

    printf("\nName: ");
    fgets(aux, MAX, stdin);
    strtok(aux, "\n");
    nodo->data.name = (char *)malloc((strlen(aux) + 1) * sizeof(char));
    if (!nodo->data.name)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }
    strcpy(nodo->data.name, aux);

    printf("Age: ");
    scanf("%d", &nodo->data.age);
    setbuf(stdin, NULL);
}

void reset(Queue *fila)
{
    fila->start = NULL;
    fila->end = NULL;
    fila->size = 0;
}

int empty(Queue *fila)
{
    if (fila->size == 0)
    {
        return 1;
    }
    return 0;
}

void clearQueue(Queue *fila)
{
    while (!empty(fila))
    {
        pop(fila);
    }
}

void push(Queue *fila)
{

    if (fila->size == SIZE)
    {
        printf("\t\t[ Queue is Full ]\n");
        pause();
        return;
    }

    TypeQueue *nodo;
    nodo = (TypeQueue *)malloc(sizeof(TypeQueue));
    if (!nodo)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }

    fillData(nodo);

    if (empty(fila))
    {
        fila->start = nodo;
        fila->end = nodo;
        nodo->next = NULL;
    }
    else
    {
        TypeQueue **tracer = &(fila->start);
        while ((*tracer) && ((*tracer)->data.age >= nodo->data.age))
        {
            if (((*tracer)->data.age == nodo->data.age) && (strcmp(nodo->data.name, (*tracer)->data.name) < 1))
                break;
            tracer = &(*tracer)->next;
        }

        nodo->next = (*tracer);
        (*tracer) = nodo;

        while (*tracer)
        {
            fila->end = (*tracer);
            tracer = &(*tracer)->next;
        }
    }

    fila->size++;
}

void pop(Queue *fila)
{

    clear();

    if (empty(fila))
    {
        printf("\t\t[ Empty Queue ]\n");
        pause();
        return;
    }

    TypeQueue *nodo = fila->start;

    if (fila->start == fila->end)
    {
        free(nodo->data.name);
        free(nodo);
        fila->start = NULL;
        fila->end = NULL;
    }
    else
    {
        TypeQueue *tracer;
        tracer = nodo->next;
        fila->start = tracer;
        free(nodo->data.name);
        free(nodo);
    }

    fila->size--;
}

void listQueue(Queue *fila)
{
    clear();

    if (empty(fila))
    {
        printf("\t\t[ Empty Queue ]\n");
        pause();
        return;
    }

    TypeQueue *tracer;
    int i = 1;
    for (tracer = fila->start; tracer != NULL; tracer = tracer->next)
    {
        printf("-----[ Queue #%d ]-----", i);
        printf("\nName: %s\nAge: %d\n\n", tracer->data.name, tracer->data.age);
        i++;
    }
    pause();
}

void search(Queue *fila)
{
    clear();

    if (empty(fila))
    {
        printf("\t\t[ Empty Queue ]\n");
        pause();
        return;
    }

    short int pos, i = 1;

    do
    {
        printf("\t[ Which position are you looking for? ]\n");
        printf("Type any number from 1-%hd: ", fila->size);
        scanf("%hd", &pos);
        setbuf(stdin, NULL);
        printf("\n");
    } while (pos < 1 || pos > fila->size);

    if (pos == 1)
    {
        printf("\n-----[ Queue #%d ]-----", pos);
        printf("\nName: %s\nAge: %d\n\n", fila->start->data.name, fila->start->data.age);
    }
    else if (pos == fila->size)
    {
        printf("\n-----[ Queue #%d ]-----", pos);
        printf("\nName: %s\nAge: %d\n\n", fila->end->data.name, fila->end->data.age);
    }
    else
    {
        TypeQueue *tracer = fila->start;
        while (i < pos)
        {
            tracer = tracer->next;
            i++;
        }
        printf("\n-----[ Queue #%d ]-----", i);
        printf("\nName: %s\nAge: %d\n\n", tracer->data.name, tracer->data.age);
    }
    pause();
}