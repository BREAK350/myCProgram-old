//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "func1.h"
#define MAXN 300
#define r 3
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1   *Form1;
Point3D  XY,
         cur,
         point,t;
TModel   model;
int      I,J,N,pl=1;
location data;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    XY.x=Form1->ClientWidth/2;
    XY.y=(Form1->ClientHeight-Panel1->Height)/2;
    XY.z=0;
    Canvas->Pen->Color=clWhite;
    Canvas->Pen->Width=1;
    Canvas->Brush->Style=bsClear;
    model.n_point=MAXN;
    model.point=(Point3D*)malloc(model.n_point*sizeof(Point3D));
    model.CreateGraf();
    model.n_point=N=I=J=0;
    Form1->Show();
    cur.z=10;
    FormXY(XY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    cur.x=X-XY.x;
    cur.y=XY.y-Y;
    Label1->Caption="Курсор("+FloatToStr(cur.x)+";"+FloatToStr(cur.y)+";"+FloatToStr(cur.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
    XY.x=Form1->ClientWidth/2;
    XY.y=(Form1->ClientHeight-Panel1->Height)/2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    Canvas->Pixels[point.x+XY.x][XY.y-point.y]=clBlack;
    point=cur;
    Canvas->Pixels[point.x+XY.x][XY.y-point.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    int i;
    for(i=0;i<model.n_point;i++)
    {
        if(model.point[i].x==point.x && model.point[i].y==point.y)
        {
            break;
        }
    }
    if(i==model.n_point)
    {
        model.point[model.n_point]=point;
        Canvas->Pixels[point.x+XY.x][XY.y-point.y]=clWhite;
        model.Show(XY);
        model.n_point++;
        //point.x=point.y=0;
    }
    Label3->Caption="Всього точок "+IntToStr(model.n_point);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    t=model.point[I];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    if(model.n_point>1)
    {
        I--;
        if(I<0)
        {
            I=model.n_point-1;
            if(I==J)
            {
                I--;
            }
        }
        else
        {
            if(I==J)
            {
                I--;
                if(I<0)
                {
                    I=model.n_point-1;
                }
            }
        }
    }
    Canvas->Pen->Color=clLime;
    t=model.point[I];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    Label4->Caption="("+FloatToStr(model.point[I].x)+";"+FloatToStr(model.point[I].y)+";"+FloatToStr(model.point[I].z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    t=model.point[I];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    if(model.n_point>1)
    {
        I++;
        if(I>=model.n_point)
        {
            I=0;
            if(I==J)
            {
                I++;
            }
        }
        else
        {
            if(I==J)
            {
                I++;
                if(I>=model.n_point)
                {
                    I=0;
                }
            }
        }
    }
    Label4->Caption="("+FloatToStr(model.point[I].x)+";"+FloatToStr(model.point[I].y)+";"+FloatToStr(model.point[I].z)+")";
    Canvas->Pen->Color=clLime;
    t=model.point[I];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    t=model.point[J];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    if(model.n_point>1)
    {
        J--;
        if(J<0)
        {
            J=model.n_point-1;
            if(J==I)
            {
                J--;
            }
        }
        else
        {
            if(J==I)
            {
                J--;
                if(J<0)
                {
                    J=model.n_point-1;
                }
            }
        }
    }
    Canvas->Pen->Color=clRed;
    t=model.point[J];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    Label6->Caption="("+FloatToStr(model.point[J].x)+";"+FloatToStr(model.point[J].y)+";"+FloatToStr(model.point[J].z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    t=model.point[J];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    if(model.n_point>1)
    {
        J++;
        if(J>=model.n_point)
        {
            J=0;
            if(J==I)
            {
                J++;
            }
        }
        else
        {
            if(J==I)
            {
                J++;
                if(J>=model.n_point)
                {
                    J=0;
                }
            }
        }
    }
    Canvas->Pen->Color=clRed;
    t=model.point[J];
    t=_3DTo2D(t);
    Canvas->Ellipse(t.x+XY.x-r,XY.y-t.y+r,t.x+XY.x+r,XY.y-t.y-r);
    Label6->Caption="("+FloatToStr(model.point[J].x)+";"+FloatToStr(model.point[J].y)+";"+FloatToStr(model.point[J].z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.y+=pl;
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.y-=pl;
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.x+=pl;
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.x-=pl;
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    model.CreateLine(I+1,J+1);
    Canvas->Pen->Color=clWhite;
    model.Show(XY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
    model.SaveToFile(Edit1->Text.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
    model.DeleteLine(I+1,J+1);
    Canvas->Pen->Color=clBlack;
    Canvas->Brush->Style=bsSolid;
    Canvas->Brush->Color=clBlack;
    Canvas->Rectangle(-1,-1,Form1->ClientWidth+1,Form1->ClientHeight+1);
    FormXY(XY);    
    Canvas->Pen->Color=clWhite;
    Canvas->Brush->Style=bsClear;
    model.Show(XY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.z-=pl;
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.z+=pl;
    t=point;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
    pl*=10;    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    pl/=10;
    if(pl==0)
    {
        pl=1;
    }
}
//---------------------------------------------------------------------------

