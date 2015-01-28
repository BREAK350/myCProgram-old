//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "TModel.h"
#include "LoadSave.h"
#include "CreateModel.h"
#include "ShowModel2D.h"
#define MAXN 300
#define r 3
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1   *Form1;
Point3D  XY,
         cur,
         point,t,loc;
TModel   model,mod;
int      I,J,N,pl=1;
location data;
Graphics::TBitmap*   bmp = new Graphics::TBitmap;
int K=300;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    bmp->Height=ClientHeight;
    bmp->Width=ClientWidth;
    XY.x=(Form1->ClientWidth-Panel1->Width-Panel2->Width)/2+Panel1->Width;
    XY.y=Form1->ClientHeight/2;
    XY.z=0;
    loc.x=loc.y=0;
    loc.z=-700;
    Canvas->Pen->Color=clWhite;
    Canvas->Pen->Width=1;
    Canvas->Brush->Style=bsClear;
    model.n_point=MAXN;
    model.scale=1;
    model.point=(Point3D*)malloc(model.n_point*sizeof(Point3D));
    CreateGraf(model);
    model.n_point=N=I=J=0;
    Form1->Show();
    cur.z=0;
    FormXY(XY);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
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
        if(model.point[i].x==point.x && model.point[i].y==point.y && model.point[i].z==point.z)
        {
            break;
        }
    }
    if(i==model.n_point)
    {
        model.point[model.n_point]=point;
        Canvas->Pixels[point.x+XY.x][XY.y-point.y]=clWhite;
        Show_(model,loc,bmp);
        model.n_point++;
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
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.y+=pl;
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.y-=pl;
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.x+=pl;
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    point.x-=pl;
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    t=_3DTo2D(t);
    Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    CreateLine(model,I+1,J+1);
    Canvas->Pen->Color=clWhite;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    FormXY(XY);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button17Click(TObject *Sender)
{
    DeleteLine(model,I+1,J+1);
    Canvas->Pen->Color=clBlack;
    Canvas->Brush->Style=bsSolid;
    Canvas->Brush->Color=clBlack;
    Canvas->Rectangle(-1,-1,Form1->ClientWidth+1,Form1->ClientHeight+1);
    FormXY(XY);    
    Canvas->Pen->Color=clWhite;
    Canvas->Brush->Style=bsClear;
    Show_(model,loc,bmp);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)
{
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    if(t.z>0)
    {
        t=_3DTo2D(t);
        Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    }
    point.z-=pl;
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    if(t.z>0)
    {
        t=_3DTo2D(t);
        Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    }
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    if(t.z>loc.z)
    {
        t=_3DTo2D(t);
        Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clBlack;
    }
    point.z+=pl;
    t=point;
    t.x-=loc.x;
    t.y-=loc.y;
    t.z-=loc.z;
    if(t.z>loc.z)
    {
        t=_3DTo2D(t);
        Canvas->Pixels[t.x+XY.x][XY.y-t.y]=clWhite;
    }
    Label2->Caption="Точка("+FloatToStr(point.x)+";"+FloatToStr(point.y)+";"+FloatToStr(point.z)+")";  
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
    pl*=10;
    Label7->Caption="+/-="+FloatToStr(pl);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    pl/=10;
    if(pl==0)
    {
        pl=1;
    }
    Label7->Caption="+/-="+FloatToStr(pl);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
    ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
    int i;
    OpenDialog1->Filter=".model";
    OpenDialog1->Execute();
    LoadFromFile(mod,OpenDialog1->FileName.c_str());
    //-----------------
    model.n_point=mod.n_point;
    for(i=0;i<mod.n_point;i++)
    {
        model.point[i]=mod.point[i];
    }
    for(i=0;i<sizeof(mod.grf)/sizeof(graf);i++)
    {
        model.grf[i]=mod.grf[i];
    }
    //DeleteModel(mod);
    //-----------------
    BMPClear(bmp);
    mod.scale=1;
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
    SaveDialog1->Execute();
    AnsiString text=SaveDialog1->FileName+".model";
    SaveToFile(model,text.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
    loc.x-=pl;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
    loc.x+=pl;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
    loc.y-=pl;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
    loc.y+=pl;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
    loc.z-=pl;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
    loc.z+=pl;
    BMPClear(bmp);
    Show_(model,loc,bmp);
    Canvas->Draw(0,0,bmp);
    Label5->Caption="Точка обзору("+FloatToStr(loc.x)+";"+FloatToStr(loc.y)+";"+FloatToStr(loc.z)+")";
}
//---------------------------------------------------------------------------

