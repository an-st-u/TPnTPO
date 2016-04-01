#include "Point.h"
#ifndef LINE_H
#define LINE_H
class Line :
	public Point
{
	int x1, y1, x2, y2;
public:
	Line() :Point(){};
	Line(int _x1, int _y1, int _x2, int _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}
	virtual void Hide();
	virtual void Show();
	virtual void Move(int dx, int dy);
	virtual void output(char* fnameo);
};

#endif
