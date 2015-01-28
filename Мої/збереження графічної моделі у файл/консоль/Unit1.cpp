//---------------------------------------------------------------------------
#pragma hdrstop
#include "func1.h"
#include <conio.h>
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
    TModel m;
    m.n_point=3;
    m.CreateGraf();
    m.point=(Point2D*)malloc(m.n_point*sizeof(Point2D));
    m.point[0].x=100;
    m.point[0].y=100;
    m.point[1].x=200;
    m.point[1].y=300;
    m.point[2].x=150;
    m.point[2].y=400;
    m.CreateLine(1,2);
    m.CreateLine(1,3);
    m.CreateLine(2,3);
    m.SaveToFile("Model1.model");
    getch();
    return 0;
}
//---------------------------------------------------------------------------
