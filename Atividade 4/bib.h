#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0

struct timeval begin, end;

typedef struct variaveis {
    //Auxiliares
    char c;
    int i, j, aux;
    
    int *vetor;
    int tamanho, escolha;

    //Selection
    int indexMenor;

    //Quicksort
    int mid;
    
    //Cronometro
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
void quickSort (Variaveis *var, int esq, int dir);
void merge(int vetor[], int inicio1, int fim1, int inicio2, int fim2);
void mergeSort(int vetor[], int inicio, int tam);