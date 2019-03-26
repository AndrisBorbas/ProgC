#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///too eazy
/*int main(){
  char s[100]="", elozo[100]="",leghosszabb[100]="";
  while(scanf("%s", &s)!=EOF){
	if(strlen(s)>strlen(leghosszabb))strcpy(leghosszabb, s);
  }
  printf("%s", leghosszabb);
}*/

void hozzafuz(char **hova, char mit) {
	*hova = realloc(*hova, strlen(*hova)+2);
	(*hova)[strlen(*hova)+1] = 0;
	(*hova)[strlen(*hova)] = mit;
}

void zh2() {
	int c;
	char *leghosszabb = malloc(1), *aktualis = malloc(1);
	strcpy(aktualis, "");
	strcpy(leghosszabb, "");
	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			hozzafuz(&aktualis, c);
		}
		else {
			if (strlen(aktualis) > strlen(leghosszabb)) {
				strcpy(leghosszabb, aktualis);
			}
			strcpy(aktualis, "");
		}
	}
	printf("leghosszabb: %s\n", leghosszabb);
	free(aktualis);
	free(leghosszabb);
	return 0;
}
