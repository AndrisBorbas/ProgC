#pragma once

typedef struct Circle {
	int x, y, r, stroke;
	char color[8];
} Circle;

typedef struct Hits {
	double speed, arc;
} Hits;

typedef struct Rect {
	int x, y, w, h, stroke;
	char color[8];
} Rect;