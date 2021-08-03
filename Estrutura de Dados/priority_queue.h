#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define SIZE 20

typedef struct
{
    char *name;
    int age;
} Person;

typedef struct node
{
    Person data;
    struct node *next;
} TypeQueue;

typedef struct
{
    short int size;
    TypeQueue *start;
    TypeQueue *end;
} Queue;

void clear();
void pause();

int menu(Queue *fila);
int empty(Queue *fila);

void clearQueue(Queue *fila);
void fillData(TypeQueue *nodo);
void listQueue(Queue *fila);

void pop(Queue *fila);
void push(Queue *fila);
void reset(Queue *fila);
void search(Queue *fila);