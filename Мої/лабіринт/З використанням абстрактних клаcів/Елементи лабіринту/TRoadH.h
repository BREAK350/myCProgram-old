//---------------------------------------------------------------------------
#ifndef TRoadHH
#define TRoadHH
#include "TElementH.h"
//---------------------------------------------------------------------------
class TRoad:public TElement
{
    private:
        TColor cl;
    public:
        virtual ~TRoad(){};
        virtual void Draw(TCanvas *,TRect);
        virtual void SaveToFile(FILE *){};
        virtual void LoadFromFile(FILE *){};
        virtual bool CanGo(){return true;};
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
