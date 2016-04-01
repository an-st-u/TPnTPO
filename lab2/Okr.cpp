#include "Okr.h"
#include "graphics.h"
void Okr::Hide()
{
    setcolor(0);
    circle(x, y, r);
    setcolor(WHITE);
}
void Okr::Show()
{
    setcolor(WHITE);
    circle(x, y, r);
}

void Okr::Move(int dx, int dy)
{

    Hide();
    x += dx;
    y += dy;
    Show();
}

void Okr::output(char* fname)
{
    FILE * f = fopen(fname, "a");
    fprintf(f, "%s %d %d %d\n", "okr:", x, y, r);
    fclose(f);
}
