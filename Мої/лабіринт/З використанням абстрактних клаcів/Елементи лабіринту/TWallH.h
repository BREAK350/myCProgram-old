//---------------------------------------------------------------------------
#ifndef TWallHH
#define TWallHH
#include "TElementH.h"
//---------------------------------------------------------------------------
class TWall:public TElement
{
    private:
        TColor cl;
    public:
        virtual ~TWall(){};
        virtual void DrawNo(TCanvas *,TRect);
        virtual void DrawIs(TCanvas *,TRect){}
        virtual void DrawWas(TCanvas *,TRect){};
        virtual void SaveToFile(FILE *){};
        virtual void LoadFromFile(FILE *){};
        virtual bool CanGo(){return false;}
};
//---------------------------------------------------------------------------
#endif
 