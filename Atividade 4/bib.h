#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0

struct timeval begin, end;

typedef struct variaveis {
    char c;
    int i, j, aux;

    int indexMenor;
    
    int *vetor;
    int tamanho, escolha;
    
    time_t t;
    double elapsed;
    long sec, microSec;
} Variaveis;

void pause();
void clearScreen();

int menu(Variaveis *var);
int verifyArray(Variaveis *var);

void reset(Variaveis *var);
void newArray(Variaveis *var);
void printArray(Variaveis *var);

void insertionSort(Variaveis *var);
void selectionSort(Variaveis *var);
