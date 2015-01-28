//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    bmp=new Graphics::TBitmap;
    bmp->Width=ClientWidth;
    bmp->Height=ClientHeight;
    Or.Canvas=bmp->Canvas;
    PointR=5;
    E=PointR;
    Scale=1;
    Curr=NULL;
    ccCurr=NULL;
    WriteOr();
}
//---------------------------------------------------------------------------
void TMainForm::DrawPoints()
{
    Or.Canvas->Pen->Color=clBlue;
    Or.Canvas->Brush->Color=clBlue;
    Points.CurrSetFirst();
    while(Points.CurrCorrect())
    {
        T_Vector2d *p=Points.GetCurr();
        Or.Circle(*p,PointR);
        Points.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
void TMainForm::DrawCurrPoint()const
{
    if(Curr)
    {
        Or.Canvas->Pen->Color=clRed;
        Or.Canvas->Brush->Color=clRed;
        Or.Circle(*Curr,PointR);
    }
}
//---------------------------------------------------------------------------
void TMainForm::AddPoint(T_Vector2d *p)
{
    if(p)
    {
        Points.Add(p);
    }
}
//---------------------------------------------------------------------------
T_Vector2d* TMainForm::SearchF(const T_Vector2d &p)
{
    T_Vector2d *r=NULL;
    Points.CurrSetFirst();
    r=SearchN(p);
    return r;
}
//---------------------------------------------------------------------------
T_Vector2d* TMainForm::SearchN(const T_Vector2d &p)
{
    T_Vector2d *r=NULL;
    while(r==NULL && Points.CurrCorrect())
    {
        r=Points.GetCurr();
        if(((p-(*r)).Length()>E))
        {
            r=NULL;
            Points.CurrSetNext();
        }
    }
    return r;
}
//---------------------------------------------------------------------------
TbCurveVector* TMainForm::SearchCaseCurveF(const T_Vector2d &p)
{
    TbCurveVector *r=NULL;
    CaseCurve.CurrSetFirst();
    r=SearchCaseCurveN(p);
    return r;
}
//---------------------------------------------------------------------------
TbCurveVector* TMainForm::SearchCaseCurveN(const T_Vector2d &p)
{
    TbCurveVector *r=NULL;
    while(r==NULL && CaseCurve.CurrCorrect())
    {
        r=&CaseCurve.GetCurr();
        if(((p-r->Point).Length()>5*E))
        {
            r=NULL;
            CaseCurve.CurrSetNext();
        }
    }
    return r;
}
//---------------------------------------------------------------------------
void TMainForm::SetCurr(const int &x,const int &y)
{
    T_Vector2d p(Or.UnOrientX(x),Or.UnOrientY(y));
    Curr=SearchN(p);
    if(!Curr)
    {
        Curr=SearchF(p);
    }

    ccCurr=SearchCaseCurveN(p);
    if(!ccCurr)
    {
        ccCurr=SearchCaseCurveF(p);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MouseDown=true;
}
//---------------------------------------------------------------------------
void TMainForm::DrawTr()
{
    Or.Canvas->Pen->Color=clBlack;
    double t0=0,t1;
    T_Vector2d p;
    Tr.NextPoint_Right(t0,p);
    Or.MoveTo(p);
    t1=Tr.Get_t();
    while(t1>t0)
    {
        t0=t1;
        Tr.NextPoint_Right(t0,p);
        Or.LineTo(p);
        t1=Tr.Get_t();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormResize(TObject *Sender)
{
    bmp->Width=ClientWidth;
    bmp->Height=ClientHeight;
    DrawAll();
}
//---------------------------------------------------------------------------
void TMainForm::DrawAll()
{
    Or.Canvas->Brush->Color=clWhite;
    Or.Canvas->Rectangle(-1,-1,bmp->Width+1,bmp->Height+1);
    DrawTr();
    DrawCaseCurve();
    DrawPoints();
    DrawCurrPoint();
    Canvas->Draw(0,0,bmp);
}
//---------------------------------------------------------------------------
void TMainForm::LoadFromFile(const char *FileName)
{
    Points.DeleteAll();
    CaseCurve.DeleteAll();
    Tr.LoadFromFile(FileName);
    int i,n=Tr.GetCount();
    for(i=0;i<n;i++)
    {
        ViewCurve(Tr[i]);
    }
    CreateCaseCurve();
}
//---------------------------------------------------------------------------
void TMainForm::ViewCurve(T_Curve *Curve)
{
    T_Segment *Segment=dynamic_cast <T_Segment*>(Curve);
    T_Arc *Arc=dynamic_cast <T_Arc*>(Curve);
    T_HermiteCurve *HermiteCurve=dynamic_cast <T_HermiteCurve*>(Curve);
    T_BezierCurve *BezierCurve=dynamic_cast <T_BezierCurve*>(Curve);

    if(Segment)
    {
        AddPoint(&Segment->p0);
        AddPoint(&Segment->p1);
    }
    else
    if(Arc)
    {
        AddPoint(&Arc->c);
    }
    else
    if(HermiteCurve)
    {
        AddPoint(&HermiteCurve->p0);
        AddPoint(&HermiteCurve->p1);
        AddPoint(&HermiteCurve->q0);
        AddPoint(&HermiteCurve->q1);
    }
    else
    if(BezierCurve)
    {
        AddPoint(&BezierCurve->p0);
        AddPoint(&BezierCurve->p1);
        AddPoint(&BezierCurve->p2);
        AddPoint(&BezierCurve->p3);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::N2Click(TObject *Sender)
{
    if(OpenDialog1->Execute())
    {
        LoadFromFile(OpenDialog1->FileName.t_str());
        DrawAll();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormMouseWheelDown(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    Or.Scale.X*=0.9;
    Or.Scale.Y*=0.9;
    DrawAll();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormMouseWheelUp(TObject *Sender,
      TShiftState Shift, TPoint &MousePos, bool &Handled)
{
    Or.Scale.X*=1.1;
    Or.Scale.Y*=1.1;
    DrawAll();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    if(MouseDown)
    {
        Or.Shift.X+=X-Cursor.x;
        Or.Shift.Y+=Y-Cursor.y;
        WriteOr();
        DrawAll();
    }
    Cursor.x=X;
    Cursor.y=Y;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormClick(TObject *Sender)
{
    SetCurr(Cursor.x,Cursor.y);
    if(ccCurr)
    {
        OpenPanelAndWriteData(ccCurr->Curve);
    }
    DrawAll();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    MouseDown=false;
}
//---------------------------------------------------------------------------
void TMainForm::ReadOr()
{
    Or.Shift.X=StrToFloat(Edit1->Text);
    Or.Shift.Y=StrToFloat(Edit2->Text);
    Or.Scale.X=StrToFloat(Edit3->Text);
    Or.Scale.Y=StrToFloat(Edit4->Text);
    Or.Up=CheckBox2->Checked;
    Or.Right=CheckBox1->Checked;
}
//---------------------------------------------------------------------------
void TMainForm::WriteOr()
{
    Edit1->Text=FloatToStr(Or.Shift.X);
    Edit2->Text=FloatToStr(Or.Shift.Y);
    Edit3->Text=FloatToStr(Or.Scale.X);
    Edit4->Text=FloatToStr(Or.Scale.Y);
    CheckBox2->Checked=Or.Up;
    CheckBox1->Checked=Or.Right;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    ReadOr();
    DrawAll();
}
//---------------------------------------------------------------------------
void TMainForm::CreateCaseCurve()
{
    TbCurveVector cv;
    int n=Tr.GetCount();
    double t=0.5;
    while(t<n)
    {
        Tr.NextPoint_Right(t,cv.Point);
        cv.Curve=Tr[t];
        CaseCurve.Add(cv);
        t++;
    }
}
//---------------------------------------------------------------------------
void TMainForm::DrawCaseCurve()
{
    Or.Canvas->Pen->Color=clPurple;
    Or.Canvas->Brush->Style=bsClear;
    CaseCurve.CurrSetFirst();
    while(CaseCurve.CurrCorrect())
    {
        Or.Circle(CaseCurve.GetCurr().Point,5*PointR);
        CaseCurve.CurrSetNext();
    }
    Or.Canvas->Brush->Style=bsSolid;
}
//---------------------------------------------------------------------------
void TMainForm::OpenPanelAndWriteData(T_Curve *Curve)
{
    T_Segment *Segment=dynamic_cast <T_Segment*>(Curve);
    T_Arc *Arc=dynamic_cast <T_Arc*>(Curve);
    T_HermiteCurve *HermiteCurve=dynamic_cast <T_HermiteCurve*>(Curve);
    T_BezierCurve *BezierCurve=dynamic_cast <T_BezierCurve*>(Curve);

    if(Segment)
    {
        gbSegment->Visible=true;
        Edit5->Text=FloatToStr(Segment->p0.X);
        Edit6->Text=FloatToStr(Segment->p0.Y);
        Edit7->Text=FloatToStr(Segment->p1.X);
        Edit8->Text=FloatToStr(Segment->p1.Y);
    }
    else
    if(Arc)
    {
        AddPoint(&Arc->c);
    }
    else
    if(HermiteCurve)
    {
        AddPoint(&HermiteCurve->p0);
        AddPoint(&HermiteCurve->p1);
        AddPoint(&HermiteCurve->q0);
        AddPoint(&HermiteCurve->q1);
    }
    else
    if(BezierCurve)
    {
        AddPoint(&BezierCurve->p0);
        AddPoint(&BezierCurve->p1);
        AddPoint(&BezierCurve->p2);
        AddPoint(&BezierCurve->p3);
    }
}
//---------------------------------------------------------------------------
void TMainForm::SavePanelAndReadData(T_Curve *Curve)
{
    T_Segment *Segment=dynamic_cast <T_Segment*>(Curve);
    T_Arc *Arc=dynamic_cast <T_Arc*>(Curve);
    T_HermiteCurve *HermiteCurve=dynamic_cast <T_HermiteCurve*>(Curve);
    T_BezierCurve *BezierCurve=dynamic_cast <T_BezierCurve*>(Curve);

    if(Segment)
    {
        gbSegment->Visible=true;
        Segment->p0.X=StrToFloat(Edit5->Text);
        Segment->p0.Y=StrToFloat(Edit6->Text);
        Segment->p1.X=StrToFloat(Edit7->Text);
        Segment->p1.Y=StrToFloat(Edit8->Text);
    }
    else
    if(Arc)
    {
        AddPoint(&Arc->c);
    }
    else
    if(HermiteCurve)
    {
        AddPoint(&HermiteCurve->p0);
        AddPoint(&HermiteCurve->p1);
        AddPoint(&HermiteCurve->q0);
        AddPoint(&HermiteCurve->q1);
    }
    else
    if(BezierCurve)
    {
        AddPoint(&BezierCurve->p0);
        AddPoint(&BezierCurve->p1);
        AddPoint(&BezierCurve->p2);
        AddPoint(&BezierCurve->p3);
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button3Click(TObject *Sender)
{
    gbSegment->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
    if(ccCurr)
    {
        SavePanelAndReadData(ccCurr->Curve);
        CaseCurve.DeleteAll();
        CreateCaseCurve();
        DrawAll();
    }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button4Click(TObject *Sender)
{
    GroupBox1->Visible=false;
}
//---------------------------------------------------------------------------

