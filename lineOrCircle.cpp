#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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
	int choice;

	cout << "Enter your choice:\n\t1.Line\n\t2.Circle\n";
	cin >> choice;

	switch (choice) {
		case 1: {
				int x1, y1, x2, y2;
				
				clrscr();

				cout << "Enter starting point (x1, y1): ");
				cin >> x1 >> y1;
				cout << "Enter ending point (x2, y2): ");
				cin >> x2 >> y2;

				int gd = DETECT, gm;
				initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
				
				DDA_line(x1, y1, x2, y2);

				getch();
				closegraph();
			}
			break;

		case 2: {
				float xc, yc, r;
				
				clrscr();

				cout << "Enter the co-ordinates of the circle: ";
				cin >> xc >> yc;
				cout << "Enter the radius of the circle: ";
				cin >> r;

				int gd = DETECT, gm;
				initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
				
				DDA_circle(xc, yc, r);

				getch();
				closegraph();
			}
			break;

		default:
			cout << "INVALID CHOICE";
			break;
	}
}
