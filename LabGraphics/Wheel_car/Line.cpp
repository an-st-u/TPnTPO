#include "line.h"
using namespace System::Drawing;

Line::Line()
{
   x1 = 0;
   x2 = 0;
   y1 = 0;
   y2 = 0;
}


Line::Line(Graphics ^ g2, int x1, int y1, int x2, int y2) // для Windows Forms
{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->g2 = g2; // для Windows Forms
}

void Line::hide()
{
	Pen^ myPen = gcnew Pen(Color::White);
	g2->DrawLine(myPen, this->x1, this->y1, this->x2, this->y2);
/* //для graphic.h
	int oldColor = getcolor();
	setcolor(0);
	line(x1, y1, x2, y2);
	setcolor(oldColor);
*/

}

void Line::show()
{
	Pen^ myPen = gcnew Pen(Color::Red);
	g2->DrawLine(myPen, this->x1, this->y1, this->x2, this->y2);
/* //для graphic.h
line(x1, y1, x2, y2);
*/
}

void Line::move(int dx, int dy)
{
    this->hide();
    this->x1 += dx;
    this->y1 += dy;
    this->x2 += dx;
    this->y2 += dy;
    this->show();
}
