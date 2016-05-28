#include "point.h"

using namespace System::Drawing;

Pixel::Pixel()
{
	int x = 0;
	int y = 0;
}

Pixel::Pixel(Graphics ^ g, int x, int y) // для Windows Forms
/* для graphics.h
Point::Point(int x, int y)
*/

{
    this->x = x;
    this->y = y;
    this->g = g; // для Windows Forms
}

void Pixel::hide()
{
	
	SolidBrush^ whiteBrush = gcnew SolidBrush(Color::White);
	g->FillRectangle(whiteBrush, this->x, this->y, this->x, this->y);
	//, this->x2, this->y2);
	/*Pen^ myPen = gcnew Pen(Color::White);
	g->FillRectangle(myPen, this->x, this->y, this->x, this->y);
 //для graphic.h
	putpixel(x, y, 0);
*/

}

void Pixel::show()
{

	SolidBrush^ RedBrush = gcnew SolidBrush(Color::Red);
	g->FillRectangle(RedBrush, this->x, this->y,this->x,this->y);

/* //для graphic.h
putpixel(x, y, getcolor());
*/
}

void Pixel::move(int dx, int dy)
{
    this->hide();
    this->x += dx;
    this->y += dy;
    //this->x2 += dx;
    //this->y2 += dy;
    this->show();
}
