#include "Wheel.h"

using namespace System::Drawing;


//Wheel::Wheel(Graphics ^ g, int x, int y, int x1, int x2, int y1, int y2, Circle circle1, Line *objects): Circle(g,x,y,r), Line(g, x1, x2, y1, y2)



Wheel::Wheel()
{
   unsigned int count = 0;
}


void Wheel::add1(Circle circle1, Line *b2)
{
    if(this->count >= 100) {
        std::cout << "maximum count of elements reached" << std::endl;
        //exit(1);
        return;
    }
    this->objects[this->count++] = b2;

	this->circle1 = circle1;

}


void Wheel::hide()
{

	this->circle1.hide();

	for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->hide();
    }

	this->objects[this->count++];

}

void Wheel::show()
{

	this->circle1.show();

	for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->show();
    }

	this->objects[this->count++];

}


void Wheel::move1(int dx, int dy)
{

    for(unsigned i = 0; i < this->count; i++) {
        this->objects[i]->move(dx, dy);
    }

}



void Wheel::move(int dx, int dy)
{

    this->hide();


	//this->x += ((dx) * 2 - r*sin((dx) * PI /(PI * r)));
	//this->y += r - r*cos((dy) * PI / (PI * r));

	this->x += dx;
	this->y += dy;

	this->x1 += dx;
	this->y1 += dy;

	this->x2 += dx;
	this->y2 += dy;

	this->show();
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
*/
