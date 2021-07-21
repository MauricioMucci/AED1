#include "bib.h"

void pause() {

	printf("\n\t[ Press any key to continue ]\n");
	getchar();
}

void clear() {

	system("cls || clear");
}

void readString(char *word, int size) {

    char c;
    int i = 0;

	c = getchar();
	while ((c != '\n') && (i < size))
    {
		word[i++] = c;
		c = getchar();
	}
	word[i] = '\0';

	if (c != '\n')
    {
		c = getchar();
		while ((c != '\n') && (c != EOF))
        {
			c = getchar();
		}
	}
}

int menu(LinkedList *head) {
    
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
    setbuf(stdin,NULL);
  
    switch (choice)
    {
    case 1:
        push(head);
        break;
    case 2:
        pop(head);
        break;
    case 3:
        while(searchMenu(head));
        break;
    case 4:
        listContacts(head);
        break;
    case 5:
        reverseList(head);
        break;
    case 6:
        clearList(head);
        free(head);
        return 0;
    default:
        printf("\n\t[ ... ]\n");
        pause();
        break;
    }

    return 1;
}

int searchMenu(LinkedList *head) {
    
    clear();
    unsigned short int choice;

    printf("-----[ Search Menu ]-----\n");
    printf("1. Name\n");
    printf("2. Address\n");
    printf("3. Exit\n");
    printf("Pick one: ");
        scanf("%hd", &choice);
    setbuf(stdin,NULL);

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

void reset(LinkedList *head) {

    head->next = NULL;
    head->previous = NULL;
}

int empty(LinkedList *head) {
    if (head->next == NULL)
    {
        return 1;
    }
    return 0;
}

void clearList(LinkedList *head) {
    if (!empty(head))
    {
        LinkedList *p, *n;
        p = head->next;
        while (p != NULL)
        {
            n = p->next;
            free(p);
            p = n;
        }
    }
}

void fillData(LinkedList *body) {

    clear();
    printf("\nName: ");
        readString(body->data.name,MAX);
    printf("Address: ");
        readString(body->data.address,MAX);
    printf("CPF: ");
        readString(body->data.cpf,MAX);
    printf("Age: ");
        scanf("%d", &body->data.age);
    setbuf(stdin, NULL);
}

void push(LinkedList *head) {

    LinkedList *body;
    body = (LinkedList*)malloc(sizeof(LinkedList));
    if (!body)
    {
        printf("\n\t[ ERROR: IMPOSSIBLE TO ALLOCATE MEMORY ]\n");
        exit(1);
    }
    
    if (empty(head))
    {
        head->next = body;
        fillData(body);
        body->next = NULL;
        body->previous = NULL;
    } else
    {
        LinkedList *tmp;
        for (tmp = head->next; tmp->next != NULL; tmp = tmp->next);
        tmp->next = body;
        body->previous = tmp;
        fillData(body);
        body->next = NULL;
    }
    
}

void pop(LinkedList *head) {

    clear();

    if (empty(head))
    {
        printf("\t\t[ No data... ]");
        pause();
        return;
    }

    char name[MAX];
    printf("Who are you going to remove?\n");
        readString(name,MAX);

    LinkedList *tmp, *body;
    for (tmp = head->next; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(name, tmp->data.name) == 0)
        {
            body = tmp->previous;
            body->next = tmp->next;
            free(tmp);
            printf("\t[ Record successfully removed ]\n");
            pause();
            return;
        }
    }
    printf("\t[ Record not found ]\n");
    pause();
}

void searchName(LinkedList *head) {
    
    clear();

    if (empty(head))
    {
        printf("\t\t[ No data... ]");
        pause();
        return;
    }

    char aux[MAX];
    printf("Who are you looking for?\n");
        readString(aux,MAX);
    
    LinkedList *tmp;
    for (tmp = head->next; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(aux, tmp->data.name) == 0)
            printf("\nName: %s\nAge: %d\nCPF: %s\nAddress: %s\n", tmp->data.name, tmp->data.age, tmp->data.cpf, tmp->data.address);
        
    }
    pause();
}

void searchAddress(LinkedList *head) {
    
    clear();

    if (empty(head))
    {
        printf("\t\t[ No data... ]");
        pause();
        return;
    }

    char aux[MAX];
    printf("What's the address you are looking for?\n");
        readString(aux,MAX);
    
    LinkedList *tmp;
    for (tmp = head->next; tmp != NULL; tmp = tmp->next)
    {
        if (strcmp(aux, tmp->data.address) == 0)
            printf("\nName: %s\nAge: %d\nCPF: %s\nAddress: %s\n", tmp->data.name, tmp->data.age, tmp->data.cpf, tmp->data.address);
        
    }
    pause();
}

void listContacts(LinkedList *head) {
    
    clear();
    if (empty(head))
    {
        printf("\t\t[ No data... ]");
        pause();
        return;
    }
    
    LinkedList *tmp;
    int i = 1;

    for (tmp = head->next; tmp != NULL; tmp = tmp->next)
    {
        printf("-----[ Record #%d ]-----\n", i++);
        printf("Name: %s\nAge: %d\nCPF: %s\nAddress: %s\n", tmp->data.name, tmp->data.age, tmp->data.cpf, tmp->data.address);
    }
    pause();
}

void reverseList(LinkedList *head) {
    
    if (empty(head))
    {
        printf("\t\t[ No data... ]");
        pause();
        return;
    }

    if (empty(head->next))
    {
        printf("\t[ There's only one record ]");
        pause();
        return;
    }
    
    LinkedList *tmp = NULL, *current = head->next;

    while (current != NULL)
    {
        tmp = current->previous;
        current->previous = current->next;
        current->next = tmp;
        current = current->previous;
    }

    if (tmp != NULL)
        head->next = tmp->previous;
    

    printf("\t[ The process was completed ]\n");
    pause();
}