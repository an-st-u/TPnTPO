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
	
    virtual void hide();
    virtual void show();
	virtual void move(int dx, int dy);


};
