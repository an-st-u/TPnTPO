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
/* //для graphic.h
int oldColor = getcolor();
	setcolor(0);
	Show();
	setcolor(oldColor);
*/
}

void Rectgle::show()
{
	//Pen^ myPen = gcnew Pen(Color::Red);
	//g->DrawRectangle(myPen, this->x1, this->y1, this->x2, this->y2);


	//если закрашивать
	SolidBrush^ redBrush = gcnew SolidBrush(Color::Red);
	g->FillRectangle(redBrush, this->x1, this->y1, this->x2, this->y2);
/* // для graphics.h
	rectangle(this->x1, this->y1, this->x2, this->y2);
*/
}


void Rectgle::move(int dx, int dy)
{
    this->hide();
    this->x1 += dx;
    this->y1 += dy;
   // this->x2 += dx;
  //  this->y2 += dy;
    this->show();
}




/*
void Rectgle::move1(int _x1, int _y1, int _x2, int _y2)
{
    this->hide();
    this->x1 += _x1;
    this->y1 += _y1;
    this->x2 += _x2;
    this->y2 += _y2;
    this->show();
}
*/
