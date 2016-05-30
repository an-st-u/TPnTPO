#include "circle.h"
#include "gcroot.h"
#include "line.h"
#include <cmath> 
#define PI 3.14159265 
#define MAX_RANGS_COUNT_LINES 10

using namespace System::Drawing;

class Wheel : public Circle//, public Line
{

		int count_lines;
		int angle;

public:

	Line *objects[MAX_RANGS_COUNT_LINES];
	Circle circle1;
	Wheel();

	//void add1(Circle circle1, Line *b2);
	

	Wheel(Graphics ^ g, int x, int y, int r, int count_lines);


	virtual void hide();
	virtual void show();
	virtual void move(int dx, int dy);
	void move1(int dx, int dy);


};

