#include <math.h>
#include <stdio.h>

void oramutato()
{
	FILE *orasvg;
	orasvg = fopen("ora.svg", "a");
	int sugar[3], vastag[3], ora, perc, mp;
	double fok[3];
	printf("ora perc mp:  ");
	scanf("%d %d %d", &ora, &perc, &mp);
	fok[0] = ora * 30 + (perc * 6 / 60 * 5);
	fok[1] = perc * 6 + (mp * 6 / 60);
	fok[2] = mp * 6;
	sugar[0] = 101;
	sugar[1] = 200;
	sugar[2] = 250;
	vastag[0] = 20;
	vastag[1] = 15;
	vastag[2] = 2;
	int pontokx[100];
	int pontoky[100];
	for (int i = 0; i < 3; i++)
	{
		pontokx[i] = sugar[i] * cos((fok[i] - 90) * 3.14159265359 / 180) + 500;
		pontoky[i] = sugar[i] * sin((fok[i] - 90) * 3.14159265359 / 180) + 500;
		fprintf(orasvg, "    <line x1=\"%d\" y1=\"%d\" x2=\"500\" y2=\"500\" stroke=\"black\" stroke-width=\"%d\" />\n", pontokx[i], pontoky[i], vastag[i]);
	}
	fprintf(orasvg, "</svg>");
	fclose(orasvg);
}

void oragen()
{
	FILE *orasvg;
	remove("ora.svg");
	orasvg = fopen("ora.svg", "a");
	int sugar = 400, ksugar, bsugar;
	double fok;
	int pontokx1[60], pontoky1[60], pontokx2[60], pontoky2[60];
	ksugar = sugar - 40;
	bsugar = sugar - 100;
	fprintf(orasvg, "<svg width=\"1000\" height=\"1000\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n    <circle cx=\"500\" cy=\"500\" r=\"400\" stroke=\"black\" stroke-width=\"15\" fill=\"white\" />\n	<circle cx=\"500\" cy=\"500\" r=\"10\" stroke=\"black\" stroke-width=\"25\" fill=\"black\" />\n");
	for (int i = 0; i < 60; i++) {
		fok = i * 6;
		pontokx1[i] = sugar * cos(fok * 3.14159265359 / 180) + 500;
		pontoky1[i] = sugar * sin(fok * 3.14159265359 / 180) + 500;
		pontokx2[i] = ksugar * cos(fok * 3.14159265359 / 180) + 500;
		pontoky2[i] = ksugar * sin(fok * 3.14159265359 / 180) + 500;
		fprintf(orasvg, "    <line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"6\" />\n", pontokx1[i], pontoky1[i], pontokx2[i], pontoky2[i]);
	}
	for (int i = 0; i < 12; i++) {
		fok = i * 5 * 6;
		pontokx1[i] = sugar * cos(fok * 3.14159265359 / 180) + 500;
		pontoky1[i] = sugar * sin(fok * 3.14159265359 / 180) + 500;
		pontokx2[i] = bsugar * cos(fok * 3.14159265359 / 180) + 500;
		pontoky2[i] = bsugar * sin(fok * 3.14159265359 / 180) + 500;
		fprintf(orasvg, "    <line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"black\" stroke-width=\"17\" />\n", pontokx1[i], pontoky1[i], pontokx2[i], pontoky2[i]);
	}
	fclose(orasvg);
}