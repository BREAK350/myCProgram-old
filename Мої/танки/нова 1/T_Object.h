//---------------------------------------------------------------------------
#ifndef T_ObjectH
#define T_ObjectH
#include <vcl.h>
//---------------------------------------------------------------------------
class T_Object
{
    protected:
        float X,Y;
        bool CrossTRect(TRect,TRect);
    public:
        T_Object(){X=Y=0;}
        virtual ~T_Object()=0;
        virtual void LoadFromFile(char *)=0;
        virtual void SaveToFile(char *)=0;
        virtual void Draw(TCanvas *)=0;
        virtual void Move()=0;
        virtual void Shot()=0;
        virtual bool Interaction(T_Object *)=0;
        virtual TRect ReturnTRect()=0;
        virtual bool Bang()=0;
        bool Cross(T_Object *);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 