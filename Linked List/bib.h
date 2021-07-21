#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct person {
    char name[MAX];
    char address[MAX];
    char cpf[MAX];
    int age;
} Person;

typedef struct node {
    Person data;
    struct node *next;
    struct node *previous;
} LinkedList;

void pause();
void clear();

int menu(LinkedList *head);
int searchMenu(LinkedList *head);

void readString(char *word, int size);

void reset(LinkedList *head);
int empty(LinkedList *head);
void clearList(LinkedList *body);
void fillData(LinkedList *body);
void push(LinkedList *head);
void pop(LinkedList *head);
void searchName(LinkedList *head);
void searchAddress(LinkedList *head);
void listContacts(LinkedList *head);
void reverseList(LinkedList *head);