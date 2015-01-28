//---------------------------------------------------------------------------
#ifndef T_WarriorH
#define T_WarriorH
#include "T_StationaryObject.h"
#define ACCIDENT 20
//---------------------------------------------------------------------------
class T_Warrior:public T_StationaryObject
{
    protected:
        T_Attack Attack;
        float WalkingRadius;
        float AttackRadius;
    public:
        virtual void SaveToFile(FILE *);
        virtual int nSaveToFile(FILE *);
        virtual void LoadFromFile(FILE *);
    public:
        T_Warrior();
        T_Warrior(const T_Warrior &);
        T_Warrior(char *,T_Poligon *,TPoint,T_Life,T_Protection,T_Attack,float,float);
        T_Warrior& operator = (const T_Warrior &);
        virtual ~T_Warrior(){}
        virtual void MoveTo(T_Point);
        virtual T_Bang CreateBang(T_Point);
        virtual T_Resource GetResource(){return T_Resource();}
        virtual T_Any_Object* GetWarrior(int,int,T_List &){return NULL;}
        virtual T_Resource GetResource(T_Resource){return T_Resource();}
        virtual void AddResource(T_Resource &){}
        virtual void AddWarrior(T_Any_Object *){}
        virtual char* GetInfo(int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
