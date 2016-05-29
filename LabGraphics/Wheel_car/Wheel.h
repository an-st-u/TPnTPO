#include "circle.h"
#include "gcroot.h"
#include "line.h"
#include <cmath> 
#define PI 3.14159265 
#define MAX_RANGS_COUNT 100

using namespace System::Drawing;

class Wheel : public Circle, public Line
{

		unsigned int count;

public:

	Line *objects[MAX_RANGS_COUNT];
	Circle circle1;

	Wheel();

	void add1(Circle circle1, Line *b2);
	
	
    void hide();
    void show();

	void move(int dx, int dy);
	void move1(int dx, int dy);


};
