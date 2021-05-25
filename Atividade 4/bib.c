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
				printf("-----------------------\n");
				printf("Vetor desordenado: ");
				printArray(var);
				printf("-----------------------\n");

				gettimeofday(&begin, 0);
            	quickSort(var, 0, var->tamanho - 1);
				gettimeofday(&end, 0);

				printf("-----------------------\n");
				printf("Vetor ordenado:    ");
				printArray(var);
				printf("-----------------------\n");

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
				printf("-----------------------\n");
				printf("Vetor desordenado: ");
				printArray(var);
				printf("-----------------------\n");

				gettimeofday(&begin, 0);
            	mergeSort(var->vetor, 0, var->tamanho - 1);
				gettimeofday(&end, 0);

				printf("-----------------------\n");
				printf("Vetor ordenado:    ");
				printArray(var);
				printf("-----------------------\n");

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

void quickSort (Variaveis *var, int esq, int dir) {
	var->i = esq;
	var->j = dir;

	var->mid = var->vetor[(esq + dir)/2];

	do
	{
		while (var->vetor[var->i] < var->mid)
			var->i++;
		
		while (var->mid < var->vetor[var->j])
			var->j--;
		
		if (var->i <= var->j)
		{
			var->aux = var->vetor[var->i];
			var->vetor[var->i] = var->vetor[var->j];
			var->vetor[var->j] = var->aux;
			var->i++;
			var->j--;
		}
	} while (var->i <= var->j);
	
	if (esq < var->j)
		quickSort(var, esq, var->j);
	if (var->i < dir)
		quickSort(var, var->i, dir);
}

void merge(int vetor[], int inicio1, int fim1, int inicio2, int fim2){
	int *temp = (int*)malloc((fim2 + 1) * sizeof(int));
	if (!temp)
    {
        printf("\n\t[ERROR: IMPOSSIVEL ALOCAR MEMORIA]\n");
        exit(1);
    }

	int i, j, k;
	//início do primeiro grupo
	i = inicio1;
	//início do segundo grupo
	j = inicio2;
	k = 0;

	//Enquanto tiver elementos em ambos as os grupos
	while(i <= fim1 && j <= fim2)
	{
		//faz a ordenação de acordo com cada grupo
		if(vetor[i] < vetor[j])
			temp[k++] = vetor[i++];
		else
			temp[k++] = vetor[j++];
	}

	//Copia os elementos restantes do primeiro grupo
	while(i <= fim1)
		temp[k++] = vetor[i++];

	//Copia os elementos restantes do segundo grupo
	while(j <= fim2)
		temp[k++] = vetor[j++];

	//Transfere os elementos do vetor temporário para o original
	for(i = inicio1, j = 0; i <= fim2; i++, j++)
		vetor[i] = temp[j];

	free(temp);
}

void mergeSort(int vetor[], int inicio, int tam){

	if(inicio < tam)
	{
		int meio = (inicio + tam) / 2;

		//recursão esquerda
		mergeSort(vetor, inicio, meio);

		//recursão direita
		mergeSort(vetor, meio + 1, tam);

		//junta os dois grupos de vetores ordenados
		merge(vetor, inicio, meio, meio + 1, tam);
	}
}