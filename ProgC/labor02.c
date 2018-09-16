#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void L2F3a() {
	int a = 1, n = 10;
	while (n >= 2) {
		//printf("cilkusvaltozo: %d\nszorzat: %d\n", n, a);
		a = a * n;
		n--;
	}
	printf("10 faktorialis: %d\n\n", a);
}

void L2F3b() {
	int a = 11220, b = 2002;
	while (b > 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	printf("lnko: %d\n\n", a);
}

void L2F4() {
	char betu;
	while (scanf("%c", &betu) == 1) {
		if (betu == 10)return 0;
		printf("betu: '%c', betukod= %d\n", betu, betu);
	}
}

void L2F5() {
	int tomb[10];
	for (int i = 0; i < 10; i++) {
		tomb[i] = i * 10;
	}
	int i = 0;
	while (i < 20) {
		printf("%d. elem: %d\n", i, tomb[i]);
		i++;
	}
}

void L2F6() {
	int tomb[10] = { 13, 21, 33, 54, 69, 3, 11, 12, 99, 98 };
	printf("A tomb:");
	for (int i = 0; i < 10; i++) {
		printf(" %d", tomb[i]);
	}
	printf("\nA tomb indexekkel:");
	for (int i = 0; i < 10; i++) {
		printf(" [%d]=%d", i, tomb[i]);
	}
	int minhely = 0;
	for (int i = 0; i < 10; i++) {
		if (tomb[i] <= tomb[minhely])minhely = i;
	}
	printf("\nLegkisebb: [%d]=%d", minhely, tomb[minhely]);
	printf("\nJelolve:");
	for (int i = 0; i < 10; i++) {
		if (i == minhely)printf(" [MIN]%d", tomb[i]);
		else printf(" %d", tomb[i]);
	}
}

void L2F7() {
	char szo[10] = { "Pitagorasz" };
	printf("\n\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i + j < 10)printf("%c ", szo[j + i]);
			else printf("%c ", szo[j + i-10]);
		}
		printf("\n");
	}
}