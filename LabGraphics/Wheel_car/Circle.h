#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include "gcroot.h"
using namespace System::Drawing;
class Circle : public Pixel
{
public:
	
    unsigned r;

	Circle();
 	Circle(Graphics ^ g, int x, int y, unsigned r); // для Windows Forms

	/* //для graphic.h
Circle(int x, int y, unsigned r);
*/

    virtual void hide();
    virtual void show();
	virtual void move(int dx, int dy);
};

#endif
