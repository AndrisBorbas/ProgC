#include <stdio.h>
#include <stdlib.h>

void rnd() {
	srand(1);
	printf("%d\n%d", rand(), rand());
}