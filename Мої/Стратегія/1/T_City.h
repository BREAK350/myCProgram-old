//---------------------------------------------------------------------------
#ifndef T_CityH
#define T_CityH
#include "T_Commander.h"
class T_Map;
//---------------------------------------------------------------------------
class T_City   // генерал, місто
{
    private:
        T_Map *LinkMap; // посилання на загальну карту
        friend T_Map;
        friend T_Commander;
    protected:
        char *Name; // назва міста
        TPoint XY; // розташування міста
        int Nation; // нація (різні нації - вороги, однакові - союзники)
        T_Resource Resource; // ресурси
        T_Resource Income; // прибуток(додається до Resource)
        T_Character Character; // місто має захист і атаку з радіусом
        int KCommander;      // кількість командирів
        T_Commander **Commanders; // масив командирів (кожен командир має націю, як і у його міста,
                                 // однак, командир може поміняти націю і піти в інше місто)
        int CurrentCommander;
        void UpIncome(_Resource_,float,float);
        void UpResource();
    public:
        T_City();
        T_City(const T_City &);
        T_City(T_Map *,char *,TPoint,int,T_Resource,T_Resource,T_Character,int,T_Commander **);
        ~T_City();
        int GetNation(){return Nation;}
        T_Commander* GetNextCommander();
        T_Commander* GetCommander(int);
        void UpIncome(_Resource_,int);
        void CreateNewCommander(char *);
};
//---------------------------------------------------------------------------
#include "T_Map.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
