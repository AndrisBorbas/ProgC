#include <stdio.h>
#include <stdlib.h>

char* kar_beolvas(int* db, char* string) {
	(*db)=(*db)+1;
	char kar;
	scanf("%c", &kar);
	if (kar == 10) {
		string = (char*) malloc((*db)*sizeof(char));
		string[(*db)-1] = '\0';
		return string;
	}
	string=kar_beolvas(db, string);
	(*db) = (*db) - 1;
	string[(*db)-1]=kar;
	return string;
}

char* sort_beolvas(void) {
	int db = 0;
	return kar_beolvas(&db, NULL);
}