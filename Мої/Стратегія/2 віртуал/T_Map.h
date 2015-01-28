//---------------------------------------------------------------------------
#ifndef T_MapH
#define T_MapH
#include "T_City.h"
/*З використанням віртуальних класів*/
//---------------------------------------------------------------------------
class T_Map             // загальна (уся) карта гри
{
    protected:
        friend T_Commander;
        char *Name; // назва карти
        int AllNation; // всього націй
        int KCity;  // кількість міст
        T_City **Cities; // масив міст
        int CurrentNation; // поточна нація (яка в даний час ходить)
        int CurrentCity; // поточне місто
        void NextNation();
        void NextDay(); // наступний крок (день)
        T_City* SearchCity(TPoint);
        T_Commander* SearchCommander(TPoint p);
    public:
        T_Map();
        T_Map(const T_Map &);
        //T_Map(char *,int,);
        ~T_Map();
        T_City* GetNextCity();
        T_City* GetCity(int);
        void Draw(TCanvas *,float,TPoint);
        void Init();
    protected:
        T_City *cCity,*EnemyCity;
        T_Commander *cCommander,*EnemyCommander;
        T_Warrior *cWarrior;
    public:
        bool Control(TPoint,EVENT,int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
