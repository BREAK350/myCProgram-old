//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Draw2D.h"
#include "CreateDetail.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*BMP=new Graphics::TBitmap;
point2D p[5];
point2D cursor;
float alpha=0;
int n=0,k[2];
int type=1;//1-point,2-line,3-lamana
extern detail det;
TColor cl=clBlack;
detail dt;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    BMP->Width=600;
    BMP->Height=600;
    Form1->Show();
    BMP->Canvas->Pen->Color=clBlue;
    BMP->Canvas->Rectangle(0,0,BMP->Width,BMP->Height);
    Canvas->Draw(10,10,BMP);
    UpDown1->Min=-1;
    UpDown2->Min=-1;
    UpDown3->Min=-1;
    UpDown1->Max=256;
    UpDown2->Max=256;
    UpDown3->Max=256;
    UpDown4->Min=-1;
    UpDown4->Max=360;
    UpDown5->Min=0;
    UpDown5->Max=1000;
}
//---------------------------------------------------------------------------
void draw2D()
{
    BMP->Canvas->Pen->Color=clBlue;
    BMP->Canvas->Rectangle(0,0,BMP->Width,BMP->Height);
    det.DrawDetail(BMP);
    Form1->Canvas->Draw(10,10,BMP);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    BeginToCreateDetail();
    BMP->Canvas->Pen->Color=clBlue;
    BMP->Canvas->Rectangle(0,0,BMP->Width,BMP->Height);
    Canvas->Draw(10,10,BMP);
    Button1->Enabled=false;
    Panel1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    if(X>=10 && X<=BMP->Width+10 && Y>=10 && Y<=BMP->Height+10)
    {
        cursor.InitXY(X-BMP->Width/2-10,BMP->Height/2-Y+10);
        Label1->Caption="Курсор("+IntToStr((int)cursor.x)+";"+IntToStr((int)cursor.y)+")";
        switch(type)
        {
            case 2:
                case 3:if(n>=1)
                       {
                           draw2D();
                           Canvas->Pen->Color=clBlue;
                           Canvas->MoveTo((det.point[k[0]]*det.S).TurnToPoint(det.loc,det.alpha).x+BMP->Width/2+10,10+BMP->Height/2-(det.point[k[0]]*det.S).TurnToPoint(det.loc,det.alpha).y);
                           Canvas->LineTo(X,Y);
                   }break;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    n=0;
    type=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    n=0;
    type=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
    switch(type)
    {
        case 2:k[n]=det.AddNewPoint((cursor*(1/det.S)).TurnToPoint(det.loc,-det.alpha));
               n++;
               Label2->Caption="Всього точок "+IntToStr(det.Npoint);
               if(n==2)
               {
                   n=0;
                   det.AddNewLine(k[0],k[1],cl);
                   Label3->Caption="Всього ліній "+IntToStr(det.Nline);
               }
               break;
        case 3:k[n]=det.AddNewPoint((cursor*(1/det.S)).TurnToPoint(det.loc,-det.alpha));
               n++;
               Label2->Caption="Всього точок "+IntToStr(det.Npoint);
               if(n==2)
               {
                   det.AddNewLine(k[0],k[1],cl);
                   Label3->Caption="Всього ліній "+IntToStr(det.Nline);
                   k[0]=k[1];
                   n=1;
               }
    }
    draw2D();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
    type=3;
    n=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    /*for(int i=0;i<det.Npoint;i++)
    {
        det.point[i].x=det.point[i].x/det.S;
        det.point[i].y=det.point[i].y/det.S;
    }*/
    SaveDialog1->Execute();
    det.SaveToFile((SaveDialog1->FileName+".detail").c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    OpenDialog1->Execute();
    EndToCreateDetail();
    BeginToCreateDetail();
    dt.LoadFromFile(OpenDialog1->FileName.c_str());
    det=dt;
    UpDown5->Position=(int)det.S;
    Edit5->Text=IntToStr(UpDown5->Position);
    draw2D();
    Panel1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
    if(UpDown1->Position>=256)
    {
        UpDown1->Position=0;
    }
    if(UpDown1->Position<=-1)
    {
        UpDown1->Position=255;
    }
    Edit1->Text=IntToStr(UpDown1->Position);
    cl=RGB(UpDown1->Position,UpDown2->Position,UpDown3->Position);
    Panel3->Color=cl;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
    if(UpDown2->Position>=256)
    {
        UpDown2->Position=0;
    }
    if(UpDown2->Position<=-1)
    {
        UpDown2->Position=255;
    }
    Edit2->Text=IntToStr(UpDown2->Position);
    cl=RGB(UpDown1->Position,UpDown2->Position,UpDown3->Position);
    Panel3->Color=cl;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpDown3Click(TObject *Sender, TUDBtnType Button)
{
    if(UpDown3->Position>=256)
    {
        UpDown3->Position=0;
    }
    if(UpDown3->Position<=-1)
    {
        UpDown3->Position=255;
    }
    Edit3->Text=IntToStr(UpDown3->Position);
    cl=RGB(UpDown1->Position,UpDown2->Position,UpDown3->Position);
    Panel3->Color=cl;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown4Click(TObject *Sender, TUDBtnType Button)
{
    if(UpDown4->Position>=360)
    {
        UpDown4->Position=0;
    }
    if(UpDown4->Position<=-1)
    {
        UpDown4->Position=359;
    }
    Edit4->Text=IntToStr(UpDown4->Position);
    det.alpha=UpDown4->Position;
    draw2D();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UpDown5Click(TObject *Sender, TUDBtnType Button)
{
   if(UpDown5->Position==1000)
    {
        UpDown5->Position=1;
    }
    if(UpDown5->Position==0)
    {
        UpDown5->Position=999;
    }
    Edit5->Text=IntToStr(UpDown5->Position);
    det.S=UpDown5->Position;
    draw2D();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
    UpDown4->Position=StrToInt(Edit4->Text);
    if(UpDown4->Position>=360)
    {
        UpDown4->Position=0;
    }
    if(UpDown4->Position<=-1)
    {
        UpDown4->Position=359;
    }
    Edit4->Text=IntToStr(UpDown4->Position);
    det.alpha=UpDown4->Position;
    draw2D();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
    UpDown5->Position=StrToInt(Edit5->Text);
    if(UpDown5->Position==1000)
    {
        UpDown5->Position=1;
    }
    if(UpDown5->Position==0)
    {
        UpDown5->Position=999;
    }
    Edit5->Text=IntToStr(UpDown5->Position);
    det.S=UpDown5->Position;
    draw2D();
}
//---------------------------------------------------------------------------



