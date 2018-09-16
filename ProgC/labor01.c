#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void labor01() {
	///3. feladat

	printf("Hello world!\n\n\n");

	///5. feladat

	printf("A printf(\"hello\\n\") kiirja, hogy \"hello\",\nes kezd egy uj sort.\n\n");
	printf("A \"%%d\" segitsegevel egy valtozo erteket tudjuk kiirni.\n\n\n");

	///6. feladat

	double tartalymagas, tartalyatmero;
	printf("Tartaly festese\n\nMilyen magas? ");
	scanf("%lf", &tartalymagas);
	printf("Mennyi az atmeroje? ");
	scanf("%lf", &tartalyatmero);
	printf("\n%f doboz festek kell.\n\n\n", (((tartalyatmero / 2)*(tartalyatmero / 2)*3.1416 * 2) + (tartalymagas*3.1416*(tartalyatmero / 2) * 2)) / 2);

	///7. feladat

	double a, b, c, x1, x2;
	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);
	if (sqrt(pow(b, 2) - 4 * a*c) >= 0)
	{
		x1 = (((b*-1) + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		x2 = (((b*-1) - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a));
		if (x1 == x2)
		{
			printf("\nx1 es x2 is: %f", x1);
		}
		if (x1 != x2)
		{
			printf("\nx1: %f\nx2: %f", x1, x2);
		}
	}
	else
	{
		printf("\nnincs valos gyok\n");
	}

	///8. feladat

	printf("\n\nwhile\n");

	int x = 1;
	while (x <= 20)
	{
		printf("%d\n", x);
		x = x + 1;
	}

	printf("\n\nfor\n");

	for (int i = 1; i <= 20; i = i + 1)
	{
		printf("%d\n", i);
	}

	///9. feladat

	printf("\n\nMekkora legyen a szakasz? ");
	int sz;
	scanf("%d", &sz);
	printf("+");
	for (int i = 1; i <= sz; i = i + 1) {
		printf("-");
	}
	printf("+");

	return 0;
}
