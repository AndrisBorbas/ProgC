#include <stdio.h>

typedef struct DinamikusSor {
	int* sor;
	int meret;
}DinamikusSor;

DinamikusSor ujnemparosit(DinamikusSor s) {
	int db = 0;
	DinamikusSor uj = { NULL,0 };
	for (int i = 0; i < s.meret; i++) {
		if ((s.sor[i] % 2) == 1) {
			uj.sor = realloc(uj.sor, sizeof(int)*(db + 1));
			uj.sor[db] = s.sor[i];
			uj.meret = db + 1;
			db++;
		}
	}
	return uj;
}

void nemparosit(DinamikusSor* s) {
	int db = 0;
	DinamikusSor* uj = malloc(sizeof(DinamikusSor));
	uj->sor = NULL;
	uj->meret = 0;
	for (int i = 0; i < s->meret; i++) {
		if ((s->sor[i] % 2) == 1) {
			uj->sor = realloc(uj->sor, sizeof(int)*(db + 1));
			uj->sor[db] = s->sor[i];
			uj->meret = db + 1;
			db++;
		}
	}
	/*s->sor = malloc(sizeof(int)*(db));
	for (int i = 0; i <= db; i++) {
		s->sor[i] = uj->sor[i];
	}
	s->meret = db;
	free(uj);*/

	s = uj;
}

void madarosit(DinamikusSor* s) {
	int db = 0;
	DinamikusSor* uj = malloc(sizeof(DinamikusSor));
	uj->sor = NULL;
	uj->meret = 0;
	for (int i = 0; i < s->meret; i++) {
		if ((s->sor[i] % 2) == 1) {
			uj->sor = realloc(uj->sor, sizeof(int)*(db + 1));
			uj->sor[db] = s->sor[i];
			uj->meret = db + 1;
			db++;
			uj->sor = realloc(uj->sor, sizeof(int)*(db + 1));
			uj->sor[db] = 0;
			uj->meret = db + 1;
			db++;
			uj->sor = realloc(uj->sor, sizeof(int)*(db + 1));
			uj->sor[db] = s->sor[i];
			uj->meret = db + 1;
			db++;
		}
		else {
			uj->sor = realloc(uj->sor, sizeof(int)*(db + 1));
			uj->sor[db] = s->sor[i];
			uj->meret = db + 1;
			db++;
		}
	}
	s->sor = malloc(sizeof(int)*(db));
	for (int i = 0; i <= db; i++) {
		s->sor[i] = uj->sor[i];
	}
	s->meret = db;
	free(uj);

	//s = uj;
}

void kiir(DinamikusSor s) {
	for (int i = 0; i < s.meret; i++) {
		printf("%d", s.sor[i]);
	}
}

void kzh6() {
	DinamikusSor s = { NULL,8 };
	s.sor = malloc(sizeof(int) * 8);
	s.sor[0] = 0;
	s.sor[1] = 1;
	s.sor[2] = 2;
	s.sor[3] = 3;
	s.sor[4] = 4;
	s.sor[5] = 5;
	s.sor[6] = 6;
	s.sor[7] = 7;
	//s = ujnemparosit(s);
	//kiir(s);
	printf("\n");
	nemparosit(&s);
	kiir(s);
}