//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "T_List2.h"
//---------------------------------------------------------------------------
struct T_Rect
{
    int Left,Top,Right,Bottom;
    T_Rect() {}
    T_Rect(const int &left,const int &top,const int &right,const int &bottom)
    {
        Left=left; Right=right; Top=top; Bottom=bottom;
    }
};
//---------------------------------------------------------------------------
struct T_Link
{
    int min,max;
    T_Link() {}
    T_Link(const int &c,const int &d)
    {
        min=(c>d)?(d):(c);
        max=(c<d)?(d):(c);
    }
};
//---------------------------------------------------------------------------
bool operator > (const T_Link &Link1,const T_Link &Link2);
bool operator >= (const T_Link &Link1,const T_Link &Link2);
bool operator < (const T_Link &Link1,const T_Link &Link2);
bool operator <= (const T_Link &Link1,const T_Link &Link2);
bool operator == (const T_Link &Link1,const T_Link &Link2);
bool operator != (const T_Link &Link1,const T_Link &Link2);
//---------------------------------------------------------------------------
void CreateTrack(int **Track,const int &n,const int &m);
T_Rect CreateTrack(int **Track,const int &n,const int &m,const int &si,const int &sj,
    const int &in);
T_Link* CreateLink(int **Track,const int &n,const int &m,int &ln);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
