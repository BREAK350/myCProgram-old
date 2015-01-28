//---------------------------------------------------------------------------
#ifndef T_CommanderH
#define T_CommanderH
#include "T_Warrior.h"
//---------------------------------------------------------------------------
class T_City;
//---------------------------------------------------------------------------
enum _Resource_{_Gold_,_Stone_,_Tree_,_Coal_,_Iron_};
//---------------------------------------------------------------------------
struct T_Resource // �������
{
    float Gold, // ������
          Stone,// �����
          Tree, // ������
          Coal, // ������
          Iron; // �����
    T_Resource();
    T_Resource(float,float,float,float,float);
};
//---------------------------------------------------------------------------
struct T_Data_Resource
{
    T_Resource Warrior,   // ���
               Doctor,    // ����
               Commander, // ��������
               Catapult,  // ����������
               Archer,    // ������
               Cavalry,   // �������� (������)
               City;      // ����
};
//---------------------------------------------------------------------------
struct T_Data
{
    T_Data_Character Character;
    T_Data_Resource  Resource;
};
//---------------------------------------------------------------------------
class T_Commander:public T_Warrior // ��������
{
    protected:
        T_City *LinkCity;
        friend T_City;
        friend T_Warrior;
        friend T_Doctor;
        int Nation;          // ����� (��� ����� - ������, ������� - ��������)
        T_Resource Resource; // ������� ���������
        int KWarrior;        // ������� ����
        T_Warrior **Warriors; // ����� ����
        void Draw(TCanvas *,float,TPoint);
    public:
        T_Commander();
        T_Commander(const T_Commander &);
        T_Commander(char *,TPoint,T_Character,int,T_Resource,int,T_Warrior **);
        ~T_Commander();
        T_Commander& operator = (const T_Commander &);
        void AddCity(char *);
        bool GetActive(){return Active;}
        bool isAttackCity(T_City *);
        void AttackCity(T_City *);
        virtual void Attack(T_Warrior *){}
        T_Warrior* SearchWarrior(TPoint);
        bool isInCity();
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
