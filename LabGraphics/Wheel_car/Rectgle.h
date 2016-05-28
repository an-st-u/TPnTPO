#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base.h"
#include "gcroot.h"


using namespace System::Drawing;
class Rectgle : public Base
{
    int x1, y1;
    int x2, y2;
    gcroot<Graphics ^> g; // для Windows Forms
public:
	Rectgle(Graphics ^ g, int x1, int y1, int x2, int y2); // для Windows Forms

	virtual void hide();
	virtual void show();
	virtual void move(int dx, int dy);
	//virtual void move1(int, int, int, int);
};

#endif
