//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    int i;
    //Wave[16].h=0;
    Wave[16].dh=3;
}
//---------------------------------------------------------------------------
void TForm1::Draw(TPoint c,float s)
{
    int i;
    Canvas->MoveTo(c.x,ClientHeight-(Wave[0].h*s+c.y));
    for(i=1;i<Size;i++)
    {
        Canvas->LineTo(s*i+c.x,ClientHeight-(Wave[i].h*s+c.y));
    }
}
//---------------------------------------------------------------------------
void TForm1::Smoothing()
{
    int i=0,j;
    float h;
    while(i<Size)
    {
        h=0;
        while(i<Size && h<fabs(Wave[i].h)+e)
        {
            h=fabs(Wave[i].h);
            i++;
        }
        i--;
        if(i<Size)
        {
            // LEFT
            j=i-1;
            while(j>=0 && h>fabs(Wave[j].h))
            {
                Wave[j].dh=Wave[j+1].dh;
                h=fabs(Wave[j].h);
                j--;
            }
            // RIGHT
            j=i+1;
            h=fabs(Wave[i].h);
            while(j<Size && h>fabs(Wave[j].h))
            {
                Wave[j].dh=Wave[j-1].dh;
                h=fabs(Wave[j].h);
                j++;
            }
            i=j;
        }
    }
    for(i=0;i<Size;i++)
    {
        Smoothing(i);
    }
}
//---------------------------------------------------------------------------
void TForm1::Smoothing(int i)
{
    if(Wave[i].h>e)
    {
        Wave[i].dh-=sm;
    }
    else
    {
        if(Wave[i].h<-e)
        {
            Wave[i].dh+=sm;
        }
    }
    if(Wave[i].h*(Wave[i].h+Wave[i].dh)<0)
    {
        Wave[i].dh*=loss;
    }
    Wave[i].h+=Wave[i].dh;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    Canvas->Rectangle(-1,-1,1000,1000);
    Smoothing2();
    Draw(TPoint(ClientWidth/3.0,ClientHeight/2.0),1);
}
//---------------------------------------------------------------------------
void TForm1::Smoothing2(int i) // i>0 && i<Size-1
{
    if(Wave[i].h>e)
    {
        if(Wave[i].h<Wave[i-1].h)
        {
            if(Wave[i].h<Wave[i+1].h)
            {
                Wave[i].dh+=sm;
            }
            else
            {
                if(Wave[i-1].h<Wave[i+1].h)
                {
                    Wave[i].dh+=sm;
                }
                else
                {
                    Wave[i].dh-=sm;
                }
            }
        }
        else
        {
            if(Wave[i].h<Wave[i+1].h)
            {
                if(Wave[i-1].h<Wave[i+1].h)
                {
                    Wave[i].dh+=sm;
                }
                else
                {
                    Wave[i].dh-=sm;
                }
            }
            else
            {
                Wave[i].dh-=sm;
            }
        }
    }


    if(Wave[i].h<-e)
    {
        if(Wave[i].h<Wave[i-1].h)
        {
            if(Wave[i].h<Wave[i+1].h)
            {
                Wave[i].dh+=sm;
            }
            else
            {
                if(Wave[i-1].h<Wave[i+1].h)
                {
                    Wave[i].dh+=sm;
                }
                else
                {
                    Wave[i].dh-=sm;
                }
            }
        }
        else
        {
            if(Wave[i].h<Wave[i+1].h)
            {
                if(Wave[i-1].h<Wave[i+1].h)
                {
                    Wave[i].dh+=sm;
                }
                else
                {
                    Wave[i].dh-=sm;
                }
            }
            else
            {
                Wave[i].dh-=sm;
            }
        }
    }

    if(Wave[i].h*(Wave[i].h+Wave[i].dh)<0)
    {
        Wave[i].dh*=loss;
    }
    Wave[i].h+=Wave[i].dh;
}
//---------------------------------------------------------------------------
void TForm1::Smoothing2()
{
    int i=0,j;
    float h;
    while(i<Size)
    {
        h=0;
        while(i<Size && h<fabs(Wave[i].h)+e)
        {
            h=fabs(Wave[i].h);
            i++;
        }
        i--;
        if(i<Size)
        {
            // LEFT
            j=i-1;
            while(j>=0 && h>fabs(Wave[j].h))
            {
                Wave[j].dh=Wave[j+1].dh;
                h=fabs(Wave[j].h);
                j--;
            }
            // RIGHT
            j=i+1;
            h=fabs(Wave[i].h);
            while(j<Size && h>fabs(Wave[j].h))
            {
                Wave[j].dh=Wave[j-1].dh;
                h=fabs(Wave[j].h);
                j++;
            }
            i=j;
        }
    }
    for(i=1;i<Size-1;i++)
    {
        Smoothing2(i);
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

