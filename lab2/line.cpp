#include "Line.h"
#include "graphics.h"
//Line::Line(inn x1, int y1, int x2, int y2)
//{
//x1=x1;
//y1=y1;
//x2=x2;
//y2=y2;
//}
void Line::Hide()
{
        setcolor(0);
	line(x1,y1,x2,y2);
	setcolor(WHITE);
}

void Line::Show()
{
	line(x1, y1, x2, y2);
  setcolor(WHITE);
  }

void Line::Move(int dx, int dy)
{
	Hide();
	x1 += dx;
	y1 += dy;
	x2 += dx;
	y2 += dy;
	Show();
}

void Line::output(char* fname)
{
    FILE * f = fopen(fname, "a");
    fprintf(f, "%s %d %d %d %d\n", "line:", x1, y1, x2, y2);
    fclose(f);
}
