#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct Datum {
	int ev, ho, nap;
} Datum;

typedef struct Versenyzo {
	char nev[31];
	Datum szuletes;
	int helyezes;
} Versenyzo;

void L34F2() {
	int j = 0, negativ[10] = { 0 };
	double szamok[10] = { 2.5, -69, 5.4, -8, -7.7, 6, 2.9, -10, -3, 9.8 };
	printf("Osszesen %d db szam van.\n", sizeof(szamok) / sizeof(double));
	for (int i = 0; i < sizeof(szamok) / sizeof(double); i++) {
		printf("[%d]=%g ", i, szamok[i]);
		if (szamok[i] < 0) {
			negativ[j] = i;
			j++;
		}
	}
	printf("\nEbbol %d szam negativ.\nIndexeik: ", j);
	for (int i = 0; i < j; i++) {
		//printf("%d ", negativ[i]);
		printf("[%d]=%g ", negativ[i], szamok[negativ[i]]);
	}
}

double kob(double valos) {
	return valos * valos * valos;
}

double abszolut(double valos) {
	if (valos >= 0)return valos;
	else return valos * -1;
}

void L34F3() {
	double i = -1;
	while (i <= 1) {
		printf("\n%0.4f %0.4f %0.4f %0.4f", i, kob(i), abszolut(i), sin(i));
		i = i + 0.1;
	}
}

bool maganhangzo(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	else return false;
}

bool nagybetu(char c) {
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	else return false;
}

void L34F4() {
	char c;
	int chardiff = 'a' - 'A';
	//printf("%d", chardiff);	
	printf("\n");
	while (scanf("%c", &c) != EOF) {
		if (c == 10)
			break;
		if (maganhangzo(c) == true) {
			if (nagybetu(c) == true)
				printf("%cv%c", c, c + chardiff);
			else printf("%cv%c", c, c);
		}
		else
			printf("%c", c);
	}
}

void datum_kiir(Datum d) {
	printf("\n%d.%d.%d", d.ev, d.ho, d.nap);
}

void versenyzo_kiir(Versenyzo v) {
	printf("\n%s, %d.%d.%d, %d", v.nev, v.szuletes.ev, v.szuletes.ho, v.szuletes.nap, v.helyezes);
}

int L34F5() {
	Versenyzo versenyzok[5] = {
		{ "Am Erika", {1984, 5, 6}, 1 },
		{ "Break Elek", {1982, 9, 30}, 3 },
		{ "Dil Emma", {1988, 8, 25}, 2 },
		{ "Kasza Blanka", {1979, 6, 10}, 5 },
		{ "Reset Elek", {1992, 4, 5}, 4 },
	};
	printf("\n%s", versenyzok[0].nev);
	printf("\n%d", versenyzok[2].helyezes);
	datum_kiir(versenyzok[4].szuletes);
	printf("\n%c", versenyzok[1].nev[0]);

	for (int i = 0; i < 5; i++) {
		versenyzo_kiir(versenyzok[i]);
	}
}



void L34() {
	L34F2();
	L34F3();
	L34F4();
	L34F5();
}