//---------------------------------------------------------------------------
#ifndef T_CommanderH
#define T_CommanderH
#include "T_Warrior.h"
//---------------------------------------------------------------------------
class T_City;
//---------------------------------------------------------------------------
enum _Resource_{_Gold_,_Stone_,_Tree_,_Coal_,_Iron_};
//---------------------------------------------------------------------------
struct T_Resource // ресурси
{
    float Gold, // золото
          Stone,// камінь
          Tree, // дерево
          Coal, // вугілля
          Iron; // залізо
    T_Resource();
    T_Resource(float,float,float,float,float);
};
//---------------------------------------------------------------------------
struct T_Price
{
    T_Resource Commander,
               City;
}Price;
//---------------------------------------------------------------------------
class T_Commander:public T_Warrior // командир
{
    private:
        T_City *LinkCity;
        friend T_City;
        friend T_Warrior;
    protected:
        int Nation;          // нація (різні нації - вороги, однакові - союзники)
        T_Resource Resource; // ресурси командира
        int KWarrior;        // кількість воїнів
        T_Warrior **Warriors; // масив воїнів
    public:
        T_Commander();
        T_Commander(const T_Commander &);
        T_Commander(char *,TPoint,T_Character,int,T_Resource,int,T_Warrior **);
        ~T_Commander();
        T_Commander& operator = (const T_Commander &);
        void AddCity(char *);
        bool GetActive(){return Active;}
};
//---------------------------------------------------------------------------
#include "T_City.h"
//---------------------------------------------------------------------------
T_Resource operator + (T_Resource l,T_Resource r);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
