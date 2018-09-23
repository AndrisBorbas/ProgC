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
Hits talalt[100]/*, sortedtalalt[50]*/; ///stores trajectories that hit the target

void createObjects(Rect Object) {
	fprintf(angrysvg, "    <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"black\" fill=\"%s\" stroke-width=\"%d\" />\n", Object.x - Object.w / 2, Object.y + EntityRadius, Object.w, Object.h, Object.color, EntityStroke);
}

void createGround(int groundheight) {
	fprintf(angrysvg, "    <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"black\" fill=\"%s\" stroke-width=\"%d\" />\n", EntityStroke, Height - EntityStroke - GroundHeight, Width - EntityStroke * 2, GroundHeight, GroundColor, EntityStroke);
}

void createBackground() {
	fprintf(angrysvg, "    <rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" stroke=\"blue\" fill=\"blue\" stroke-width=\"0\" />\n", Width, Height);
}

void createEntities(Circle Entity) {
	fprintf(angrysvg, "    <circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" fill=\"%s\" stroke-width=\"%d\" />\n", Entity.x, Entity.y, Entity.r, Entity.color, Entity.stroke);
}

void createSVG(Circle madar, Circle malac, Rect malacground, int groundheight, Circle sun) { ///create visuals
	createBackground();
	createObjects(malacground);
	createGround(groundheight);
	createEntities(sun);
	createEntities(madar);
	createEntities(malac);
}

void calculateTrajectories(Circle malac) { ///checks whether a trajectory is on target or not
	int x, y, j = 0;
	double c;
	for (speed = 130; speed <= 160; speed = speed + 3) {
		for (int k = 10; k <= 60; k = k + 5) {
			arc = (k * -1) * 3.14159265359 / 180;
			for (int i = 0; i < 5000; i++) {
				c = i * 0.125;

				x = (speed * cos(arc) * c) + EntityRadius + 50;
				y = (speed * sin(arc) * c + (g / 2 * c * c)) + Height - Margin - GroundHeight;

				if (pow((EntityRadius - EntityRadius), 2) <= pow((MalacX-x), 2) + pow((MalacY - y), 2) && pow((MalacX - x), 2) + pow((MalacY - y), 2) <= pow((EntityRadius + EntityRadius), 2)) {
					talalt[j].speed = speed; talalt[j].arc = k;
					printf("Sebesseg: %g Szog: %g\n", talalt[j].speed, talalt[j].arc);
					j++;
					break;
				}
				if (y > Height || x > Width) break;
			}
		}
	}
	db = j;
}

////////////////
///deprecated///
/*void sortTrajectories() { ///sorts out trajectories that are equal or the same so they don't get drawn more than once
	int j = 0;
	for (int i = 1; i <= 1000; i++) {
		if (talalt[i - 1].speed == talalt[i].speed && talalt[i - 1].arc == talalt[i].arc);
		else {
			sortedtalalt[j].speed = talalt[i - 1].speed;
			sortedtalalt[j].arc = talalt[i - 1].arc;
			if (sortedtalalt[j].speed == 0 || sortedtalalt[j].arc == 0)continue;
			printf("Sebesseg: %g Szog: %g\n", sortedtalalt[j].speed, sortedtalalt[j].arc);
			j++;
		}
	}
	db = j;
}*/

void drawTrajectory() { ///draws out the trajectories that are on target
	//delay(1);
	int x, y;
	double c;

	for (int j = 0; j <= db; j++) {
		speed = talalt[j].speed;
		arc = talalt[j].arc;
		if (speed == 0 || arc == 0)continue;
		arc = (arc * -1) * 3.14159265359 / 180;
		fprintf(angrysvg, "    <polyline points=\"");
		for (int i = 0; i < 55; i++) {
			c = i * 0.5;

			x = (speed * cos(arc) * c) + EntityRadius + 50;
			y = (speed * sin(arc) * c + (g / 2 * c * c)) + Height - Margin - GroundHeight;

			if (y > Height + 150 || x > Width + 100)break;

			fprintf(angrysvg, "%d,%d ", x, y);
		}
		fprintf(angrysvg, "\" stroke=\"pink\" fill=\"none\" stroke-width=\"1\" />\n");
	}
}


void angrybirds() {

	angrysvg = fopen("angry.svg", "w");
	fprintf(angrysvg, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", Width, Height);

	Circle Madar = { EntityRadius + 50, Height - Margin - GroundHeight, EntityRadius, EntityStroke, "#c90628" };
	Circle Malac = { MalacX, MalacY, EntityRadius, EntityStroke ,"#75e543" };
	Rect MalacGround = { MalacX , MalacY, 200, Height - MalacY, EntityStroke, "#6e2b00" };
	Circle Sun = { Width, 0, 140, 0, "yellow" };

	createSVG(Madar, Malac, MalacGround, GroundHeight, Sun);

	/*printf("Kiloves szoge (10-60): ");
	scanf("%lf", &arc);
	arc = (arc * -1) * 3.14159265359 / 180;
	printf("%f", arc);
	printf("Kiloves sebessege (10-30): ");
	scanf("%lf", &speed);
	speed = (speed + 90);*/

	calculateTrajectories(Malac);
	//sortTrajectories();
	drawTrajectory();

	fprintf(angrysvg, "</svg>");
	fclose(angrysvg);
}