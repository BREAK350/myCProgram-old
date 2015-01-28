//---------------------------------------------------------------------------
#ifndef TbVisualElementH
#define TbVisualElementH
#include <vcl.h>
#include "T_Vector2d.h"
#include "TbList2.h"
//---------------------------------------------------------------------------
class TbVisualElementBase
{
    public:
        virtual bool Draw(TCanvas *Canvas){ return false; }
};
//---------------------------------------------------------------------------
class TbVisualElementCircle:public TbVisualElementBase
{
    public:
        TbVector2d Center,CenterFuture;
        double Radius,Speed;
        bool isMove()const { return CenterFuture!=Center; }
        virtual bool Draw(TCanvas *Canvas);

};
//---------------------------------------------------------------------------
class TbVisualElementEdge:public TbVisualElementBase
{
    public:
        TbVisualElementCircle *First,*Second;
        virtual bool Draw(TCanvas *Canvas);
};
//---------------------------------------------------------------------------
class TbVisualElementArrow:public TbVisualElementEdge
{
    public:
        double Length,Speed;
        virtual bool Draw(TCanvas *Canvas);
};
//---------------------------------------------------------------------------
class TbVisualElementCircleName:public TbVisualElementCircle
{
    public:
        String Name;
        virtual bool Draw(TCanvas *Canvas);
};
//---------------------------------------------------------------------------
class TbVisualElementArrowName:public TbVisualElementArrow
{
    public:
        String Name;
        virtual bool Draw(TCanvas *Canvas);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void LocatePointOnCircle(const TbVector2d &Center,const int &n,
    TbVector2d *PointCenter,const double &MinDistance);
//---------------------------------------------------------------------------
void DrawElementFromList(TCanvas *Canvas,TbList2 <TbVisualElementBase*> &VEB,
    const int &Interval,const TRect &Rect);
//---------------------------------------------------------------------------
#endif

