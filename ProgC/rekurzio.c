#include <stdio.h>
#include <stdlib.h>

char* kar_beolvas(int db) {
	char kar;
	char* string = NULL;
	int beolvasott = scanf("%c", &kar);
	if (beolvasott != 1 || kar == '\n') {
		string = (char*)malloc((db + 1) * sizeof(char));
		string[db] = '\0';
		return string;
	}
	string = kar_beolvas(db + 1);
	string[db] = kar;
	return string;
}

char* sort_beolvas(void) {
	return kar_beolvas(0);
}