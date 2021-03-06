//---------------------------------------------------------------------------
#ifndef T_RectH
#define T_RectH
#include "T_Object.h"
#include <math.h>
//---------------------------------------------------------------------------
class T_Rect:public T_Object
{
    protected:
        float v,angle;
    public:
        T_Rect():T_Object(){v=angle=0;}
        virtual ~T_Rect(){}
        virtual void LoadFromFile(char *){}
        virtual void SaveToFile(char *){}
        virtual void Draw(TCanvas *);
        virtual void Move();
        virtual void Shot(){}
        virtual bool Interaction(T_Object *){return false;}
        virtual TRect ReturnTRect();
        virtual bool Bang(){return false;}
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 