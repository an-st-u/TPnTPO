#ifndef LINE_H
#define LINE_H
#define PI 3.14159265
#include "base.h"
#include <iostream>
#include "gcroot.h"
using namespace System::Drawing;

class Line : public Base
{

public:
    int x1, y1;
    int x2, y2;
    gcroot<Graphics ^> g2; // для Windows Forms

	Line();
	Line(Graphics ^ g2, int x1, int y1, int x2, int y2); // для Windows Forms
    virtual void hide();
    virtual void show();
    virtual void move(int dx, int dy);
	virtual void rotate(int x, int y, int r, int angle);
};
#endif