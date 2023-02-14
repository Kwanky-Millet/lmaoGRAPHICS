#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <Math.h>
#include <graphics.h>

void floodfill (int x, int y, int fillcolor, int oldcolor) {
	if (getpixel(x, y) == oldcolor) {
		setcolor(fillcolor);

		putpixel(x, y, fillcolor);

		floodfill(x + 1, y, fillcolor, oldcolor);
		floodfill(x - 1, y, fillcolor, oldcolor);
		floodfill(x, y + 1, fillcolor, oldcolor);
		floodfill(x, y - 1, fillcolor, oldcolor);
	}
}

void main () {
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	rectangle(100, 100, 300, 300);

	floodfill(120, 120, 9, 0);
	delay(500);

	getch();
	closegraph();
}
