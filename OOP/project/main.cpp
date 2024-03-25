#include <iostream>
#include <ctime>
#include <time.h>
#include "mygraphics.h"


int lightOrder = 0;

class light {

	bool LR;
	bool UD;

public:
	light() {}

	void setLightGreen2(int a)
	{
		if (a == 0 || a == 1)
		{
			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);

			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);

			drawEllipse(521, 319, 541, 339, 0, 255, 0, 0, 255, 0);
		
			drawEllipse(275, 122, 295, 142, 0, 255, 0, 0, 255, 0);

			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);

			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);
		}


		else if (a == 2 || a == 3)
		{
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);

			drawEllipse(273, 322, 293, 342, 0, 255, 0, 0, 255, 0);

			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);

			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);

			drawEllipse(521, 118, 541, 138, 0, 255, 0, 0, 255, 0);

			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
		}
	}
	void setLightGreen(int a)
	{
		if (a == 0)
		{
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);

			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);

			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);

			drawEllipse(521, 319, 541, 339, 0, 255, 0, 0, 255, 0);
		}


		else if (a == 1)
		{
			drawEllipse(275, 122, 295, 142, 0, 255, 0, 0, 255, 0);

			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);

			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);

			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
		}


		else if (a == 2)
		{
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);

			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);

			drawEllipse(273, 322, 293, 342, 0, 255, 0, 0, 255, 0);

			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
		}


		else if (a == 3)
		{
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);

			drawEllipse(521, 118, 541, 138, 0, 255, 0, 0, 255, 0);

			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);

			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
		}
	}


	void draw() {
		//Upper left
		drawRectangle(190, 115, 300, 150, 0, 0, 0, 0, 0, 0);

		//Upper right
		drawRectangle(514, 40, 549, 150, 0, 0, 0, 0, 0, 0);

		//Lower left
		drawRectangle(265, 314, 300, 424, 0, 0, 0, 0, 0, 0);

		//Lower right
		drawRectangle(514, 314, 624, 349, 0, 0, 0, 0, 0, 0);


		drawEllipse(238, 122, 258, 142, 105, 105, 105, 105, 105, 105);
		drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
		drawEllipse(200, 122, 220, 142, 105, 105, 105, 105, 105, 105);

		drawEllipse(521, 45, 541, 65, 105, 105, 105, 105, 105, 105);
		drawEllipse(521, 82, 541, 102, 105, 105, 105, 105, 105, 105);
		drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);

		drawEllipse(273, 393, 293, 413, 105, 105, 105, 105, 105, 105);
		drawEllipse(273, 357, 293, 377, 105, 105, 105, 105, 105, 105);
		drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);

		drawEllipse(558, 319, 578, 339, 105, 105, 105, 105, 105, 105);
		drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
		drawEllipse(595, 319, 615, 339, 105, 105, 105, 105, 105, 105);
	}

	void drawupL(int i)
	{
		if (i == 0)
		{
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);
			drawEllipse(238, 122, 258, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
			LR = false;

		}
		if (i == 1)
		{
			drawEllipse(200, 122, 220, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(238, 122, 258, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(275, 122, 295, 142, 0, 255, 0, 0, 255, 0);
			LR = true;
		}
	}
	void drawupR(int i)
	{
		if (i == 0)
		{
			drawEllipse(521, 45, 541, 65, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 82, 541, 102, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 118, 541, 138, 0, 255, 0, 0, 255, 0);
			UD = true;
		}
		if (i == 1)
		{
			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);
			drawEllipse(521, 82, 541, 102, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);
			UD = false;
		}
	}
	void drawdownL(int i)
	{
		if (i == 0)
		{
			drawEllipse(273, 393, 293, 413, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 357, 293, 377, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 322, 293, 342, 0, 255, 0, 0, 255, 0);
			UD = true;
		}
		if (i == 1)
		{
			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);
			drawEllipse(273, 357, 293, 377, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);
			UD = false;
		}
	}
	void drawdownR(int i)
	{
		if (i == 0)
		{
			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
			drawEllipse(558, 319, 578, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
			LR = true;
			UD = true;
		}
		if (i == 1)
		{
			drawEllipse(595, 319, 615, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(558, 319, 578, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 319, 541, 339, 0, 255, 0, 0, 255, 0);
			LR = true;
			UD = true;
		}
	}

	void yellow()
	{
		//Upper left lights
		drawEllipse(200, 122, 220, 142, 105, 105, 105, 105, 105, 105);
		drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
		drawEllipse(238, 122, 258, 142, 255, 255, 0, 255, 255, 0);

		//Upper right lights
		drawEllipse(521, 45, 541, 65, 105, 105, 105, 105, 105, 105);
		drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);
		drawEllipse(521, 82, 541, 102, 255, 255, 0, 255, 255, 0);

		//Lower left lights
		drawEllipse(273, 393, 293, 413, 105, 105, 105, 105, 105, 105);
		drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);
		drawEllipse(273, 357, 293, 377, 255, 255, 0, 255, 255, 0);

		//Lower right lights
		drawEllipse(595, 319, 615, 339, 105, 105, 105, 105, 105, 105);
		drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
		drawEllipse(558, 319, 578, 339, 255, 255, 0, 255, 255, 0);
	}


	void yellow2(int temp)
	{
		if (temp == 1)
		{
			//Upper left lights
			drawEllipse(200, 122, 220, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(238, 122, 258, 142, 255, 255, 0, 255, 255, 0);

			//Upper right lights
			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);
			drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 82, 541, 102, 105, 105, 105, 105, 105, 105);

			//Lower left lights
			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);
			drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 357, 293, 377, 105, 105, 105, 105, 105, 105);

			//Lower right lights
			drawEllipse(595, 319, 615, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(558, 319, 578, 339, 255, 255, 0, 255, 255, 0);
		}
		else if (temp == 2)
		{
			//Upper left lights
			drawEllipse(200, 122, 220, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(238, 122, 258, 142, 255, 255, 0, 255, 255, 0);

			//Upper right lights
			drawEllipse(521, 45, 541, 65, 255, 0, 0, 255, 0, 0);
			drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 82, 541, 102, 105, 105, 105, 105, 105, 105);

			//Lower left lights
			drawEllipse(273, 393, 293, 413, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 357, 293, 377, 255, 255, 0, 255, 255, 0);

			//Lower right lights
			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
			drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(558, 319, 578, 339, 105, 105, 105, 105, 105, 105);
		}
		else if (temp == 3)
		{
			//Upper left lights
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);
			drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(238, 122, 258, 142, 105, 105, 105, 105, 105, 105);

			//Upper right lights
			drawEllipse(521, 45, 541, 65, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 82, 541, 102, 255, 255, 0, 255, 255, 0);

			//Lower left lights
			drawEllipse(273, 393, 293, 413, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 357, 293, 377, 255, 255, 0, 255, 255, 0);

			//Lower right lights
			drawEllipse(595, 319, 615, 339, 255, 0, 0, 255, 0, 0);
			drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(558, 319, 578, 339, 105, 105, 105, 105, 105, 105);
		}
		else if (temp == 0)
		{
			//Upper left lights
			drawEllipse(200, 122, 220, 142, 255, 0, 0, 255, 0, 0);
			drawEllipse(275, 122, 295, 142, 105, 105, 105, 105, 105, 105);
			drawEllipse(238, 122, 258, 142, 105, 105, 105, 105, 105, 105);

			//Upper right lights
			drawEllipse(521, 45, 541, 65, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 118, 541, 138, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 82, 541, 102, 255, 255, 0, 255, 255, 0);

			//Lower left lights
			drawEllipse(273, 393, 293, 413, 255, 0, 0, 255, 0, 0);
			drawEllipse(273, 322, 293, 342, 105, 105, 105, 105, 105, 105);
			drawEllipse(273, 357, 293, 377, 105, 105, 105, 105, 105, 105);

			//Lower right lights
			drawEllipse(595, 319, 615, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(521, 319, 541, 339, 105, 105, 105, 105, 105, 105);
			drawEllipse(558, 319, 578, 339, 255, 255, 0, 255, 255, 0);
		}
	}

	bool getUD()
	{
		return UD;
	}
	bool getLR()
	{
		return LR;
	}
};


int breaking = 0;
int arr[] = { 0,260,750,200,325,0,435,411 };


class car {
protected:
	int x;
	int y;
	int a1;
	int a2;
	int R;
	int G;
	int B;

public:
	void setU(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setD(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setL(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setR(int x, int y)
	{
		this->x = x;
		this->y = y;
	}


	car() {};
	car(int a, int r, int g, int b) :R(r), G(g), B(b)
	{
		srand(time(0));
		a2 = rand() % 3;
		a1 = a;
		switch (a) {
		here:
		case 0:
			x = arr[0];
			y = arr[1];
			break;
		case 1:
			x = arr[2];
			y = arr[3];
			break;
		case 2:
			x = arr[4];
			y = arr[5];
			break;
		case 3:
			x = arr[6];
			y = arr[7];
			break;
		default:
			a = 0;
			goto here;
			break;
		}
	}
	void draw()
	{
		switch (a1)
		{
		case 0:
			drawr();
			break;
		case 1:
			drawl();
			break;
		case 2:
			drawu();
			break;
		case 3:
			drawd();
			break;
		}
	}


	void drawr()
	{
		if (a2 == 1 && x >= 325)
		{
			drawU();
			if (y >= 400)
			{
				breaking = 1;
			}
		}
		else if (a2 == 2 && x >= 425)
		{
			drawD();
			if (y <= 10)
			{
				breaking = 1;
			}
		}
		else
		{
			if (x > 240 && x < 280 && lightOrder != 0)
			{
				drawRectangle(x, y + 29, x + 50, y - 9, R, G, B, B, G, R);
			}

			else
			{
				drawRectangle(x, y + 29, x + 50, y - 9, R, G, B, B, G, R);
				x += 10;
			}

			if (x >= 750)
			{
				breaking = 1;
			}
		}

	}
	void drawl()
	{

		if (a2 == 1 && x <= 325)
		{
			drawU();
			if (y >= 400)
			{
				breaking = 1;
			}
		}
		else if (a2 == 2 && x <= 450)
		{
			drawD();
			if (y <= 10)
			{
				breaking = 1;
			}
		}
		else
		{
			if (x > 485 && x < 515 && lightOrder != 1)
			{
				drawRectangle(x, y + 10, x + 50, y - 20, R, G, B, B, G, R);
			}
			else {
				drawRectangle(x, y + 10, x + 50, y - 20, R, G, B, B, G, R);
				x -= 10;
			}
			if (x <= 0)
			{
				breaking = 1;
			}
		}
	}
	void drawu()
	{
		if (a2 == 1 && y >= 199)
		{
			drawL();
			if (x <= 10)
			{
				breaking = 1;
			}
		}
		else if (a2 == 2 && y >= 260)
		{
			drawR();
			if (x >= 750)
			{
				breaking = 1;
			}
		}
		else
		{
			if (y > 90 && y < 120 && lightOrder != 2)
			{
				drawRectangle(x, y + 50, x + 40, y - 9, R, G, B, B, G, R);
			}
			else
			{
				drawRectangle(x, y + 50, x + 40, y - 9, R, G, B, B, G, R);
				y += 10;
			}
			if (y >= 400)
			{
				breaking = 1;
			}
		}
	}

	void drawd()
	{
		if (a2 == 1 && y <= 200)
		{
			drawL();
			if (x <= 10)
			{
				breaking = 1;
			}
		}
		else if (a2 == 2 && y <= 275)
		{
			drawR();
			if (x >= 750)
			{
				breaking = 1;
			}
		}
		else
		{
			if (y > 330 && y < 360 && lightOrder != 3)
			{
				drawRectangle(x, y + 19, x + 40, y - 29, R, G, B, B, G, R);
			}
			else
			{
				drawRectangle(x, y + 19, x + 40, y - 29, R, G, B, B, G, R);
				y -= 10;
			}

			if (y <= 0)
			{
				breaking = 1;
			}
		}
	}

	void drawL()
	{
		drawRectangle(x, y + 10, x + 50, y - 20, R, G, B, B, G, R);
		x -= 10;
	}
	void drawR()
	{
		drawRectangle(x, y + 29, x + 50, y - 9, R, G, B, B, G, R);
		x += 10;
	}
	void drawU() {
		drawRectangle(x, y + 50, x + 40, y - 9, R, G, B, B, G, R);
		y += 10;
	}
	void drawD() {
		drawRectangle(x, y + 50, x + 40, y - 9, R, G, B, B, G, R);
		y -= 10;

	}
	void drawUC(int i)
	{
		if (i == 0)
		{
			drawRectangle(x + 0, 5 * y + 0, x - 30, 5 * y + 50, 128, 0, 128, 128, 0, 128);
			y++;
			if (5 * y > 410) y = 0;
		}
		if (i == 1)
		{
			drawRectangle(x + 0, 5 * y + 0, x - 30, 5 * y + 50, 128, 0, 128, 128, 0, 128);
			y++;
			if (5 * y > 415) y = 0;
			if (5 * y == 105) y = 20;
		}
	}
	void drawDC(int i)
	{
		if (i == 0)
		{
			drawRectangle(x + 0, 5 * y - 0, x - 30, 5 * y - 50, 139, 69, 19, 139, 69, 19);
			y--;
			if (5 * y < 25) y = 90;
		}
		if (i == 1)
		{
			drawRectangle(x + 0, 5 * y - 0, x - 30, 5 * y - 50, 139, 69, 19, 139, 69, 19);
			y--;
			if (5 * y < 30) y = 90;
			if (5 * y == 360) y = 73;
		}
	}
	void drawLC(int i)
	{
		if (i == 0)
		{
			drawRectangle(5 * x + 0, y + 0, 5 * x + 50, y + 25, 255, 140, 0, 255, 140, 0);
			x++;
			drawRectangle(5 * x + 0, y + 0, 5 * x + 50, y + 25, 255, 140, 0, 255, 140, 0);
			if (5 * x > 760) x = 0;
			if (5 * x == 250) x = 49;
		}
		if (i == 1)
		{
			drawRectangle(5 * x + 0, y + 0, 5 * x + 50, y + 25, 255, 140, 0, 255, 140, 0);
			x++;
			if (5 * x > 760) x = 0;
		}
	}
	void drawRC(int i)
	{
		if (i == 0)
		{
			drawRectangle(5 * x - 0, y - 0, 5 * x - 50, y - 25, 64, 224, 208, 64, 224, 208);
			x--;
			if (5 * x < 25) x = 160;
			if (5 * x == 555) x = 112;
		}
		if (i == 1)
		{
			drawRectangle(5 * x - 0, y - 0, 5 * x - 50, y - 25, 64, 224, 208, 64, 224, 208);
			x--;
			if (5 * x < 25) x = 160;
		}
	}
};


class intersection
{
protected:
	light* l;
	car* c;

public:
	virtual void draw() = 0;
	virtual void draw2() = 0;
};


class road : public intersection
{
protected:

public:
	road() {}
	road(car* c1, light* l1)
	{
		c = c1;
		l = l1;
	}
	void draw2()
	{
		long T = clock();
		long T2;
		long E;

	lrs:
		while (l->getUD())
		{

			//Platform
			drawRectangle(0, 0, 814, 464, 0, 255, 0, 0, 255, 0);

			//Vertical road
			drawRectangle(301, 0, 513, 464, 128, 128, 128, 128, 128, 128);

			//Horizontal road
			drawRectangle(0, 151, 814, 313, 128, 128, 128, 128, 128, 128);

			//Upper vertical lane
			drawRectangle(402, 0, 412, 150, 255, 255, 0, 255, 255, 0);

			//Lower vertical lane
			drawRectangle(402, 314, 412, 464, 255, 255, 0, 255, 255, 0);

			//Left horizontal lane
			drawRectangle(0, 227, 300, 237, 255, 255, 0, 255, 255, 0);

			//Right horizontal lane
			drawRectangle(511, 227, 814, 237, 255, 255, 0, 255, 255, 0);


			//Upper left lightbase
			drawRectangle(190, 115, 300, 150, 0, 0, 0, 0, 0, 0);

			//Upper right lightbase
			drawRectangle(514, 40, 549, 150, 0, 0, 0, 0, 0, 0);

			//Lower left lightbase
			drawRectangle(265, 314, 300, 424, 0, 0, 0, 0, 0, 0);

			//Lower right lightbase
			drawRectangle(514, 314, 624, 349, 0, 0, 0, 0, 0, 0);


			//Upper left lights
			l->drawupL(0);

			//Upper right lights
			l->drawupR(0);

			//Bottom left lights
			l->drawdownL(0);

			//Bottom right lights
			l->drawdownR(0);

			//Cars
			c[2].drawLC(0);
			c[3].drawRC(0);
			c[0].drawUC(0);
			c[1].drawDC(0);


			T2 = clock();
			E = T2 - T;
			if ((int)E / CLOCKS_PER_SEC == 3)
			{
				for (int i = 0; i < 8; i++)
				{
					delay(40);

					//Platform
					drawRectangle(0, 0, 814, 464, 0, 255, 0, 0, 255, 0);

					//Vertical road
					drawRectangle(301, 0, 513, 464, 128, 128, 128, 128, 128, 128);

					//Horizontal road
					drawRectangle(0, 151, 814, 313, 128, 128, 128, 128, 128, 128);

					//Upper vertical lane
					drawRectangle(402, 0, 412, 150, 255, 255, 0, 255, 255, 0);

					//Lower vertical lane
					drawRectangle(402, 314, 412, 464, 255, 255, 0, 255, 255, 0);

					//Left horizontal lane
					drawRectangle(0, 227, 300, 237, 255, 255, 0, 255, 255, 0);

					//Right horizontal lane
					drawRectangle(511, 227, 814, 237, 255, 255, 0, 255, 255, 0);

					//Upper left
					drawRectangle(190, 115, 300, 150, 0, 0, 0, 0, 0, 0);

					//Upper right
					drawRectangle(514, 40, 549, 150, 0, 0, 0, 0, 0, 0);

					//Lower left
					drawRectangle(265, 314, 300, 424, 0, 0, 0, 0, 0, 0);

					//Lower right
					drawRectangle(514, 314, 624, 349, 0, 0, 0, 0, 0, 0);

					l->yellow();
					l->setLightGreen2(2);

					c[0].drawUC(1);
					c[1].drawDC(1);
					c[2].drawLC(1);
					c[3].drawRC(1);
				}
				T = clock();
				goto uds;
			}
			delay(40);
		}
	uds:
		while (l->getLR())
		{
			//Platform
			drawRectangle(0, 0, 814, 464, 0, 255, 0, 0, 255, 0);

			//Vertical road
			drawRectangle(301, 0, 513, 464, 128, 128, 128, 128, 128, 128);

			//Horizontal road
			drawRectangle(0, 151, 814, 313, 128, 128, 128, 128, 128, 128);

			//Upper vertical lane
			drawRectangle(402, 0, 412, 150, 255, 255, 0, 255, 255, 0);

			//Lower vertical lane
			drawRectangle(402, 314, 412, 464, 255, 255, 0, 255, 255, 0);

			//Left horizontal lane
			drawRectangle(0, 227, 300, 237, 255, 255, 0, 255, 255, 0);

			//Right horizontal lane
			drawRectangle(511, 227, 814, 237, 255, 255, 0, 255, 255, 0);

			//Upper left
			drawRectangle(190, 115, 300, 150, 0, 0, 0, 0, 0, 0);

			//Upper right
			drawRectangle(514, 40, 549, 150, 0, 0, 0, 0, 0, 0);

			//Lower left
			drawRectangle(265, 314, 300, 424, 0, 0, 0, 0, 0, 0);

			//Lower right
			drawRectangle(514, 314, 624, 349, 0, 0, 0, 0, 0, 0);


			//Upper left lights
			l->drawupL(1);

			//Upper right lights
			l->drawupR(1);

			//Bottom left lights
			l->drawdownL(1);

			//Bottom right lights
			l->drawdownR(1);


			c[2].drawLC(1);
			c[3].drawRC(1);
			c[0].drawUC(1);
			c[1].drawDC(1);


			T2 = clock();
			E = T2 - T;
			if ((int)E / CLOCKS_PER_SEC == 6)
			{
				for (int i = 0; i < 8; i++)
				{
					delay(40);
					//Platform
					drawRectangle(0, 0, 814, 464, 0, 255, 0, 0, 255, 0);

					//Vertical road
					drawRectangle(301, 0, 513, 464, 128, 128, 128, 128, 128, 128);

					//Horizontal road
					drawRectangle(0, 151, 814, 313, 128, 128, 128, 128, 128, 128);

					//Upper vertical lane
					drawRectangle(402, 0, 412, 150, 255, 255, 0, 255, 255, 0);

					//Lower vertical lane
					drawRectangle(402, 314, 412, 464, 255, 255, 0, 255, 255, 0);

					//Left horizontal lane
					drawRectangle(0, 227, 300, 237, 255, 255, 0, 255, 255, 0);

					//Right horizontal lane
					drawRectangle(511, 227, 814, 237, 255, 255, 0, 255, 255, 0);

					//Upper left
					drawRectangle(190, 115, 300, 150, 0, 0, 0, 0, 0, 0);

					//Upper right
					drawRectangle(514, 40, 549, 150, 0, 0, 0, 0, 0, 0);

					//Lower left
					drawRectangle(265, 314, 300, 424, 0, 0, 0, 0, 0, 0);

					//Lower right
					drawRectangle(514, 314, 624, 349, 0, 0, 0, 0, 0, 0);


					l->yellow();
					l->setLightGreen2(0);


					c[0].drawUC(0);
					c[1].drawDC(0);
					c[2].drawLC(0);
					c[3].drawRC(0);
				}
				T = clock();
				goto lrs;
			}
			delay(40);
		}
	}


	void draw()
	{
		//Platform
		drawRectangle(0, 0, 814, 464, 0, 255, 0, 0, 255, 0);

		//Vertical road
		drawRectangle(301, 0, 513, 464, 128, 128, 128, 128, 128, 128);

		//Horizontal road
		drawRectangle(0, 151, 814, 313, 128, 128, 128, 128, 128, 128);

		//Upper vertical lane
		drawRectangle(402, 0, 412, 150, 255, 255, 0, 255, 255, 0);

		//Lower vertical lane
		drawRectangle(402, 314, 412, 464, 255, 255, 0, 255, 255, 0);

		//Left horizontal lane
		drawRectangle(0, 227, 300, 237, 255, 255, 0, 255, 255, 0);

		//Right horizontal lane
		drawRectangle(511, 227, 814, 237, 255, 255, 0, 255, 255, 0);

		c->draw();
		l->draw();
	}
};


using namespace std;
int main()
{
	int val = 0;
	car  c1 ;
	car c2[4];
	c2[0].setU(365, 0);
	c2[1].setD(475, 90);
	c2[2].setL(0, 260);
	c2[3].setR(160, 200);
	light l1;
	long T, T2;
	int ch;
	intersection* r1 = new road(c2, &l1);
	intersection* r2 = new road(&c1, &l1);



	cout << "TRAFFIC SIMULATOR\n------------------\nPress 1 for first strategy\nPress 2 for second strategy\n\n";


	cin >> ch;
	if (ch == 1)
	{
		r1->draw2();
	}
	if (ch == 2)
	{
		while (1)
		{
			T = clock();
			while (true)
			{
				srand(time(0));
				int l = rand() % 4;
				c1 = car(l, l * (25 * l) + 200, l * (10 * l) + 200, l * (5 * l) + 200);
				r1 = new road(&c1, &l1);
				while (1) {
					breaking = 0;
					r1->draw();
					T2 = clock();
					if (static_cast<int>(T2 - T) / CLOCKS_PER_SEC == 2)
					{
						lightOrder++;
						if (lightOrder > 3)lightOrder = 0;
						T = clock();
						int p = 0;
						while (p < 5) {

							r1->draw();
							l1.yellow2(lightOrder);
							p++;
							delay(40);
						}

					}



					l1.setLightGreen(lightOrder);
					delay(40);
					if (breaking == 1)
					{
						break;
					}
				}
				delete r1;
			}
		}
	}

	cls();
	return 0;
}
