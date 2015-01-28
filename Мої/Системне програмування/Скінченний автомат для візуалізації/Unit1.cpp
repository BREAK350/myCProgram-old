//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TbVisualElementCircleName vec[20];
TbVisualElementArrowName vea[20];
int Blue=0,add=1,nc=12,na=16,MinDistance=100;
TbVisualElementBase *Element[6];
TbVector2d PointCenter[20];

Graphics::TBitmap *bmp=new Graphics::TBitmap;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    randomize();
    bmp->Width=700;
    bmp->Height=500;

    LocatePointOnCircle(TbVector2d(200,200),nc/2,PointCenter,MinDistance);
    LocatePointOnCircle(TbVector2d(600,200),nc-nc/2,&PointCenter[nc/2],MinDistance);
    for(int i=0;i<nc;i++)
    {
        vec[i].Center=PointCenter[i];
        vec[i].CenterFuture.Init(500,200);

        vec[i].Radius=10;
        vec[i].Speed=0;

        vec[i].Name=IntToStr(i);
    }

    for(int i=0;i<na-1;i++)
    {
        vea[i].First=&vec[i];
        vea[i].Second=&vec[i+1];

        vea[i].Name=(char)(random(3)+'a');
    }
    vea[na-1].First=&vec[na-1];
    vea[na-1].Second=&vec[0];
    vea[na-1].Name=(char)(random(3)+'a');

    vea[5].First=&vec[5];
    vea[5].Second=&vec[0];
    vea[11].First=&vec[11];
    vea[11].Second=&vec[6];
    vea[12].First=&vec[1];
    vea[12].Second=&vec[4];
    vea[13].First=&vec[9];
    vea[13].Second=&vec[7];
    vea[14].First=&vec[3];
    vea[14].Second=&vec[8];
    vea[15].First=&vec[8];
    vea[15].Second=&vec[3];

    for(int i=0;i<na;i++)
    {
        vea[i].Length=0;
        vea[i].Speed=0;
    }

    LocatePointOnCircle(TbVector2d(400,200),nc,PointCenter,MinDistance);
    for(int i=0;i<nc;i++)
    {
        vec[i].CenterFuture=PointCenter[i];
    }

    Show();
    myDraw();
}
//---------------------------------------------------------------------------
void TForm1::myDraw()
{
    bmp->Canvas->Pen->Color=clWhite;
    bmp->Canvas->Rectangle(0,0,bmp->Width,bmp->Height);

    bmp->Canvas->Pen->Color=clBlue;
    for(int i=0;i<na;i++)
    {
        vea[i].Draw(bmp->Canvas);
    }

    bmp->Canvas->Pen->Color=clRed;
    for(int i=0;i<nc;i++)
    {
        vec[i].Draw(bmp->Canvas);
    }

    /*for(int i=0;i<nc;i++)
    {
        if(!vec[i].isMove())
        {
            vec[i].CenterFuture.Init(random(ClientWidth),random(ClientHeight));
        }
    }*/

    Canvas->Draw(0,0,bmp);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    //myDraw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if(vea[0].Speed>0)
    {
        for(int i=0;i<na;i++)
        {
            vea[i].Speed=0;
        }
    }
    else
    {
        for(int i=0;i<na;i++)
        {
            vea[i].Speed=6;
        }
    }

    TbList2 <TbVisualElementBase*> l;
    for(int i=0;i<na;i++)
    {
        l.Add(&vea[i]);
    }
    for(int i=0;i<nc;i++)
    {
        l.Add(&vec[i]);
    }
    //DrawElementFromList(Canvas,l,10,ClientRect);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(vec[0].Speed>0)
    {
        for(int i=0;i<nc;i++)
        {
            vec[i].Speed=0;
        }
    }
    else
    {
        for(int i=0;i<nc;i++)
        {
            vec[i].Speed=3;
        }
    }
}
//---------------------------------------------------------------------------
