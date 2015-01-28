//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Trajectory.h"
#pragma argsused
#include <iostream.h>
#include <conio.h>
//---------------------------------------------------------------------------
class T_Segment:public T_Curve
{
    public:
        double x0,y0,x1,y1;
        T_Segment(const double &_x0,const double &_y0,const double &_x1,const double &_y1)
        {
            x0=_x0; y0=_y0; x1=_x1; y1=_y1;
        }
        virtual int Value(const double &t,double &x,double &y);
};
//---------------------------------------------------------------------------
int T_Segment::Value(const double &t,double &x,double &y)
{
    x=(x1-x0)*t+x0;
    y=(y1-y0)*t+y0;
    return 1;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    T_Trajectory tr(3);
    double x,y,t=0;
    int i;
    tr.SetEpsilon(0.01);
    tr.SetLength(1);
    tr[0]=new T_Segment(0,0,4,0);
    tr[1]=new T_Segment(4,0,0,4);
    tr[2]=new T_Segment(0,4,0,0);

    for(i=0;i<50;i++)
    {
        //tr.GetPoint(t,x,y);
        tr.NextPoint_Right(t,x,y);
        cout<<x<<' '<<y<<endl;
        t=tr.Get_t();
    }
    getch();
    return 0;
}
//---------------------------------------------------------------------------
 