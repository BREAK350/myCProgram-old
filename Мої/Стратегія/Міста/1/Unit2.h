//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include <vcl.h>
//---------------------------------------------------------------------------
const int MAX_DIFFERENT_WARRIOR=16; // ����������� ������� ����� ���� � ��쳿
const int MAX_DIFFERENT_ARMY=8; // ����������� ������� ����� ���� � ���
const int MAX_DIFFERENT_ENTRANCE=8; // ����������� ������� ������� �'������� ���
const int MAX_DIFFERENT_CITY=64; // ����������� ������� ���
const int MAX_DIFFERENT_NATIONALITY=8; // ����������� ������� ���������������
//---------------------------------------------------------------------------
char *WarriorName[]={"������","������","ʳ�����","��������"};
//---------------------------------------------------------------------------
struct T_Warrior
{
    int idWN; // ������ � ����� WarriorName
    int Amount; // ������� ���������� ����
    float Efficiency; // ����������� � ��� (����� ���� ����� ���� �������� ���, � ���� ����������� �����, ���������� ����, � ��� ��� ������ - ������� )
    T_Warrior();
};
/*
    ��� ����, ���� ���� ����������� ����� ����� 75% �� ���������. ��� �������� ����� ��������,
    ���� ��������� �������� � ���. ��� �������� ����� �������� �� 30%
*/
//---------------------------------------------------------------------------
struct T_Army
{
    int AmountWarrior;
    T_Warrior Warrior[MAX_DIFFERENT_WARRIOR];
    T_Army() { AmountWarrior=0; }
};
//---------------------------------------------------------------------------
struct T_City
{
    int x,y; // ���������� ����
    int Nationality; // ������������� ����
    int Population; // ���������
    int Gold; // ������
    int GoldMining; // ��������� ������ �� 1 ��� (�������� �� ���������)
    int AmountArmy;
    T_Army Army[MAX_DIFFERENT_ARMY];
    int LevelOfMedicine;
    int AmountEntrance; // ������� ����� � ���� (�������� 2, ����������� MAX_DIFFERENT_ENTRANCE)
    T_City *CityLink[MAX_DIFFERENT_ENTRANCE]; // ������� �'����� ����
    T_City();
};
//---------------------------------------------------------------------------
class T_Game
{
    private:
    public:
        T_City City[MAX_DIFFERENT_CITY];
        int AmountCity;
        int Union[MAX_DIFFERENT_NATIONALITY][MAX_DIFFERENT_NATIONALITY]; // ������� �����
        // i-�(�����) ������������� � ���� � j-�(��������) �� 1 ������ 0
    public:
        int isCityFriendly(const T_City *City1,const T_City *City2); // �� ����� ��� ����
        int MovingArmy(T_City *CityFrom,const int &idArmy,T_City *CityTo); // ���������� ��쳿 � �������� idArmy � ��� CityFrom � ���� CityTo
        int isUnionWarrior(const T_Warrior &Warrior1,const T_Warrior &Warrior2); // �� ����� ��'������ ��� ������ ����
        int AddCity(const int &nationality,const int &_x,const int &_y); // ��������� ����
        int UnionWarrior(T_Warrior &Warrior1,T_Warrior &Warrior2); // ��'������� ���� ������ (������� ���� ���� Warrior1)
        int isFreeEntrance(const T_City *City);
        int UnionCity(T_City *City1,T_City *City2);
        int UnionCity(const int &City1,const int &City2);
        //-------------------------------------------------------------------
        void DrawCity(TCanvas *Canvas);
        void DrawCityLink(TCanvas *Canvas);

};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
