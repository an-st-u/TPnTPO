#include "point.h"

using namespace System::Drawing;

Pixel::Pixel()
{
	int x = 0;
	int y = 0;
}

Pixel::Pixel(Graphics ^ g, int x, int y) // для Windows Forms

{
    this->x = x;
    this->y = y;
    this->g = g; // для Windows Forms
}

void Pixel::hide()
{
	
	SolidBrush^ whiteBrush = gcnew SolidBrush(Color::White);
	g->FillRectangle(whiteBrush, this->x, this->y, this->x, this->y);


}

void Pixel::show()
{

	SolidBrush^ RedBrush = gcnew SolidBrush(Color::Red);
	g->FillRectangle(RedBrush, this->x, this->y,this->x,this->y);

}

void Pixel::move(int dx, int dy)
{
    this->hide();
    this->x += dx;
    this->y += dy;
    this->show();
}
