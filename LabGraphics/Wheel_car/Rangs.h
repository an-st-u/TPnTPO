#include "line.h"
#include <iostream>
#include "gcroot.h"
using namespace System::Drawing;

class Rangs : public Line
{
public:

	//array<LineF>^ Line;

	//rgb color 

	void DrawLines(Graphics ^ g, array<PointF>^ points);

	void _Line(Graphics ^ g, PointF start, PointF end);

/* //для graphic.h
Line(int x1, int y1, int x2, int y2);
*/

    virtual void hide();
    virtual void show();
    virtual void move(int dx, int dy);
};

#endif
