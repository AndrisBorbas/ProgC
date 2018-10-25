#include <stdio.h>
#include <stdarg.h>

void L71();
void L72(char*, int);

void L7() {
	L71();
}

void L71() {
	int db;
	scanf("%d", &db);
	char* szamok;
	szamok = malloc((db+1) * sizeof(char));
	for (int i = 0; i < db+1; i++) {
		scanf("%c", &szamok[i]);
	}
	L72(szamok, db);
	free(szamok);

}

void L72(char* szamok, int db) {
	for (int i = db ; i >= 0; i--) {
		printf("%c", szamok[i]);
	}
}