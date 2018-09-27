#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

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

void L34F5() {
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
	printf("\n%s", versenyzok[1].helyezes <= 3 ? "igen" : "nem");
	printf("\n%s", versenyzok[4].helyezes < versenyzok[3].helyezes ? "igen" : "nem");
	printf("\n%s", versenyzok[1].szuletes.ev == versenyzok[2].szuletes.ev ? "igen" : "nem");

	for (int i = 0; i < 5; i++) {
		versenyzo_kiir(versenyzok[i]);
	}
}

int f0() {
	return 1;
}

int f1(int a) {
	return a + 1;
}

int f2(int a) {
	return -a;
}

int f3(int a) {
	return a * 2;
}

void L34F6() {
	int a = 1, x;
	bool isExit = false;
	do {
		printf("\n%d", a);
		printf("\n0: Alapertelmezettek visszaallitasa (a=1)\n1: Hozzaad 1-et\n2: Megforditja az elojelet\n3: Szorozza 2-vel\n9: Kilepes\n");
		scanf("%d", &x);
		switch (x) {
		default: break;
		case 0:
			a = f0();
			break;
		case 1:
			a = f1(a);
			break;
		case 2:
			a = f2(a);
			break;
		case 3:
			a = f3(a);
			break;
		case 9:
			isExit = true;
			break;
		}
	} while (!isExit);
}

void L34() {
	L34F2();
	L34F3();
	L34F4();
	L34F5();
	L34F6();
}