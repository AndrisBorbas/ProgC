#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
	double i=-1;
	while (i <= 1) {
		printf("\n%0.4f %0.4f %0.4f %0.4f", i, kob(i), abszolut(i), sin(i));
		i = i+0.1;
	}
}

void L34F4() {

}

void L34() {
	L34F2();
	L34F3();
	L34F4();
}