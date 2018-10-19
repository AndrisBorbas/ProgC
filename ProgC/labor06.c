#include <stdio.h>

//fibonacci szám kiszámolása
int fibonacci(int);

//kiírós fgv ek
void ax(char, int);
void ay(char, int);
int bx(char, int);
int by(char, int);


//main
void L6() {
	printf("%d", fibonacci(10));
	char tomb[50] = "Atomrakeeta";
	ax(tomb, sizeof(tomb));
	ay(tomb, sizeof(tomb));
	printf("\n");
	bx(tomb, sizeof(tomb));
	printf("\n");
	by(tomb, sizeof(tomb));
}

int fibonacci(int db) {
	if (db < 2)return db;
	else return fibonacci(db - 1) + fibonacci(db - 2);
}

void ax(char tomb[], int s) {
	printf("\n");
	for (int i = 0; i < s-1; i++) {
		printf("%c",tomb[i]);
	}
}

void ay(char tomb[], int s) {
	printf("\n");
	for (int i = s-1; i >= 0; i--) {
		printf("%c", tomb[i]);
	}
}

int bx(char tomb[], int s) {
	if (s = 0) {
		printf("%c", tomb[s]);
		return s;
	} else {
		printf("%c", tomb[bx(tomb, s)]);
		return s-1;
	}
}

int by(char tomb[], int s) {
	if (s = 0);
}