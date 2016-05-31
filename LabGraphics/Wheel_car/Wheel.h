#include "circle.h"
#include "gcroot.h"
#include "line.h"
#include <cmath> 
#define PI 3.14159265 
#define MAX_RANGS_COUNT_LINES 6

using namespace System::Drawing;

class Wheel : public Circle
{

	Line *objects = new Line[MAX_RANGS_COUNT_LINES];
	int wheel_angle;
	int tire;

public:

	Wheel();
	Wheel(Graphics ^ g, int x, int y, int r, int tire);
	virtual void hide();
	virtual void show();
	virtual void move(int dx, int dy);


};

