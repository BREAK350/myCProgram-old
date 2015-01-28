//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "T_Vector2d.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
double S=1,G=100;
//---------------------------------------------------------------------------
struct TPlanet
{
    T_Vector2d Place,Speed;
    double Mass;
    void Init(const T_Vector2d &Place,const T_Vector2d &Speed,const double &Mass)
    {
        this->Place=Place;
        this->Speed=Speed;
        this->Mass=Mass;
    }
    void Draw(TCanvas *Canvas)
    {
        Canvas->Ellipse(Place.X-S*Mass,Place.Y-S*Mass,Place.X+S*Mass,Place.Y+S*Mass);
    }
    void Interact(const TPlanet &Planet)
    {
        T_Vector2d r=Planet.Place-Place;
        double F=0;
        if(r.Length()>Mass+Planet.Mass)
        {
            F=G*Planet.Mass/(r.GetSquareLength());
        }
        r.SetLength(F);
        Speed+=r;
    }
    void Move()
    {
        Place+=Speed;
    }
};
//---------------------------------------------------------------------------
TPlanet Planet[90];
int N=90;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
    for(int i=0;i<N-1;i++)
    {
        Planet[i].Init(T_Vector2d(random(500)+100,random(500)+100),T_Vector2d(0,0),random(3)+1);
    }
    Planet[N-1].Init(T_Vector2d(600,400),T_Vector2d(0,0),100);
    Canvas->Brush->Color=clBlue;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            Planet[i].Interact(Planet[j]);
            Planet[j].Interact(Planet[i]);
        }
    }
    Repaint();
    SetViewportOrgEx(Canvas->Handle,Planet[N-1].Place.X+500,Planet[N-1].Place.Y+300,NULL);
    for(int i=0;i<N;i++)
    {
        Planet[i].Place-=Planet[N-1].Place;
        Planet[i].Move();
        Planet[i].Draw(Canvas);
    }
}
//---------------------------------------------------------------------------

