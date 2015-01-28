//---------------------------------------------------------------------------
#ifndef TbUFAdH
#define TbUFAdH
#include <iostream.h>
#include <vcl.h>
#include "TbList2.h"
#include "T_Vector2d.h"
#include "UnitFormAnimation.h"
#define BEGIN  TbVector2d(650,0)
#define CENTER TbVector2d(650,350)
#define LEFT   TbVector2d(375,350)
#define RIGHT  TbVector2d(1025,350)
//---------------------------------------------------------------------------
const int Speed = 5;
const int Radius = 10;
const int Interval = 25;
const int IntervalEndOperation = 1000;
const int MinDistance = 70;
//---------------------------------------------------------------------------
struct TbUFAdState;
//---------------------------------------------------------------------------
struct TbUFAdLink
{
    String Symbols;
    double Distance;
    TbUFAdState *State; // посилання на той стано, до якої проведено дане з'єднання
    TbUFAdLink() { Distance=0; }
    TbUFAdLink(const String &Symbols,TbUFAdState *State); // щоб прямо в конструкторі почав малюватись зв'язок
    bool Draw(TCanvas *Canvas,TbUFAdState *Begin,const TbVector2d &Center);
    void WriteName(TCanvas *Canvas,TbUFAdState *Begin);
};
//---------------------------------------------------------------------------
struct TbUFAdFinalState
{
    TbUFAdState *State; // посилання на стан
    TbUFAdFinalState() {}
    TbUFAdFinalState(TbUFAdState *State);
};
//---------------------------------------------------------------------------
struct TbUFAdState
{
    int Number;
    TbVector2d Location,LocationFuture,Center;
    TbList2 <TbUFAdLink> Links;
    TbUFAdState() {}
    TbUFAdState(const int &Number,const TbVector2d &Location);
    TbUFAdState(const int &Number,const TbVector2d &Location,
        const TbVector2d &LocationFuture);
    TbUFAdState(const int &Number,const TbVector2d &Location,
        const TbVector2d &LocationFuture,const TbVector2d &Center);
    int Draw(TCanvas *Canvas);
    void WriteName(TCanvas *Canvas);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TbUFAd
{
    private:
        TbList2 <TbUFAdState> AllStates; // перший стан є початковим станом
        TbList2 <TbUFAdFinalState> FinalStates;

    public:
        static TbUFAd CreateSimpleAutomaton(const char *Expression,int &Number,TCanvas *Canvas);
        static void LocatePointOnCircle(const TbVector2d &Center,TbList2 <TbUFAdState> &L,
            const double &MinDistance);

        void AddLink(TbList2 <TbUFAdLink> &Links,const String &Symbols,const int &Number);

        TbUFAdState* SearchByName(const int &Number)const;
        void print()const;
        void Draw();
        TCanvas *Canvas;
        TbVector2d Center;
        TbUFAd Create(const char *Expression,const int &iBegin,const int &iEnd,
            TCanvas *Canvas,int &Number)const;
    public:
        TbUFAd(TCanvas *Canvas);
        TbUFAd(const TbUFAd &UFAd);
        TbUFAd(const char *Expression);
        ~TbUFAd();

        TbUFAd& operator = (const TbUFAd &UFAd);

        TbUFAd Iteration(int &Number)const;
        TbUFAd Alternative(const TbUFAd &UFA,int &Number)const;
        TbUFAd Concatenation(const TbUFAd &UFA,int &Number)const;

        void Create(const char *Expression,TCanvas *Canvas,int &Number);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 