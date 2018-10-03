#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Megcseréli a két chart
void csere(char*, int, int);

//Megkeveri a szóban a betűket
void kever(char*, int);

//main
void szokevero() {
	char szo[50], szoveg[100000] = { '\0' };
	int n = sizeof(szo) / sizeof(szo[0]);
	//szavanként beolvas??
	while (scanf("%s", &szo)) {
		//"exit" re kiírja az eddig beírt szöveget
		if (strcmp(szo, "exit") == 0)break;

		kever(szo, n);

		//szöveg eltárolása
		strcat(szoveg, szo);
		strcat(szoveg, " ");
	}
	printf("%s", szoveg);
}


void csere(char* szo, int i, int j) {
	char temp = szo[i];
	szo[i] = szo[j];
	szo[j] = temp;
}

void kever(char* szo, int n) {
	srand(time(NULL));
	int db = 2;
	//írásjelek detektálása
	if (szo[strlen(szo) - 1] == '.' || szo[strlen(szo) - 1] == '!' || szo[strlen(szo) - 1] == '?' || szo[strlen(szo) - 1] == ',')db = 3;
	//... detektálása
	if (szo[strlen(szo) - 3] == '.')db = 5;
	for (int i = 1; i < strlen(szo) - db; i++) {
		// random index generálása cseréhez
		int j = rand() % (strlen(szo) - db) + 1;
		//karakterek megcserélése
		csere(szo, i, j);
	}
}