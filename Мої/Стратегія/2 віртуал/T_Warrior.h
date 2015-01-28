//---------------------------------------------------------------------------
#ifndef T_WarriorH
#define T_WarriorH
#include <vcl.h>
#include "T_Info.h"
//---------------------------------------------------------------------------
class T_Commander;
//---------------------------------------------------------------------------
enum EVENT
{
    DONOTHING,
    MOVETO,
    ATTACK,
    GO_CITY,
    GO_COMMANDER,
    GO_WARRIOR,
    GO_BACK,
    NEXT_DAY,
    SAVE_GAME,
    LOAD_GAME,
    DESTROY_CITY
};
//---------------------------------------------------------------------------
struct T_Character   // характеристика воїна
{
    float Life,      // життя
          Attack,    // атака
          Protection,// захист
          Radius,    // радіус дії атаки
          Speed;     // швидкість пересування
    T_Character();
    T_Character(float,float,float,float,float);
};
//---------------------------------------------------------------------------
struct T_Data_Character
{
    T_Character Warrior,   // воїн
                Doctor,    // лікар
                Commander, // командир
                Catapult,  // катапульта
                Archer,    // лучник
                Cavalry,   // кавалерія (кіннота)
                City;      // місто
};
//---------------------------------------------------------------------------
class T_Doctor;
//---------------------------------------------------------------------------
class T_Warrior      // воїн
{
    protected:
        friend T_Doctor;
        friend T_Commander;
        T_Commander *LinkCommander;
        char *Name;  // ім'я воїна
        TPoint XY;   // розташування воїна
        T_Character Character; // характеристика воїна
        bool Active; // true- якщо не ходив, false- якщо ходив
    public:
        T_Warrior();
        T_Warrior(const T_Warrior &);
        T_Warrior(char *,TPoint,T_Character);
        ~T_Warrior();
        int GetNation();
        virtual bool isMove(TPoint);
        virtual void Move(TPoint);
        virtual bool isAttack(T_Warrior *);
        virtual void Attack(T_Warrior *);
        T_Warrior& operator = (const T_Warrior &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class T_Doctor:public T_Warrior
{
    public:
        T_Doctor():T_Warrior(){}
        T_Doctor(const T_Doctor &d):T_Warrior(d){}
        T_Doctor(char *n,TPoint p,T_Character c):T_Warrior(n,p,c){}
        //virtual bool isMove(TPoint p){return T_Warrior::isMove(p);}
        //virtual void Move(TPoint p){T_Warrior::Move(p);}
        virtual bool isAttack(T_Warrior *);
        virtual void Attack(T_Warrior *);
};
//---------------------------------------------------------------------------
#include "T_Commander.h"
//---------------------------------------------------------------------------
bool operator == (TPoint l,TPoint r){return (l.x==r.x && l.y==r.y);}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
