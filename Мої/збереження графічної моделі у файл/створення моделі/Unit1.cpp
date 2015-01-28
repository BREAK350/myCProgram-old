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
TForm1  *Form1;
Point2D XY,
        cur,
        point;
TModel  model;
int     I,J,N;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    XY.x=0;
    XY.y=Form1->Height-Panel1->Height-39;
    Canvas->Pen->Color=clWhite;
    Canvas->Pen->Width=1;
    Canvas->Brush->Style=bsClear;
    model.n_point=MAXN;
    model.point=(Point2D*)malloc(model.n_point*sizeof(Point2D));
    model.CreateGraf();
    model.n_point=N=I=J=0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    cur.x=X+XY.x;
    cur.y=XY.y-Y;
    Label1->Caption="Курсор("+FloatToStr(cur.x)+";"+FloatToStr(cur.y)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
    XY.y=Form1->Height-Panel1->Height-39;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    point=cur;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+")";
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
    }
    Label3->Caption="Всього точок "+IntToStr(model.n_point);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    Canvas->Ellipse(model.point[I].x+XY.x-r,XY.y-model.point[I].y+r,model.point[I].x+XY.x+r,XY.y-model.point[I].y-r);
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
    Canvas->Ellipse(model.point[I].x+XY.x-r,XY.y-model.point[I].y+r,model.point[I].x+XY.x+r,XY.y-model.point[I].y-r);
    Label4->Caption="("+FloatToStr(model.point[I].x)+";"+FloatToStr(model.point[I].y)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    Canvas->Ellipse(model.point[I].x+XY.x-r,XY.y-model.point[I].y+r,model.point[I].x+XY.x+r,XY.y-model.point[I].y-r);
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
    Label4->Caption="("+FloatToStr(model.point[I].x)+";"+FloatToStr(model.point[I].y)+")";
    Canvas->Pen->Color=clLime;
    Canvas->Ellipse(model.point[I].x+XY.x-r,XY.y-model.point[I].y+r,model.point[I].x+XY.x+r,XY.y-model.point[I].y-r);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    Canvas->Ellipse(model.point[J].x+XY.x-r,XY.y-model.point[J].y+r,model.point[J].x+XY.x+r,XY.y-model.point[J].y-r);
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
    Canvas->Ellipse(model.point[J].x+XY.x-r,XY.y-model.point[J].y+r,model.point[J].x+XY.x+r,XY.y-model.point[J].y-r);
    Label6->Caption="("+FloatToStr(model.point[J].x)+";"+FloatToStr(model.point[J].y)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    Canvas->Pen->Color=clBlack;
    Canvas->Ellipse(model.point[J].x+XY.x-r,XY.y-model.point[J].y+r,model.point[J].x+XY.x+r,XY.y-model.point[J].y-r);
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
    Canvas->Ellipse(model.point[J].x+XY.x-r,XY.y-model.point[J].y+r,model.point[J].x+XY.x+r,XY.y-model.point[J].y-r);
    Label6->Caption="("+FloatToStr(model.point[J].x)+";"+FloatToStr(model.point[J].y)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    point.y++;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    point.y--;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+")";    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    point.x++;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+")";    
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    point.x--;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+")";    
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
