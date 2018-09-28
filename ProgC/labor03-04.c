// ***********************************************************************
// Assembly         : 
// Author           : cxl20
// Created          : 09-24-2018
//
// Last Modified By : cxl20
// Last Modified On : 09-28-2018
// ***********************************************************************
// <copyright file="labor03-04.c" company="">
//     Copyright (c) . All rights reserved.
// </copyright>
// <summary></summary>
// ***********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

/// <summary>
/// Struct Datum
/// </summary>
typedef struct Datum {
	/// <summary>
	/// The ho
	/// </summary>
	int ev, ho, nap;
} Datum;

/// <summary>
/// Struct Versenyzo
/// </summary>
typedef struct Versenyzo {
	/// <summary>
	/// The nev
	/// </summary>
	char nev[31];
	/// <summary>
	/// The szuletes
	/// </summary>
	Datum szuletes;
	/// <summary>
	/// The helyezes
	/// </summary>
	int helyezes;
} Versenyzo;

/// <summary>
/// L34s the f2.
/// </summary>
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

/// <summary>
/// Kobs the specified valos.
/// </summary>
/// <param name="valos">The valos.</param>
/// <returns>double.</returns>
double kob(double valos) {
	return valos * valos * valos;
}

/// <summary>
/// Abszoluts the specified valos.
/// </summary>
/// <param name="valos">The valos.</param>
/// <returns>double.</returns>
double abszolut(double valos) {
	if (valos >= 0)return valos;
	else return valos * -1;
}

/// <summary>
/// L34s the f3.
/// </summary>
void L34F3() {
	double i = -1;
	while (i <= 1) {
		printf("\n%0.4f %0.4f %0.4f %0.4f", i, kob(i), abszolut(i), sin(i));
		i = i + 0.1;
	}
}

/// <summary>
/// Maganhangzoes the specified c.
/// </summary>
/// <param name="c">The c.</param>
/// <returns>bool.</returns>
bool maganhangzo(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	else return false;
}

/// <summary>
/// Nagybetus the specified c.
/// </summary>
/// <param name="c">The c.</param>
/// <returns>bool.</returns>
bool nagybetu(char c) {
	if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
		return true;
	else return false;
}

/// <summary>
/// L34s the f4.
/// </summary>
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

/// <summary>
/// Datums the kiir.
/// </summary>
/// <param name="d">The d.</param>
void datum_kiir(Datum d) {
	printf("\n%d.%d.%d", d.ev, d.ho, d.nap);
}

/// <summary>
/// Versenyzoes the kiir.
/// </summary>
/// <param name="v">The v.</param>
void versenyzo_kiir(Versenyzo v) {
	printf("\n%s, %d.%d.%d, %d", v.nev, v.szuletes.ev, v.szuletes.ho, v.szuletes.nap, v.helyezes);
}

/// <summary>
/// L34s the f5.
/// </summary>
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

/// <summary>
/// F0s this instance.
/// </summary>
/// <returns>int.</returns>
int f0() {
	return 1;
}

/// <summary>
/// F1s the specified a.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
int f1(int a) {
	return a + 1;
}

/// <summary>
/// F2s the specified a.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
int f2(int a) {
	return -a;
}

/// <summary>
/// F3s the specified a.
/// </summary>
/// <param name="a">a.</param>
/// <returns>int.</returns>
int f3(int a) {
	return a * 2;
}

/// <summary>
/// L34s the f6.
/// </summary>
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

/// <summary>
/// L34s this instance.
/// </summary>
void L34() {
	L34F2();
	L34F3();
	L34F4();
	L34F5();
	L34F6();
}