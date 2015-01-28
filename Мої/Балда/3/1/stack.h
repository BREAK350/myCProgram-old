//---------------------------------------------------------------------------
#ifndef stackH
#define stackH
#include <stdio.h>
#include <vcl.h>
//---------------------------------------------------------------------------
class T_Stack
{
    private:
        int Size,Top;
        TPoint *Stack;
    public:
        T_Stack();
        T_Stack(const int &s);
        T_Stack(const T_Stack &s);
        ~T_Stack();
        T_Stack& operator = (const T_Stack &s); 
        int Search(const TPoint &p)const;
        int Search(const int &x,const int &y)const { return Search(TPoint(x,y)); }
        int Write(const int &x,const int &y);
        int Write(const TPoint &p) { return Write(p.x,p.y); }
        int Read(TPoint &p);
        int GetTop()const { return Top; }
        TPoint GetElement(const int &i);
        void Clear() { Top=0; }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
