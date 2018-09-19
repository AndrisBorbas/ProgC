#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "everything.h"

FILE *angrysvg;

int Width = 1920, Height = 936, GroundHeight = 35, EntityRadius = 35, EntityStroke = 5, MalacX = 1500, MalacY = 500;
double g = -0.981, speed, arc;
char GroundColor[] = "green";

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

void calculateTrajectory() {
	angrysvg = fopen("angry.svg", "a");
	//delay(1);
	HitReg Hits[100];
	for (int i = 0; i < 30; i++) {
		Hits[i].x = (speed * cos(arc) * i*4) + EntityRadius + 50;
		Hits[i].y = (speed * sin(arc) * i*4 - (g / 2 * i*4 * i*4)) + Height - 100 - GroundHeight;
		fprintf(angrysvg, "    <circle cx=\"%d\" cy=\"%d\" r=\"15\" stroke=\"black\" fill=\"pink\" stroke-width=\"0\" />\n", Hits[i].x, Hits[i].y);
	}
	fcloseall;
}

void angrybirds() {

	angrysvg = fopen("angry.svg", "w");
	fprintf(angrysvg, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", Width, Height);
	fcloseall;

	Circle Madar = { "#c90628", EntityRadius + 50, Height - 100 - GroundHeight, EntityRadius, EntityStroke };
	Circle Malac = { "#75e543", MalacX, MalacY, EntityRadius, EntityStroke };
	Rect MalacGround = { "#6e2b00", MalacX , MalacY, 200, Height - MalacY, EntityStroke };
	Circle Sun = { "yellow" ,Width, 0, 140, 0 };

	createSVG(Madar, Malac, MalacGround, GroundHeight, Sun);

	printf("Kiloves szoge (10-60): ");
	scanf("%lf", &arc);
	arc = (arc) * 3.14159265359 / 180;
	printf("%f", arc);
	printf("Kiloves sebessege (10-30): ");
	scanf("%lf", &speed);

	calculateTrajectory();

	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "</svg>");
	fcloseall;
}