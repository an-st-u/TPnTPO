#include "Wheel.h"

using namespace System::Drawing;


Wheel::Wheel()
{
	this->objects = NULL;
	this->wheel_angle = 0;
	this->tire = 5;
}


Wheel::Wheel(Graphics ^ g, int x, int y, int r, int tire): Circle(g, x, y, r)
{

	this->wheel_angle = 0;
	this->tire = tire;

	int angle = 0;
	int shift = 180 / MAX_RANGS_COUNT_LINES;

	for (int i = 0; i < MAX_RANGS_COUNT_LINES; i++) {
		this->objects[i] = Line(g, (x - (r / 2)*cos(angle*PI/180) + r / 2), y - (r / 2)*sin(angle*PI / 180) + r / 2, x + (r / 2)*cos(angle*PI/180) + r / 2, y + (r / 2)*sin(angle*PI / 180) + r / 2);
		angle += shift;
	}
}



void Wheel::hide()
{


	Pen^ myPen = gcnew Pen(Color::White);
	g->DrawEllipse(myPen, this->x, this->y, this->r, this->r);
	g->DrawEllipse(myPen, this->x-tire, this->y-tire, this->r+2*tire, this->r+2*tire);
	for (int i = 0; i < MAX_RANGS_COUNT_LINES; i++) {
		this->objects[i].hide();
	}
}

void Wheel::show()
{


	Pen^ myPen = gcnew Pen(Color::Red);
	g->DrawEllipse(myPen, this->x, this->y, this->r, this->r);
	g->DrawEllipse(myPen, this->x - tire, this->y - tire, this->r + 2 * tire, this->r + 2 * tire);
	for (int i = 0; i < MAX_RANGS_COUNT_LINES; i++) {
		this->objects[i].show();
	}
}




void Wheel::move(int dx, int dy) {

	this->hide();
	x += dx;
	y += dy;
	int angle = wheel_angle++;
	int shift = 180 / MAX_RANGS_COUNT_LINES;

	if (wheel_angle > 360) {
		wheel_angle = -360;
	}

	int rr = r / 2;
	
	for (int i = 0; i < MAX_RANGS_COUNT_LINES; i++) {
		
		this->objects[i].x1 = x - rr * cos(angle*PI/180) + rr;
		this->objects[i].y1 = y - rr * sin(angle*PI/180) + rr;
		this->objects[i].x2 = x + rr * cos(angle*PI/180) + rr;
		this->objects[i].y2 = y + rr * sin(angle*PI/180) + rr;
		angle += shift;
	}

    this->show();
}



