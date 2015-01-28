//---------------------------------------------------------------------------
#ifndef T_WarriorH
#define T_WarriorH
#include <vcl.h>
//---------------------------------------------------------------------------
class T_Commander;
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
class T_Warrior      // воїн
{
    private:
        T_Commander *LinkCommander;
    protected:
        char *Name;  // ім'я воїна
        TPoint XY;   // розташування воїна
        T_Character Character; // характеристика воїна
        bool Active; // true- якщо не ходив, false- якщо ходив
        bool isMove(TPoint);
        bool isAttack(T_Warrior *);
    public:
        T_Warrior();
        T_Warrior(const T_Warrior &);
        T_Warrior(char *,TPoint,T_Character);
        ~T_Warrior();
        void Move(TPoint);
        void Attack(T_Warrior *);
        T_Warrior& operator = (const T_Warrior &);
};
//---------------------------------------------------------------------------
#include "T_Commander.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
