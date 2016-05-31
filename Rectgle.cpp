#include "Rectgle.h"
using namespace System::Drawing;
Rectgle::Rectgle(Graphics ^ g, int x1, int y1, int x2, int y2) // для Windows Forms


{
    this->x1 = x1;
    this->y1 = y1;
    this->x2 = x2;
    this->y2 = y2;
    this->g = g; // для Windows Forms
}

void Rectgle::hide()
{
	Pen^ myPen = gcnew Pen(Color::White);
	g->DrawRectangle(myPen, this->x1, this->y1, this->x2, this->y2);

}

void Rectgle::show()
{

	//если закрашивать
	SolidBrush^ redBrush = gcnew SolidBrush(Color::Red);
	g->FillRectangle(redBrush, this->x1, this->y1, this->x2, this->y2);

}


void Rectgle::move(int dx, int dy)
{
    this->hide();
    this->x1 += dx;
    this->y1 += dy;
    this->show();
}