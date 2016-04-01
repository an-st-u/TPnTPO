#include "Arc.h"
#include "graphics.h"

void Arc::Hide()
{
    setcolor(0);
    arc(x, y, sa, ea, r);
    setcolor(WHITE);
}

void Arc::Show()
{
    setcolor(WHITE);
    arc(x, y, sa, ea, r);
}

void Arc::Move(int dx, int dy)
{
    Hide();
    x += dx;
    y += dy;
    Show();
}

void Arc::output(char* fname)
{
    FILE * f = fopen(fname, "a");
    fprintf(f, "%s %d %d %d %d %d\n", "arc:", x, y, sa, ea, r);
    fclose(f);
}
