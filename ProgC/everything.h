#pragma once
typedef struct Circle{
	char color[50];
	int x, y, r, stroke;
} Circle;

typedef struct Hits {
	double speed, arc;
} Hits;

typedef struct Rect{
	char color[50];
	int x, y, w, h, stroke;
} Rect;