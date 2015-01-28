//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "T_Poligon.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#define RADIUS 4
#define MAX_POINTS 1024
TForm1 *Form1;
TPoint Points[MAX_POINTS],Buf[MAX_POINTS];
T_Poligon *poligon;
T_Point Cur,XY(0,0);
int i=0,j,n=0;
TColor clBrush;
int SignX=1,SignY=1,S=1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Cur.Init((int)(SignX*(X/S-XY.GetX()/S)),(int)(SignY*(Y/S-XY.GetY()/S)));
    Label6->Caption=IntToStr((int)Cur.GetX());
    Label6->Caption=Label6->Caption+';';
    Label6->Caption=Label6->Caption+IntToStr((int)Cur.GetY());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    i=0;
    while(i<n && Cur.Distance(Points[i])>RADIUS)
    {
        i++;
    }
    if(i>=n && n<MAX_POINTS-1)
    {
        Points[n]=Cur;
        n++;
    }
    Draw();
    Edit1->Text=IntToStr(Points[i].x);
    Edit2->Text=IntToStr(Points[i].y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    ColorDialog1->Execute();
    Canvas->Brush->Color=ColorDialog1->Color;
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    ColorDialog1->Execute();
    Canvas->Pen->Color=ColorDialog1->Color;
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Points[i].x=StrToInt(Edit1->Text);
    Points[i].y=StrToInt(Edit2->Text);
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    i++;
    if(i>=n)
    {
        i=0;
    }
    Edit1->Text=IntToStr(Points[i].x);
    Edit2->Text=IntToStr(Points[i].y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    i--;
    if(i<=0)
    {
        i=n-1;
    }
    Edit1->Text=IntToStr(Points[i].x);
    Edit2->Text=IntToStr(Points[i].y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    for(j=i;j<n-1;j++)
    {
        Points[j]=Points[j+1];
    }
    n--;
    if(n<0)
    {
        n=0;
    }
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    int left,top,right,bottom;
    float s;
    SaveDialog1->Execute();
    T_Point *p=new T_Point[n];
    left=right=Points[0].x;
    top=bottom=Points[0].y;
    for(i=0;i<n;i++)
    {
        p[i]=Points[i];
        if(left>Points[i].x)
        {
            left=Points[i].x;
        }
        if(right<Points[i].x)
        {
            right=Points[i].x;
        }
        if(top>Points[i].y)
        {
            top=Points[i].y;
        }
        if(bottom<Points[i].y)
        {
            bottom=Points[i].y;
        }
    }
    if(abs(right-left)>abs(bottom-top))
    {
        s=abs(right-left);
    }
    else
    {
        s=abs(bottom-top);
    }
    if(s==0)
    {
        return;
    }
    FILE *f=fopen("GGGGGGG.txt","wt");
    for(i=0;i<n;i++)
    {
        //p[i].GetX()   (right+left)/2.0
        p[i]=T_Point(p[i].GetX()/s-(float)(right+left)/(2*s),p[i].GetY()/s-(float)(bottom+top)/(2*s));
        fprintf(f,"(%1.2f;%1.2f)\n",p[i].GetX(),p[i].GetY());
    }
    fclose(f);
    poligon=new T_Poligon(n,Canvas->Pen->Color,Canvas->Brush->Color,p);
    poligon->SaveToFile(SaveDialog1->FileName.c_str());
    delete poligon;
    delete[] p;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    if(n<MAX_POINTS-1)
    {
        Points[n].x=StrToInt(Edit1->Text);
        Points[n].y=StrToInt(Edit2->Text);
        n++;
    }
    Draw();
}
//---------------------------------------------------------------------------
void TForm1::Draw()
{
    int i;
    clBrush=Canvas->Brush->Color;
    Canvas->Brush->Color=clWhite;
    Canvas->Rectangle(-1,-1,1000,1000);
    Canvas->Brush->Color=clBrush;
    for(i=0;i<n;i++)
    {
        Buf[i]=TPoint(Points[i].x*S*SignX+XY.GetX(),Points[i].y*S*SignY+XY.GetY());
    }
    Canvas->Polygon(Buf,n-1);
    for(j=0;j<n;j++)
    {
        Canvas->Ellipse(Buf[j].x-RADIUS,Buf[j].y-RADIUS,Buf[j].x+RADIUS,Buf[j].y+RADIUS);
    }
    Canvas->Rectangle(XY.GetX()-RADIUS,XY.GetY()-RADIUS,XY.GetX()+RADIUS,XY.GetY()+RADIUS);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    XY.SetX(StrToFloat(Edit3->Text));
    XY.SetY(StrToFloat(Edit4->Text));
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    SignX=-SignX;
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    SignY=-SignY;
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
    S=StrToFloat(Edit5->Text);
    if(S<=0)
    {
        S=1;
    }
    Draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
    FILE *f;
    SaveDialog1->Execute();
    f=fopen(SaveDialog1->FileName.c_str(),"wb");
    fwrite(&n,sizeof(int),1,f);
    fwrite(Points,sizeof(TPoint),n,f);
    fclose(f);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender)
{
    FILE *f;
    OpenDialog1->Execute();
    f=fopen(OpenDialog1->FileName.c_str(),"rb");
    fread(&n,sizeof(int),1,f);
    fread(Points,sizeof(TPoint),n,f);
    fclose(f);
    Draw();
}
//---------------------------------------------------------------------------

