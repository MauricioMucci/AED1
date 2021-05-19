#include "bib.h"

void pause() {
    setbuf(stdin, NULL);
	printf("\n\t[Clique no enter para continuar]\n");
	getchar();
}

void clearScreen() {
	system("cls || clear");
}

int menu(Variaveis* var) {

    clearScreen();

	printf("-----[ Menu ]-----\n");
    printf("1 - Quick sort\n");
    printf("2 - Merge sort\n");
    printf("3 - Insertion sort\n");
    printf("4 - Selection sort\n");
    printf("5 - Criar novo vetor\n");
    printf("6 - Sair\n");
    printf("Digite: ");
        scanf("%d", &var->escolha);
    setbuf(stdin, NULL);
    
    switch (var->escolha){
        case 1:
            clearScreen();
			if (!verifyArray(var))
            {
				gettimeofday(&begin, 0);
            	//quickSort(var);
				gettimeofday(&end, 0);

				var->sec = end.tv_sec - begin.tv_sec;
				var->microSec = end.tv_usec - begin.tv_usec;
				var->elapsed = var->sec + var->microSec*1e-6;
				printf("\n\t     [Time: %.6f seconds]\n", var->elapsed);
			}
            else
				printf("\n\t\t   [ORDENADO]\n");
			pause();
            break;
        case 2:
            clearScreen();
			if (!verifyArray(var))
            {
				gettimeofday(&begin, 0);
            	//mergeSort(var);
				gettimeofday(&end, 0);

				var->sec = end.tv_sec - begin.tv_sec;
				var->microSec = end.tv_usec - begin.tv_usec;
				var->elapsed = var->sec + var->microSec*1e-6;
				printf("\n\t     [Time: %.6f seconds]\n", var->elapsed);
			}
            else
				printf("\n\t\t   [ORDENADO]\n");
			pause();
			break;
        case 3:
			clearScreen();
			if (!verifyArray(var))
			{
				gettimeofday(&begin, 0);
            	insertionSort(var);
				gettimeofday(&end, 0);

				var->sec = end.tv_sec - begin.tv_sec;
				var->microSec = end.tv_usec - begin.tv_usec;
				var->elapsed = var->sec + var->microSec*1e-6;
				printf("\n\t     [Time: %.6f seconds]\n", var->elapsed);
			}
			else
				printf("\n\t\t   [ORDENADO]\n");
			pause();
			break;
        case 4:
			clearScreen();
			if (!verifyArray(var))
            {
				gettimeofday(&begin, 0);
            	selectionSort(var);
				gettimeofday(&end, 0);

				var->sec = end.tv_sec - begin.tv_sec;
				var->microSec = end.tv_usec - begin.tv_usec;
				var->elapsed = var->sec + var->microSec*1e-6;
				printf("\n\t     [Time: %.6f seconds]\n", var->elapsed);
			}
            else
				printf("\n\t\t   [ORDENADO]\n");
			pause();
			break;
        case 5:
			newArray(var);
			break;
        case 6:
			free(var->vetor);
			var->vetor = NULL;
			free(var);
			var = NULL;
			return 0;
        default:
            printf("\n\t[Tente novamente!]\n");
            pause();
            break;
    }

    return 1;
}

void printArray (Variaveis *var) {
	for (var->i = 0; var->i < var->tamanho; var->i++)
	{
		printf("[%d]", var->vetor[var->i]);
	}
	printf("\n");
}

void reset (Variaveis *var) {
	for (var->i = 0; var->i < var->tamanho; var->i++)
		{
			var->vetor[var->i] = rand()%100;
		}
	printf("\n\t   [Vetor criado com sucesso]\n");
	return;
}

int verifyArray (Variaveis *var) {
	for (var->i = 0; var->i < (var->tamanho - 1); var->i++)
	{
		for (var->j = (var->i + 1); var->j < var->tamanho; var->j++)
		{
			if (var->vetor[var->j] < var->vetor[var->i])
				return FALSE;
		}
	}

	return TRUE;
}


void newArray (Variaveis *var) {
	setbuf(stdin, NULL);
	printf("\nMesmo tamanho(Y/N)?\nR: ");
        var->c = getchar();

	if(var->c == 'Y' || var->c == 'y')
	{
		for (var->i = 0; var->i < var->tamanho; var->i++)
		{
			var->vetor[var->i] = rand()%100;
		}
		printf("\n\t   [Vetor criado com sucesso]\n");
		if (verifyArray(var))
		{
			printf("\n\t\t   [ORDENADO]\n");
		} else
		{
			printf("\n\t\t  [DESORDENADO]\n");
		}
		pause();
		getchar();
		return;
	}

	printf("Qual o novo tamanho do vetor?\nR: ");
		scanf("%d", &var->tamanho);

	var->vetor = (int*)realloc(var->vetor, var->tamanho * sizeof(int));
	if (!var->vetor)
	{
		printf("\n\t[ERROR: IMPOSSIVEL ALOCAR MEMORIA]\n");
		exit(1);
	}

	for (var->i = 0; var->i < var->tamanho; var->i++)
	{
		var->vetor[var->i] = rand()%100;
	}
	printf("\n\t   [Vetor criado com sucesso]\n");
	if (verifyArray(var))
	{
		printf("\n\t\t   [ORDENADO]\n");
	} else
	{
		printf("\n\t\t  [DESORDENADO]\n");
	}
	pause();
	return;
}

void insertionSort (Variaveis *var) {
	printf("-----------------------\n");
	printf("Vetor desordenado: ");
	printArray(var);
	printf("-----------------------\n");

	for (var->j = 1; var->j < var->tamanho; var->j++)
	{
		var->i = var->j - 1;
		var->aux = var->vetor[var->j];
		while ((var->i >= 0) && (var->aux < var->vetor[var->i]))
		{
			var->vetor[var->i + 1] = var->vetor[var->i];
			var->i--;
		}
		var->vetor[var->i + 1] = var->aux;
	}

	printf("-----------------------\n");
	printf("Vetor ordenado:    ");
	printArray(var);
	printf("-----------------------\n");
	return;
}

void selectionSort (Variaveis *var) {
	printf("-----------------------\n");
	printf("Vetor desordenado: ");
	printArray(var);
	printf("-----------------------\n");

	for (var->i = 0; var->i < (var->tamanho - 1); var->i++)
	{
		var->indexMenor = var->i;
		for (var->j = (var->i + 1); var->j < var->tamanho; var->j++)
		{
			if (var->vetor[var->j] < var->vetor[var->indexMenor])
				var->indexMenor = var->j;
		}
		if (var->i != var->indexMenor)
		{
			var->aux = var->vetor[var->i];
			var->vetor[var->i] = var->vetor[var->indexMenor];
			var->vetor[var->indexMenor] = var->aux;
		}
	}
	
	printf("-----------------------\n");
	printf("Vetor ordenado:    ");
	printArray(var);
	printf("-----------------------\n");
	return;
}