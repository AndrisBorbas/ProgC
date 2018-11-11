#include <stdio.h>
#include <stdlib.h>

typedef struct List_Element {
	struct List_Element * prev;
	int wasd;
	struct List_Element * next;
} List_Element;

List_Element *lista_letrehoz(void) {
	int szamok[] = { 8, 14, 13, 17, 1, 19, 16, 5, 3, -1 };
	List_Element *lis = NULL;

	for (int i = 0; szamok[i] != -1; ++i) {
		List_Element *u;
		u = (List_Element*)malloc(sizeof(List_Element));
		u->next = lis;
		u->wasd = szamok[i];
		lis = u;
	}
	return lis;
}

List_Element *list_rotate(List_Element *listptr) {
	List_Element* last = NULL;
	List_Element* current = NULL;
	List_Element* next = NULL;
	last = current;
	current = listptr;
	next = listptr->next;
	current = listptr;
	current->next = last;
	do {
		last = current;
		current = next;
		next = next->next;
		current->next = last;
	} while (next != NULL);
	return current;
}

void printlist(List_Element* listptr) {
	for (List_Element* current = listptr; current != NULL; current = current->next) {
		printf("%d ", current->wasd);
	}
	return;
}

void L10(void) {
	List_Element *eleje;

	eleje = lista_letrehoz();
	printlist(eleje);

	printf("\n");

	List_Element *rotated;
	rotated = eleje;
	rotated = list_rotate(rotated);
	printlist(rotated);

	return 0;
}