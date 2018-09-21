#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "everything.h"

FILE *angrysvg;

int Width = 1920, Height = 936, GroundHeight = 35, EntityRadius = 35, EntityStroke = 5, MalacX = 1500, MalacY = 500, Margin = 100, db;
double g = 9.81, speed, arc;
char GroundColor[] = "green";
Hits talalt[1000], sortedtalalt[200];

void createObjects(Rect Object) {
	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "    <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"black\" fill=\"%s\" stroke-width=\"%d\" />\n", Object.x - Object.w / 2, Object.y + EntityRadius, Object.w, Object.h, Object.color, EntityStroke);
	fcloseall;
}

void createGround(int groundheight) {
	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "    <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"black\" fill=\"%s\" stroke-width=\"%d\" />\n", EntityStroke, Height - EntityStroke - GroundHeight, Width - EntityStroke * 2, GroundHeight, GroundColor, EntityStroke);
	fcloseall;
}

void createBackground() {
	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "    <rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" stroke=\"blue\" fill=\"blue\" stroke-width=\"0\" />\n", Width, Height);
	fcloseall;
}

void createEntities(Circle Entity) {
	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "    <circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" fill=\"%s\" stroke-width=\"%d\" />\n", Entity.x, Entity.y, Entity.r, Entity.color, Entity.stroke);
	fcloseall;
}

void createSVG(Circle madar, Circle malac, Rect malacground, int groundheight, Circle sun) {
	createBackground();
	createObjects(malacground);
	createGround(groundheight);
	createEntities(sun);
	createEntities(madar);
	createEntities(malac);
}

void calculateTrajectories(Circle malac) {
	int x, y, j = 0;
	double c;
	for (speed = 130; speed <= 160; speed++) {
		for (int k = 10; k <= 60; k = k + 5) {
			arc=(k * -1) * 3.14159265359 / 180;
			for (int i = 0; i < 5000; i++) {
				c = i * 0.125;

				x = (speed * cos(arc) * c) + EntityRadius + 50;
				y = (speed * sin(arc) * c + (g / 2 * c * c)) + Height - Margin - GroundHeight;

				if (abs(MalacX - x) < EntityRadius + EntityStroke && abs(MalacY - y) < EntityRadius + EntityStroke) {
					talalt[j].speed = speed; talalt[j].arc = k; /*printf("%f %f\n", talalt[j].speed, talalt[j].arc);*/ j++;
				}
				if (y > Height) break;
			}
		}
	}
	fcloseall;
}

void sortTrajectories() {
	int j = 0;
	for (int i = 1; i <= 1000; i++) {
		if (talalt[i-1].speed == talalt[i].speed && talalt[i-1].arc == talalt[i].arc);
		else {
			sortedtalalt[j].speed = talalt[i - 1].speed;
			sortedtalalt[j].arc = talalt[i - 1].arc;
			//printf("%f %f\n", sortedtalalt[j].speed, sortedtalalt[j].arc);
			j++;
		}
	}
	db = j;
}

void drawTrajectory() {
	angrysvg = fopen("angry.svg", "a");
	//delay(1);
	int x, y;
	arc = 50;
	arc = (arc * -1) * 3.14159265359 / 180;
	speed = 155;
	double c;
	for (int j = 0; j <= db; j++) {
		speed = sortedtalalt[j].speed;
		arc = sortedtalalt[j].arc;
		for (int i = 0; i < 47; i++) {

			///ez itt csak egy bizonyos karakter szám ig müködik, onnan tól konkrétan meggyilkolja az svgt, és foggalmam sincs hogy miért, ha csak 1 pályát irok ki körökkel akkor müködik, de több után elromlik, ezt miért csinálja?

			c = i * 0.5;

			x = (speed * cos(arc) * c) + EntityRadius + 50;
			y = (speed * sin(arc) * c + (g / 2 * c * c)) + Height - Margin - GroundHeight;

			fprintf(angrysvg, "    <circle cx=\"%d\" cy=\"%d\" r=\"15\" stroke=\"black\" fill=\"pink\" stroke-width=\"0\" />\n", x, y);
		}
	}
	fcloseall;
}


void angrybirds() {

	angrysvg = fopen("angry.svg", "w");
	fprintf(angrysvg, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", Width, Height);
	fcloseall;

	Circle Madar = { "#c90628", EntityRadius + 50, Height - Margin - GroundHeight, EntityRadius, EntityStroke };
	Circle Malac = { "#75e543", MalacX, MalacY, EntityRadius, EntityStroke };
	Rect MalacGround = { "#6e2b00", MalacX , MalacY, 200, Height - MalacY, EntityStroke };
	Circle Sun = { "yellow" ,Width, 0, 140, 0 };

	createSVG(Madar, Malac, MalacGround, GroundHeight, Sun);

	/*printf("Kiloves szoge (10-60): ");
	scanf("%lf", &arc);
	arc = (arc * -1) * 3.14159265359 / 180;
	printf("%f", arc);
	printf("Kiloves sebessege (10-30): ");
	scanf("%lf", &speed);
	speed = (speed + 90);*/

	calculateTrajectories(Malac);
	sortTrajectories();
	drawTrajectory();

	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "</svg>");
	fcloseall;
}