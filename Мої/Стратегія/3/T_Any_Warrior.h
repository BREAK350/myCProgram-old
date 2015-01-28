//---------------------------------------------------------------------------
#ifndef T_Any_WarriorH
#define T_Any_WarriorH
#include <vcl.h>
#include "T_Poligon.h"
#define ACCIDENT 20
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
struct T_Attack
{
    float Power,
          Radius;
};
//---------------------------------------------------------------------------
typedef T_Attack T_Protection;
//---------------------------------------------------------------------------
class T_Any_Warrior
{
    public:
        char *Name;  // ім'я воїна
        TPoint XY;   // розташування воїна
        T_Character Character; // характеристика воїна
        bool Active; // true- якщо не ходив, false- якщо ходив
        T_Poligon Picture;
    public:
        T_Any_Warrior();
        T_Any_Warrior(const T_Any_Warrior &);
        T_Any_Warrior(char *,TPoint,T_Character,T_Poligon &);
        ~T_Any_Warrior();
        T_Any_Warrior& operator = (const T_Any_Warrior &);
        //--------------------=Ігровий процес=-------------------------------
        virtual bool isMove(TPoint)=0;
        virtual void Move(TPoint)=0;
        virtual bool isAttack(T_Any_Warrior *)=0;
        virtual void Attack(T_Any_Warrior *,T_Character)=0;
        virtual float GetAttack(int)=0;
        virtual float GetProtcion(int)=0;
        void Draw(TCanvas *,TPoint,float);
        bool isLive(){return Character.Life>0;}
        void DoActive(){Active=true;}
};
//---------------------------------------------------------------------------
typedef T_Any_Warrior* pT_Any_Warrior;
//---------------------------------------------------------------------------
#endif
