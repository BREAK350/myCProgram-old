//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "TbOrientation.h"
#include <stdio.h>
//---------------------------------------------------------------------------
struct T_CityInf3
{
    int CityNumber,
        PlayerNumber;
    TPoint Location;
    int CountArmy[3];
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
struct T_Player
{
    int Money,
        AddMoney;
    double *Life; // CountTypeArmy
    double **Attack, // CountTypeArmy*CountTypeArmy
           **Protection; // CountTypeArmy*CountTypeArmy

    T_Player() { Money=0; AddMoney=0; Life=NULL; Attack=NULL; Protection=NULL; }

    void LoadFromFile(FILE *File,const int &CountTypeArmy);
    void SaveToFile(FILE *File,const int &CountTypeArmy);
    void Delete(const int &CountTypeArmy);
};
//---------------------------------------------------------------------------
struct T_City
{
    TPoint Location;
    int PlayerNumber;
    int *CountArmy; // CountTypeArmy
    int *AddArmy; // CountTypeArmy

    T_City() { PlayerNumber=-1; CountArmy=NULL; AddArmy=NULL; }

    void LoadFromFile(FILE *File,const int &CountTypeArmy);
    void SaveToFile(FILE *File,const int &CountTypeArmy);
    void Delete();
};
//---------------------------------------------------------------------------
class T_Game
{
    private:
        int CountPlayer,
            CurrPlayer,
            CountTypeArmy,
            CountCity,
            CurrCity;
        T_Player *Player; // CountPlayer
        int *CostArmy; // CountTypeArmy
        T_City *City; // CountCity
        char **CityLink; // CountCity*CountCity
    private:
        void LoadFromFile(FILE *File);
        void SaveToFile(FILE *File);
        void Delete();
    public:
        T_Game();
        ~T_Game() { Delete(); }
        int BuyArmy(const int &TypeArmy,const int &Count);
        int MovingArmy(int *CountArmy,const int &CityTo);  
        int ChooseCity(const TPoint &Location);
        int Attack(int *CountArmy,const int &CityTo);
        int AccessCity()const;
        T_CityInf3 GetCityInf3()const;
        void Draw(TbOrientation &Or)const;
        int isAttack()const;
        void Init1();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
