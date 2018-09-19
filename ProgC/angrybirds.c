#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "everything.h"

FILE *angrysvg;

int Width = 1920, Height = 900, GroundHeight = 35, EntityRadius = 35, EntityStroke = 5;
char GroundColor[] = "green";

void createObjects() {

}

void createGround(int groundheight) {
	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "    <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"black\" fill=\"green\" stroke-width=\"%d\" />\n", EntityStroke, Height - EntityStroke - GroundHeight, Width - EntityStroke * 2, GroundHeight, EntityStroke);
	fcloseall;
}

void createBackground() {
	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "    <rect x=\"0\" y=\"0\" width=\"%d\" height=\"%d\" stroke=\"blue\" fill=\"blue\" stroke-width=\"0\" />\n", Width, Height);
	fcloseall;
}

void createEntities(Kor Entity) {
	angrysvg = fopen("angry.svg", "a");
	if (!strcmp(Entity.name, "madar")) {
		fprintf(angrysvg, "    <circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" fill=\"red\" stroke-width=\"%d\" />\n", Entity.x, Entity.y, Entity.r, Entity.stroke);
	}
	if (!strcmp(Entity.name, "malac")) {
		fprintf(angrysvg, "    <circle cx=\"%d\" cy=\"%d\" r=\"%d\" stroke=\"black\" fill=\"green\" stroke-width=\"%d\" />\n", Entity.x, Entity.y, Entity.r, Entity.stroke);
	}
	fcloseall;
}

void createSVG(Kor madar, Kor malac, int GroundHeight) {
	createBackground();
	createEntities(madar);
	createEntities(malac);
	createGround(GroundHeight);
}

void angrybirds() {

	angrysvg = fopen("angry.svg", "w");
	fprintf(angrysvg, "<svg width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", Width, Height);
	fcloseall;
	Kor Madar = { "madar", EntityRadius + 50, Height - 100 - GroundHeight, EntityRadius, EntityStroke };
	Kor Malac = { "malac", 1500, 500, EntityRadius, EntityStroke };
	createSVG(Madar, Malac, GroundHeight);


	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "</svg>");
	fcloseall;
}