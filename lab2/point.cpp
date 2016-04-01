#include "Point.h"
#include "graphics.h"
Point::Point(int x, int y)
{
    x = x;
    y = y;
}
void Point::Hide()
{
    putpixel(x, y,0);
}
void Point::Show()
{
    putpixel(x, y, col);
}
void Point::Move(int dx, int dy)
{
    Hide();
    x += dx;
    y += dy;
    Show();
}


void Point::output(char* fname)
{
    FILE * f = fopen(fname, "w");
    fprintf(f, "%s %d %d\n", "point:", x, y);
    fclose(f);
}
