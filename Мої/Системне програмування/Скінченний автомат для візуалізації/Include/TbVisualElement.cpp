//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbVisualElement.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
bool TbVisualElementCircle::Draw(TCanvas *Canvas)
{
    bool Execute=false;
    if(Center!=CenterFuture)
    {
        TbVector2d Road=CenterFuture-Center;
        if(Road.GetLength()>=Speed)
        {
            Road.SetLength(Speed);
            Center=Center+Road;
        }
        else
        {
            Center=CenterFuture;
        }
        if(Road.GetLength()>0)
        {
            Execute=true;
        }
    }
    Canvas->Ellipse(Center.X-Radius,Center.Y-Radius,Center.X+Radius,Center.Y+Radius);
    return Execute;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool TbVisualElementEdge::Draw(TCanvas *Canvas)
{
    First->Center.MoveTo(Canvas);
    Second->Center.LineTo(Canvas);
    return false;
}
//---------------------------------------------------------------------------
bool TbVisualElementArrow::Draw(TCanvas *Canvas)
{
    bool Execute=false;
    TbVector2d Edge=Second->Center-First->Center;
    if(Speed>0)
    {
        if(Length+Speed<Edge.GetLength())
        {
            Length+=Speed;
            Execute=true;
        }
        else
        {
            Length=Edge.GetLength();
        }
    }
    if(Speed<0)
    {
        if(Length-Speed>0)
        {
            Length-=Speed;
            Execute=true;
        }
        else
        {
            Length=0;
        }
    }
    if(Length-Second->Radius>0)
    {
        Edge.SetLength(Length-Second->Radius);
        First->Center.MoveTo(Canvas);
        (First->Center+Edge).LineTo(Canvas);
        TbVector2d v=Edge;
        v.Reverse();
        v.SetLength(10);
        v.Rotate(30*M_PI/180);
        (First->Center+Edge).MoveTo(Canvas);
        (First->Center+Edge+v).LineTo(Canvas);
        v.Rotate(-60*M_PI/180);
        (First->Center+Edge).MoveTo(Canvas);
        (First->Center+Edge+v).LineTo(Canvas);
    }
    return Execute;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void LocatePointOnCircle(const TbVector2d &Center,const int &n,
    TbVector2d *PointCenter,const double &MinDistance)
{
    if(n>1)
    {
        double Angle=360.0/n;
        TbVector2d v(0,100);
        v.SetLength(MinDistance/(2*sin(M_PI/n)));
        for(int i=0;i<n;i++)
        {
            PointCenter[i]=v+Center;
            v.Rotate(Angle*M_PI/180);
        }
    }
    else
    {
        if(n==1)
        {
            PointCenter[0]=Center;
        }
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
bool TbVisualElementCircleName::Draw(TCanvas *Canvas)
{
    bool Execute=TbVisualElementCircle::Draw(Canvas);
    Canvas->TextOutA(Center.X-Canvas->TextWidth(Name)/2,
        Center.Y-Canvas->TextHeight(Name)/2,Name);
    return Execute;
}
//---------------------------------------------------------------------------
bool TbVisualElementArrowName::Draw(TCanvas *Canvas)
{
    bool Execute=TbVisualElementArrow::Draw(Canvas);
    if(Length>2*Canvas->TextHeight(Name))
    {
        TbVector2d v=Second->Center-First->Center;
        v.SetLength(Length/4.0);
        v=v+First->Center;
        Canvas->TextOutA(v.X-Canvas->TextWidth(Name)/2,
                         v.Y-Canvas->TextHeight(Name)/2,Name);
    }
    return Execute;
}
//---------------------------------------------------------------------------
void DrawElementFromList(TCanvas *Canvas,TbList2 <TbVisualElementBase*> &VEB,
    const int &Interval,const TRect &Rect)
{
    int Execute=0;
    do
    {
        Canvas->Rectangle(Rect);
        Execute=0;
        VEB.CurrSetFirst();
        while(VEB.CurrCorrect())
        {
            Execute+=VEB.GetCurr()->Draw(Canvas);
            VEB.CurrSetNext();
        }
        Sleep(Interval);
    }
    while(Execute>0);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

