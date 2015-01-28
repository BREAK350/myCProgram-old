//---------------------------------------------------------------------------
#ifndef T_WarriorH
#define T_WarriorH
#include <vcl.h>
//---------------------------------------------------------------------------
class T_Commander;
//---------------------------------------------------------------------------
struct T_Character   // �������������� ����
{
    float Life,      // �����
          Attack,    // �����
          Protection,// ������
          Radius,    // ����� 䳿 �����
          Speed;     // �������� �����������
    T_Character();
    T_Character(float,float,float,float,float);
};
//---------------------------------------------------------------------------
class T_Warrior      // ���
{
    private:
        T_Commander *LinkCommander;
    protected:
        char *Name;  // ��'� ����
        TPoint XY;   // ������������ ����
        T_Character Character; // �������������� ����
        bool Active; // true- ���� �� �����, false- ���� �����
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
