#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <Math.h>
#include <graphics.h>

void boundaryfill (int x, int y, int fillcolor, int boundarycolor) {
	if (getpixel(x, y) != boundarycolor && getpixel(x, y) != fillcolor) {
		setcolor(fillcolor);

		putpixel(x, y, fillcolor);

		boundaryfill(x + 1, y, fillcolor, boundarycolor);
		boundaryfill(x - 1, y, fillcolor, boundarycolor);
		boundaryfill(x, y + 1, fillcolor, boundarycolor);
		boundaryfill(x, y - 1, fillcolor, boundarycolor);
	}
}

void main () {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	rectangle(100, 100, 300, 300);

	boundaryfill(120, 120, 9, 0);
	delay(500);

	getch();
	closegraph();
}
