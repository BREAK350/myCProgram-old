//---------------------------------------------------------------------------
#ifndef ObjectH
#define ObjectH
#include <math.h>
#include <stdio.h>
#include "T_Poligon.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class T_Object
{
    protected:
        int n;//кількість замкнутих ліній (полігонів)
        int *pn;//кількість точок кожної замкнутої лінії
        T_Point **p;//усі точки усіх ліній
        TColor *cl;//відповідний колір заливки полігона
        float Scale;//масштаб
        T_Point Where;//глобальне розташування
        float angle;//кут з додатньою віссю ох в радіанах
        T_Point GC(const T_Point &);//розташовує точку на координатній площині
        T_Point Rotate(const T_Point &);//повертає вектор з початком в (0;0) на кут
        T_Point Move(const T_Point &);//пересуває точку на вектор, заданий кутом і довжиною(швидкістю)
        T_Point Zoom(const T_Point &);//масштабує точку
        void DrawPoligon(TCanvas *,int);
        void SaveToFile(FILE *);
        void LoadFromFile(FILE *);
    public:
        T_Object();
        T_Object(const T_Object &);
        T_Object(int,int *,T_Point **,TColor *,float,T_Point, float);
        virtual void Init(int,int *,T_Point **,TColor *,float,T_Point, float);
        virtual ~T_Object();
        virtual void Draw(TCanvas *);
        virtual void SaveToFile(const char *);
        virtual void LoadFromFile(const char *);
        void SetAngleGradus(float);
        void SetWhere(T_Point);
        T_Point SearchCenter();
        float GetDiametr();
        float Distance(const T_Object &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
