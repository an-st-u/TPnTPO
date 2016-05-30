#include "Wheel.h"

using namespace System::Drawing;

const int angleStep = 1;


//Wheel::Wheel(Graphics ^ g, int x, int y, int x1, int x2, int y1, int y2, Circle circle1, Line *objects): Circle(g,x,y,r), Line(g, x1, x2, y1, y2)


Wheel::Wheel()
{

}


Wheel::Wheel(Graphics ^ g, int x, int y, int r, int angle)
{
	this->g = g;
	this->x = x;
	this->y = y;
	this->r = r;
	this->angle = angle;
	//this->objects[this->count_lines++] = b2;
}



void Wheel::hide()
{
	//this->circle1.show();

	/*for(unsigned i = 0; i < this->count_lines; i++) {
        this->objects[i]->hide();
    }

	this->objects[this->count_lines++];*/

	Pen^ myPen = gcnew Pen(Color::White);
	g->DrawLine(myPen, (int)(x - (r / 2)*cos(angle* PI/ 180) + r / 2), y - (r / 2)*sin(angle* PI/ 180) + r / 2, x + (r / 2)*cos(angle* PI/ 180) + r / 2, y + (r / 2)*sin(angle* PI/ 180) + r / 2);

}

void Wheel::show()
{

	//this->circle1.show();
/*
	for(unsigned i = 0; i < this->count_lines; i++) {
        this->objects[i]->show();
    }

	this->objects[this->count_lines++];*/

	Pen^ myPen = gcnew Pen(Color::Red);
	g->DrawLine(myPen, (int)(x - (r / 2)*cos(angle* PI/ 180) + r / 2), y - (r / 2)*sin(angle* PI/ 180) + r / 2, x + (r / 2)*cos(angle* PI/ 180) + r / 2, y + (r / 2)*sin(angle* PI/ 180) + r / 2);

}




void Wheel::move(int dx, int dy)
{
	//this->circle1.hide();
	this->hide();
	this->move1(dx, dy);
	x += dx;
	y += dy;
    this->show();
	//this->circle1.show();
}



void Wheel::move1(int dx, int dy)
{

    /*for(unsigned i = 0; i < this->count_lines; i++) {
        this->objects[i]->move(dx, dy);
    }*/

		angle += angleStep ;
	if (angle > 360)
		angle -= 360;

}






	/*this->x1 += ((dx) * 2 - r*sin((dx) * PI /(PI * r))); 
	this->y1 += r - r*cos((dy) * PI / (PI * r)); 


	this->x2 += ((dx) * 2 - r*sin((dx) * PI /(PI * r))); 
    this->y2 += r - r*cos((dy) * PI / (PI * r));

    this->show();

}
/*

/*this->x1 += dx; 
this->y1 = y1; 
//this->x2 = r*cos((dx+x1)/r); 
//this->y2 = r*sin((dx+x1)/r);//(1-sqrt(1-r*r-dx*dx)); 
//this->y = Big_r*acos((Big_r - x) / Big_r) - sqrt(2 * Big_r*x - x*x); 
this->x2 = (dx+x1) - r*sin((dx+x1)/r); 
this->y2 = r-r*sqrt(1-sin((dx+x1) / r)*sin((dx + x1) / r));
*/

/*
Был последний вариант
    this->hide();
	this->x += (dx) * 180 /PI - r*sin((dx) * 180 /(PI * r));  // делить на 6
	this->y += r - r*cos((dy) * 180 / (PI * r));

	this->x1 += dx; 
	this->y1 += y; 
	this->x2 = r*sin(dx / r) - r*sin(sin(dx/r)); 
    this->y2 = r-r*cos(sin(dx/r)); 

*/


/*x = x_centre + r * Convert.ToSingle(
Math.Cos(2 * Math.PI * angle / 360));
y = y_centre + r * Convert.ToSingle(
Math.Sin(2 * Math.PI * angle / 360));
*/


	/*this->x1 += dx*t - r/(sin(t * PI /180));
   this->y1 += r - r/(cos(t * PI /180));
	this->x2 += dx*t - r/(sin(t * PI /180));
   this->y2 += r - r/(cos(t * PI /180));
   




void RotateTransformAngle( PaintEventArgs^ e )
   {
      // Set world transform of graphics object to translate.
      e->Graphics->TranslateTransform( 100.0F, 0.0F );

      // Then to rotate, prepending rotation matrix.
      e->Graphics->RotateTransform( 30.0F );

      // Draw rotated, translated ellipse to screen.
      e->Graphics->DrawEllipse( gcnew Pen( Color::Blue,3.0f ), 0, 0, 200, 80 );

}*/

/*this->x = x;
    this->y = y;
    this->r = r;
	this->g = g;
	this->circle1 = circle1;

    this->objects[this->count++];

    this->g = g;*/

/*
void Wheel::_Line(Graphics ^ g, PointF start, PointF end)
 {
            this.start = start;
            this.end = end;
            this.pen = pen;
        }



const double angleStep = 1;

// Wheel::Spoke(Graphics ^g, int x, int y, unsigned r, double startAngle)
//{
//	 this->g = g;
//   this->x = x;
//    this->y = y;
//    this->r = r;
//    this->angle = 3.14/180*startAngle;
//}



Wheel::Wheel()
{
  
}

Wheel::Wheel(Graphics ^ g, double x, double y, double r, int angle)
{
	this->g = g;
	this->x = x;
	this->y = y;
	this->r = r;
	this->angle = angle;
}

void Wheel::hide()
{
	Pen^ myPen = gcnew Pen(Color::White);
	g->DrawLine(myPen, (int)(x - (r / 2)*cos(angle*3.14 / 180) + r / 2), y - (r / 2)*sin(angle*3.14 / 180) + r / 2, x + (r / 2)*cos(angle*3.14 / 180) + r / 2, y + (r / 2)*sin(angle*3.14 / 180) + r / 2);
}

void Wheel::show()
{
	Pen^ myPen = gcnew Pen(Color::Red);
	g->DrawLine(myPen, (int)(x - (r / 2)*cos(angle*3.14 / 180) + r / 2), y - (r / 2)*sin(angle*3.14 / 180) + r / 2, x + (r / 2)*cos(angle*3.14 / 180) + r / 2, y + (r / 2)*sin(angle*3.14 / 180) + r / 2);
}

void Wheel::move(int dx, int dy)
{
	this->hide();
	this->rotate();
	x += dx;
	y += dy;
    this->show();
}

void Wheel::rotate()
{
	angle += angleStep;
	if (angle > 360)
		angle -= 360;
}*/
