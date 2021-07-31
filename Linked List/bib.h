#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30
#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct person
{
    char *name;
    char *address;
    char *cpf;
    int age;
} Person;

typedef struct node
{
    Person data;
    struct node *next;
    struct node *previous;
} LinkedList;

void clear();
void pause();

int menu(LinkedList **head);
int searchMenu(LinkedList **head);

void fillData(LinkedList *body);
void clearList(LinkedList **head);
void listContacts(LinkedList **head);
void reverseList(LinkedList **head);

void pop(LinkedList **head);
void push(LinkedList **head);
void searchName(LinkedList **head);
void searchAddress(LinkedList **head);

void testaDoublyLinked(LinkedList **head);