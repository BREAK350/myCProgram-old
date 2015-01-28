//---------------------------------------------------------------------------
#ifndef T_MapH
#define T_MapH
#include "T_City.h"
/*� ������������� ���������� �����*/
//---------------------------------------------------------------------------
class T_Map             // �������� (���) ����� ���
{
    protected:
        friend T_Commander;
        char *Name; // ����� �����
        int AllNation; // ������ �����
        int KCity;  // ������� ���
        T_City **Cities; // ����� ���
        int CurrentNation; // ������� ����� (��� � ����� ��� ������)
        int CurrentCity; // ������� ����
        void NextNation();
        void NextDay(); // ��������� ���� (����)
        T_City* SearchCity(TPoint);
        T_Commander* SearchCommander(TPoint p);
    public:
        T_Map();
        T_Map(const T_Map &);
        //T_Map(char *,int,);
        ~T_Map();
        T_City* GetNextCity();
        T_City* GetCity(int);
        void Draw(TCanvas *,float,TPoint);
        void Init();
    protected:
        T_City *cCity,*EnemyCity;
        T_Commander *cCommander,*EnemyCommander;
        T_Warrior *cWarrior;
    public:
        bool Control(TPoint,EVENT,int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
