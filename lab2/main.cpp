#include <dos.h>
#include <graphics.h>
#include <conio.h>
#include "Point.h"
#include "Okr.h"
#include "Figure.h"
#include "Line.h"

void main()
{
int gdriver = DETECT, gmode;

initgraph(&gdriver, &gmode, "c:\\BORLANDC\\BGI");
Figure F=Figure();
//FILE * f;
//FILE * ff;
char fname[81];
char fpath[]="c:\\file.txt";
strcpy(fname,fpath);
fopen(fname, "r");

//fclose(f);

F.read(fname);

//printf("Enter output filename:\n");
//scanf("%s", fname);
char fnameo[81];
char fpatho[]="c:\\file1.txt";
strcpy(fnameo,fpatho);
fopen(fnameo, "r");

F.write(fnameo);

F.Show();

for (int i=0; i<400; i++){

F.Move(1, 0);

delay(100);

}

closegraph();
}
