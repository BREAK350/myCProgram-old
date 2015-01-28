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
        virtual void DrawNo(TCanvas *,TRect)=0;//���� ����� ���� �� ����� �������
        virtual void DrawIs(TCanvas *,TRect)=0;//���� ����� ����� �� ����� �������
        virtual void DrawWas(TCanvas *,TRect)=0;//���� ����� ��� �� ����� �������
        virtual void SaveToFile(FILE *)=0;
        virtual void LoadFromFile(FILE *)=0;
        virtual bool CanGo()=0;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
