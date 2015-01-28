//---------------------------------------------------------------------------
#ifndef T_CityH
#define T_CityH
#include "T_Commander.h"
class T_Map;
//---------------------------------------------------------------------------
class T_City   // �������, ����
{
    private:
        T_Map *LinkMap; // ��������� �� �������� �����
        friend T_Map;
        friend T_Commander;
    protected:
        char *Name; // ����� ����
        TPoint XY; // ������������ ����
        int Nation; // ����� (��� ����� - ������, ������� - ��������)
        T_Resource Resource; // �������
        T_Resource Income; // ��������(�������� �� Resource)
        T_Character Character; // ���� �� ������ � ����� � �������
        int KCommander;      // ������� ���������
        T_Commander **Commanders; // ����� ��������� (����� �������� �� �����, �� � � ���� ����,
                                 // �����, �������� ���� ������� ����� � ��� � ���� ����)
        int CurrentCommander;
        void UpIncome(_Resource_,float,float);
        void UpResource();
    public:
        T_City();
        T_City(const T_City &);
        T_City(T_Map *,char *,TPoint,int,T_Resource,T_Resource,T_Character,int,T_Commander **);
        ~T_City();
        int GetNation(){return Nation;}
        T_Commander* GetNextCommander();
        T_Commander* GetCommander(int);
        void UpIncome(_Resource_,int);
        void CreateNewCommander(char *);
};
//---------------------------------------------------------------------------
#include "T_Map.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
