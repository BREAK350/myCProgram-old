//---------------------------------------------------------------------------
#ifndef TElementHH
#define TElementHH
#include <vcl.h>
#include <stdio.h>
//---------------------------------------------------------------------------
class TElement
{
    public:
        virtual ~TElement(){};
        virtual void DrawNo(TCanvas *,TRect)=0;//коли нікого нема на цьому елементі
        virtual void DrawIs(TCanvas *,TRect)=0;//коли хтось стоїть на цьому елементі
        virtual void DrawWas(TCanvas *,TRect)=0;//коли хтось був на цьому елементі
        virtual void SaveToFile(FILE *)=0;
        virtual void LoadFromFile(FILE *)=0;
        virtual bool CanGo()=0;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
