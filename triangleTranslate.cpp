#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <Math.h>

void DDA_line (int x1, int y1, int x2, int y2) {
	int i, dx, dy, steps;
	float x, y, xinc, yinc;

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) >= abs(dy))
		steps = dx;
	else
		steps = dy;

	xinc = float(dx) / float(steps);
	yinc = float(dy) / float(steps);
	x = x1;
	y = y1;

	for (int i = 0; i <= steps; i++) {
		putpixel(x, y, 15);
		
		x = x + xinc;
		y = y + yinc;
	}
}

void DDA_circle (int xc, int yc, int r) {
	float x, y, t;

	for (t = 0.0; t <= 2 * 3.14; t += 0.01) {
		x = xc + r * cos(t);
		y = yc + r * sin(t);

		putpixel(x, y, RED);
	}
}

void main () {
  int x1, x2, x3, y1, y2, y3;
  float px1, px2, px3, py1, py2, py3, tx, ty;

  cout << "Enter the co-ordinates (x1 y1 x2 y2 x3 y3): ";
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  cout << "Enter the translation factors (tx ty): ";
  cin >> tx >> ty;

  int gd = DETECT, gm;
  initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

  DDA_line(x1, y1, x2, y2);
  DDA_line(x2, y2, x3, y3);
  DDA_line(x3, y3, x1, y1);

  x1 += tx;
  x2 += tx;
  x3 += tx;
  y1 += ty;
  y2 += ty;
  y3 += ty;

  DDA_line(x1, y1, x2, y2);
  DDA_line(x2, y2, x3, y3);
  DDA_line(x3, y3, x1, y1);

  getch();
  closegraph();

}
