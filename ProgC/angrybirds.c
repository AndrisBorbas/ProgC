#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "everything.h"

FILE *angrysvg;

int Width = 1920, Height = 936, GroundHeight = 35, EntityRadius = 35, EntityStroke = 5, MalacX = 1500, MalacY = 500;
double g = 9.81;
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

	calculateTrajectory();

	angrysvg = fopen("angry.svg", "a");
	fprintf(angrysvg, "</svg>");
	fcloseall;
}