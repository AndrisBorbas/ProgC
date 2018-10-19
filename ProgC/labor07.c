#include <stdio.h>
#include <stdarg.h>

void L71();
void L72(double*, int);

void L7() {
	L71();
}

void L71() {
	int db;
	scanf("%d", &db);
	double* szamok = malloc(db * sizeof(double));
	for(int i=0;i<db;i++){
		scanf("%lf", &szamok[i]);
	}	
	L72(szamok, db);
	free(szamok);

}

void L72(double* szamok, int db) {
	for (int i = db-1; i >= 0; i--) {
		printf("%g\n", szamok[i]);
	}
}