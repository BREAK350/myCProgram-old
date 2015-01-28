//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
//---------------------------------------------------------------------------
const int MAX_DIFFERENT_WARRIOR=16; // максимальна кількість різних воїнів в армії
const int MAX_DIFFERENT_ARMY=8; // максимальна кількість різних армій в місті
const int MAX_DIFFERENT_ENTRANCE=8; // максимальна кількість напряму з'єднаних міст
const int MAX_DIFFERENT_CITY=64; // максимальна кількість міст
const int MAX_DIFFERENT_NATIONALITY=8; // максимальна кількість національностей
//---------------------------------------------------------------------------
char *WarriorName[]={"Солдат","Лучник","Кіннота","Артилерія"};
//---------------------------------------------------------------------------
struct T_Warrior
{
    int idWN; // індекс в масиві WarriorName
    int Amount; // кількість однотипних воїнів
    float Efficiency; // ефективність в бою (серед двох різних воїнів перемагає той, у кого ефективність більша, проігравший гине, а той хто виграв - лікується )
    T_Warrior();
};
/*
    воїн гине, якщо його ефективність стане менше 75% від початкової. Цей показник можна зменшити,
    якщо розвивати медицину в місті. Тоді показник можна зменшити до 30%
*/
//---------------------------------------------------------------------------
struct T_Army
{
    int AmountWarrior;
    T_Warrior Warrior[MAX_DIFFERENT_WARRIOR];
    T_Army() { AmountWarrior=0; }
};
//---------------------------------------------------------------------------
struct T_City
{
    int x,y; // координати міста
    int Nationality; // національність міста
    int Population; // населення
    int Gold; // золото
    int GoldMining; // видобуток золота за 1 хід (залежить від населення)
    int AmountArmy;
    T_Army Army[MAX_DIFFERENT_ARMY];
    int LevelOfMedicine;
    int AmountEntrance; // кількість входів у місто (мінімально 2, максимально MAX_DIFFERENT_ENTRANCE)
    T_City *CityLink[MAX_DIFFERENT_ENTRANCE]; // напряму з'єднані міста
    T_City();
};
//---------------------------------------------------------------------------
class T_Game
{
    private:
    public:
        T_City City[MAX_DIFFERENT_CITY];
        int AmountCity;
        int Union[MAX_DIFFERENT_NATIONALITY][MAX_DIFFERENT_NATIONALITY]; // матриця союзів
        // i-а(рядок) національність в союзі з j-ю(стовпчик) дає 1 інакше 0
    public:
        int isCityFriendly(const T_City *City1,const T_City *City2); // чи дружні два міста
        int MovingArmy(T_City *CityFrom,const int &idArmy,T_City *CityTo); // переміщення армії з індексом idArmy в місті CityFrom в місто CityTo
        int isUnionWarrior(const T_Warrior &Warrior1,const T_Warrior &Warrior2); // чи можна об'єднати два загони воїнів
        int AddCity(const int &nationality,const int &_x,const int &_y); // додавання міста
        int UnionWarrior(T_Warrior &Warrior1,T_Warrior &Warrior2); // об'єднання двох загонів (спільний загін буде Warrior1)
        int isFreeEntrance(const T_City *City);
        int UnionCity(T_City *City1,T_City *City2);
        int UnionCity(const int &City1,const int &City2);
        //-------------------------------------------------------------------
        void DrawCity(TCanvas *Canvas);
        void DrawCityLink(TCanvas *Canvas);

};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
