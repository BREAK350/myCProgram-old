//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "T_Geometry.h"
//---------------------------------------------------------------------------
class T_Object
{
    public:
        T_Poligon Size;
        T_Vector Speed,Siting;
};
//---------------------------------------------------------------------------
class T_Track
{
    private:
        int N;
        T_Object **Obj;
    public:
        T_Poligon Border;
    public:
        T_Track();
        ~T_Track();
        void AddObject(const T_Object &);
        void AllMove();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 