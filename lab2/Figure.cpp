#include "Figure.h"
#include <string.h>

Figure::Figure()
{
    N = 0;
}
void Figure::Hide() {
    for (int i = 0; i < N; i++)
        A[i]->Hide();
}
void Figure::Show() {
    for (int i = 0; i < N; i++)
        A[i]->Show();
}

void Figure::Move(int dx, int dy) {
    for (int i = 0; i < N; i++)
        this->A[i]->Move(dx, dy);
}

void Figure::Add(Base *Ptr) {
    if (N < 100)
        A[N++] = Ptr;
}

void Figure::read(char* fname) {
    FILE * f= fopen(fname, "r");
    while(!feof(f))
    {
       char id[16];
	fscanf(f, "%s", id);
	if(!strcmp(id, "point:"))
	{
		int x, y,z;
		fscanf(f, "%d%d%d", &x, &y,&z);
	       Point *  p= new Point(x, y,z);
	       Add(p);
	}

       if(!strcmp(id, "okr:"))

	{
		int x, y, r;
		fscanf(f, "%d%d%d", &x, &y, &r);
		Okr *o=new Okr(x, y, r);
                Add(o);
	}
	if(!strcmp(id, "line:"))
	{
		int x1, y1, x2, y2;
		fscanf(f, "%d%d%d%d", &x1, &y1, &x2, &y2);
		Line* l=new Line(x1, y1, x2, y2);
		//Add((Base*)&l);
 Add(l);
	}
	// if (id[0]=='a')
	if(!strcmp(id, "arc:"))
	{
		int x, y, sa, ea, r;
		fscanf(f, "%d%d%d%d%d", &x, &y, &sa, &ea, &r);
		Arc *a=new Arc(x, y, sa, ea, r);
		//Add((Base*)&a);
Add(a);
	}
    }

}


void Figure::write(char* fnameo)
{
    for(int i = 0; i < N; i++)
	A[i]->output(fnameo);
}
