//---------------------------------------------------------------------------
#ifndef T_BattleGroundH
#define T_BattleGroundH
#include "T_Warrior.h"
//---------------------------------------------------------------------------
enum Event
{
    CHOOSEMEMBER,
    MOVETO,
    ATTACK
};
//---------------------------------------------------------------------------
struct T_MemberOfFight
{
    T_Any_Warrior *p;
    int Nation;
};
//---------------------------------------------------------------------------
struct T_Members
{
    int NMembers;
    T_Any_Warrior **Members;
    T_Members(int,pT_Any_Warrior *);
    ~T_Members();
};
//---------------------------------------------------------------------------
class T_BattleGround    // ���� �����
{
    protected:
        int NMembers,   // ������� ��� ���� �� ��� �����
            NNation;    // ������� �����
        T_MemberOfFight *Members; // ����� ��� ����
    public:
        T_BattleGround();
        T_BattleGround(int,T_Members *,...);
        T_BattleGround(const T_BattleGround &);
        ~T_BattleGround();
        T_BattleGround& operator = (const T_BattleGround &);
        void Init(int,T_Members *,...);
        //--------------------=������� ������=-------------------------------
    protected:
        int CurrentMember, // �������� ����� ���� � ������
            CurrentNation; // �������� ����� �����
        int SearchMember(TPoint);
        bool Battle(int,int);
    public:
        void Draw(TCanvas *,TPoint,float);
        void NextNation();
        bool ChooseMember(TPoint);
        bool MoveTo(TPoint);
        bool Attack(TPoint);
};
//---------------------------------------------------------------------------
bool operator == (TPoint,TPoint);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
