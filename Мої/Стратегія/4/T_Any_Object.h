//---------------------------------------------------------------------------
#ifndef T_Any_ObjectH
#define T_Any_ObjectH
#include "T_Poligon.h"
#define no false
#define yes true
#define MAX_ACTIVE 2
//---------------------------------------------------------------------------
enum
{
    nT_Any_Object,
    nT_StationaryObject,
    nT_Warrior,
    nT_Minery    
};
//---------------------------------------------------------------------------
struct T_Any_Attack
{
    float
        Power,
        Radius;
    T_Any_Attack(){Power=Radius=0;}
    T_Any_Attack(float p,float r){Power=p;Radius=r;}
};
//---------------------------------------------------------------------------
typedef T_Any_Attack T_Any_Protection;
//---------------------------------------------------------------------------
struct T_Attack
{
    T_Any_Attack Fire,
                 Water,
                 Earth,
                 Air;
    T_Attack(){}
    T_Attack(T_Any_Attack f,T_Any_Attack w,T_Any_Attack e,T_Any_Attack a){Fire=f;Water=w;Earth=e;Air=a;}
    T_Attack Accident(int);
};
//---------------------------------------------------------------------------
typedef T_Attack T_Protection;
//---------------------------------------------------------------------------
struct T_Bang
{
    T_Attack Attack;
    T_Point XY;
    T_Bang(){}
    T_Bang(T_Attack a,T_Point xy){Attack=a;XY=xy;}
};
//---------------------------------------------------------------------------
struct T_Resource
{
    float Crystal,
          Gold,
          Iron,
          Coal,
          Tree;
    T_Resource(){Crystal=Gold=Iron=Coal=Tree=0;}
};
//---------------------------------------------------------------------------
enum T_Info
{
    InfoName,
    InfoXY,
    InfoLife,
    InfoAttack,
    InfoAttackFire,
    InfoAttackWater,
    InfoAttackEarth,
    InfoAttackAir,
    InfoAttackRadius,
    InfoProtection,
    InfoProtectionFire,
    InfoProtectionWater,
    InfoProtectionEarth,
    InfoProtectionAir,
    InfoWalkingRadius,
    InfoResource,
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class T_List;
//---------------------------------------------------------------------------
class T_Any_Object
{
    protected:
        char Name[10];
        T_Poligon *Picture;
        T_Point XY;
        bool isDraw;
        int Active; // 2-можна ходити або(і) атакувати
                    // 1-ходити або атакувати
                    // 0-нічо не можна робити(атака забирає 2, ходіння 1)
    public:
        virtual void SaveToFile(FILE *);
        virtual int nSaveToFile(FILE *);
        virtual void LoadFromFile(FILE *);
    public:
            T_Any_Object();
            T_Any_Object(const T_Any_Object &);
            T_Any_Object(char *,T_Poligon *,TPoint);
        T_Any_Object& operator = (const T_Any_Object &);
        bool isHere(T_Point);
        T_Point GetXY(){return XY;}
        virtual     ~T_Any_Object();
        virtual bool isLive()=0;
        virtual char* GetInfo(int);
        virtual T_Any_Object* GetWarrior(int,int,T_List &)=0;
        virtual T_Bang CreateBang(T_Point)=0;
        virtual T_Resource GetResource()=0;
        virtual T_Resource GetResource(T_Resource)=0;
        virtual void AddResource(T_Resource &)=0;
        virtual void AddWarrior(T_Any_Object *)=0;
        virtual void AfterBang(T_Bang)=0;
        virtual void MoveTo(T_Point)=0;
        void DoActive(){Active=MAX_ACTIVE;}
        void Draw(TCanvas *,T_Point,float,float);
        void SavePicture(char *fname){Picture->SaveToFile(fname);}
        void SetPicture(T_Poligon *p){Picture=p;}
};
//---------------------------------------------------------------------------
typedef T_Any_Object* pT_Any_Object;
//---------------------------------------------------------------------------
typedef int (*T_Simile)(T_Any_Object *,T_Any_Object *);
//---------------------------------------------------------------------------
#include "T_List.h"
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
