#include "circle.h"
using namespace System::Drawing;

Circle::Circle()
{
	unsigned r = 0;
}
 

Circle::Circle(Graphics ^ g, int x, int y, unsigned r): Pixel(g, x, y) // для Windows Forms
{
    this->x = x;
    this->y = y;
    this->r = r;
	this->g = g;

}

void Circle::hide()
{
	Pen^ myPen = gcnew Pen(Color::White);
	g->DrawEllipse(myPen, this->x, this->y, this->r, this->r);

/* //для graphic.h
	int oldColor = getcolor();
	setcolor(0);
	circle(x, y, r);
	setcolor(oldColor);
*/
}

void Circle::show()
{
	Pen^ myPen = gcnew Pen(Color::Red);
	g->DrawEllipse(myPen, this->x, this->y, this->r, this->r);

}

void Circle::move(int dx, int dy)
{
    this->hide();
    this->x += dx;
    this->y += dy;
    this->show();
}


