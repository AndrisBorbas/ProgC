#include <stdio.h>
#include <stdbool.h>

int* kivesz(int*, int);
char* charkivesz(char*, char);
int* nullkivesz(int*);

void KZH5() {
	int tomb[] = { 10,20,30,33,444,-1 };
	int* ujtomb = kivesz(tomb, 5);
	int i = 0;
	while (ujtomb[i] != -1) {
		printf("%d\n", ujtomb[i]);
		i++;
	}
	free(ujtomb);

	char ktomb[] = "almafafal";
	char * kujtomb = charkivesz(ktomb, 'a');
	i = 0;
	while (kujtomb[i] != '\0') {
		printf("%c", kujtomb[i]);
		i++;
	}
	free(kujtomb);

	int ntomb[] = { 0,0,0,0,0,0,0,2,1,2,3,2,0,0,32,0,-1 };
	int* nujtomb = nullkivesz(ntomb);
	i = 0;
	while (nujtomb[i] != -1) {
		printf("%d\n", nujtomb[i]);
		i++;
	}
	free(nujtomb);
}

int* kivesz(int* tomb, int oszto) {
	int i = 0, db = 1;
	int static *ujtomb;
	while (tomb[i] != -1) {
		if ((tomb[i] % oszto) != 0)
		{
			ujtomb = realloc(ujtomb, sizeof(int)*db);
			ujtomb[db - 1] = tomb[i];
			db++;
		}
		else
		{

		}
		i++;
	}
	ujtomb = realloc(ujtomb, sizeof(int)*(db));
	ujtomb[db - 1] = tomb[i];
	return ujtomb;
}

char* charkivesz(char* tomb, char k) {
	int i = 0, db = 1;
	char static *kujtomb;
	while (tomb[i] != '\0') {
		if (tomb[i] != k)
		{
			kujtomb = realloc(kujtomb, sizeof(char)*db);
			kujtomb[db - 1] = tomb[i];
			db++;
		}
		else
		{

		}
		i++;
	}
	kujtomb = realloc(kujtomb, sizeof(char)*(db));
	kujtomb[db - 1] = tomb[i];
	return kujtomb;
}

int* nullkivesz(int* tomb) {
	int i = 0, db = 1;
	bool nemnulla = true;
	int static *nujtomb;
	while (tomb[i] != -1) {
		if (nemnulla) {
			if (tomb[i] == 0) {
				i++;
				continue;
			}
			else {
				nemnulla = false;
			}
		}
		else {
			nujtomb = realloc(nujtomb, sizeof(int)*db);
			nujtomb[db - 1] = tomb[i];
			db++;
			i++;
		}
	}
	nujtomb = realloc(nujtomb, sizeof(int)*db);
	nujtomb[db - 1] = tomb[i];
	return nujtomb;
}