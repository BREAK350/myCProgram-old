//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TbOrientation.h"
#include "TbList2.h"
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
struct TDrop
{
    int Radius;
    TbVector2d Location;
    void Draw(TbOrientation &Or)
    {
        Or.Circle(Location,Radius);
    }
};
//---------------------------------------------------------------------------
struct TObj
{
    TbVector2d Location,Speed;
    int Width,Height;
    void Draw(TbOrientation &Or)
    {
        Or.Rectangle(Location.X-Width,Location.Y-Height,Location.X+Width,Location.Y+Height);
    }
    bool isHitting(const TDrop &Drop) // чи крапля попала в об'єкт
    {
        return fabs(Location.X-Drop.Location.X)<=Width &&
               fabs(Location.Y-Drop.Location.Y)<=Height;
    }
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    TLabel *Label1;
    void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TbOrientation Or;
    TbList2 <TDrop> Drops; // краплі
    TbVector2d g; // сила тяжіння
    TObj Obj,World;
    int CountDropsHitting,Frequency,CurrFrequency,CountDrops;
    void NextPos();
    void NextDrops();
    void NewTest();
    void DrawDrops();
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 