//---------------------------------------------------------------------------
#ifndef T_WarriorH
#define T_WarriorH
#include "T_Any_Warrior.h"
#include <math.h>
//---------------------------------------------------------------------------
class T_Warrior:public T_Any_Warrior // воїн
{
    public:
        T_Warrior():T_Any_Warrior(){}
        T_Warrior(const T_Warrior &w):T_Any_Warrior(w){}
        T_Warrior(char *name,TPoint p,T_Character c,T_Poligon &pict):T_Any_Warrior(name,p,c,pict){}
        ~T_Warrior();
        T_Warrior& operator = (const T_Any_Warrior &);
        //--------------------=Ігровий процес=-------------------------------
        virtual bool isMove(TPoint);
        virtual void Move(TPoint);
        virtual bool isAttack(T_Any_Warrior *);
        virtual void Attack(T_Any_Warrior *,T_Character);
        virtual float GetAttack(int);
        virtual float GetProtcion(int);
};
//---------------------------------------------------------------------------
typedef T_Warrior T_Cavalry,  // вершник
                  T_Catapult, // катапульта
                  T_Archer;   // лучник
//---------------------------------------------------------------------------
class T_Doctor:public T_Any_Warrior
{
    public:
        T_Doctor():T_Any_Warrior(){}
        T_Doctor(const T_Warrior &w):T_Any_Warrior(w){}
        T_Doctor(char *name,TPoint p,T_Character c,T_Poligon &pict):T_Any_Warrior(name,p,c,pict){}
        ~T_Doctor();
        T_Doctor& operator = (const T_Any_Warrior &);
        //--------------------=Ігровий процес=-------------------------------
        virtual bool isMove(TPoint);
        virtual void Move(TPoint);
        virtual bool isAttack(T_Any_Warrior *);
        virtual void Attack(T_Any_Warrior *,T_Character);
        virtual float GetAttack(int);
        virtual float GetProtcion(int);
};
//---------------------------------------------------------------------------
#endif
