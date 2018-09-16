///Ezt a void sakk ot a main c ben hivom, gondoltam rendezettebb lesz minden 1 projectben de kulon fajlban.

#include <stdio.h>

void sakk()
{
	int db, i = 1, j = 1, k = 1, l = 1, sakksor, m = 0;
	_Bool isX = 1;
	printf("Hanyszor hanyas legyen a sakktabla? ");
	scanf_s("%d", &db);
	printf("\n");
	sakksor = 8;
	while (l <= sakksor)
	{
		while (k <= db)
		{
			if (m % 2 == 0)
				isX = 1;
			else
				isX = 0;
			while (i <= 8)
			{
				if (isX == 1)
				{
					while (j <= db)
					{
						printf("X");
						j++;
					}
					isX = 0;
					j = 1;
				}
				else
				{
					while (j <= db)
					{
						printf(".");
						j++;
					}
					isX = 1;
					j = 1;
				}
				i++;
			}
			i = 1;
			printf("\n");
			k++;
		}
		k = 1;
		l++;
		m++;
	}
}
