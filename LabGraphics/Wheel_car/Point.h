#ifndef POINT_H
#define POINT_H

#include "base.h"
#include "gcroot.h"
using namespace System::Drawing;
class Pixel : public Base
{
//для наследования
public:

	int x, y;
    gcroot<Graphics ^> g; // для Windows Forms

	Pixel();
	Pixel(Graphics ^ g, int x, int y); // для Windows Forms

/* //для graphic.h
Point(int x, int y);
*/

    virtual void hide();
    virtual void show();
    virtual void move(int, int);
};

#endif
