//---------------------------------------------------------------------------
#ifndef T_StationaryObjectH
#define T_StationaryObjectH
#include "T_Any_Object.h"
//---------------------------------------------------------------------------
struct T_Life
{
    float Health,MaxHealth;
    T_Life(){Health=MaxHealth=0;}
    T_Life(float h){Health=MaxHealth=h;}
};
//---------------------------------------------------------------------------
class T_StationaryObject:public T_Any_Object
{
    protected:
        T_Life Life;
        T_Protection Protection;
    public:
        virtual void SaveToFile(FILE *);
        virtual int nSaveToFile(FILE *);
        virtual void LoadFromFile(FILE *);
    public:
            T_StationaryObject();
            T_StationaryObject(const T_StationaryObject &);
            T_StationaryObject(char *,T_Poligon *,TPoint,T_Life,T_Protection);
        virtual     ~T_StationaryObject();
        T_StationaryObject& operator = (const T_StationaryObject &);
        virtual void MoveTo(T_Point){}
        virtual void AfterBang(T_Bang);
        virtual T_Bang CreateBang(T_Point){return T_Bang();}
        virtual bool isLive(){return Life.Health>0;}
        virtual T_Resource GetResource()=0;
        virtual T_Any_Object* GetWarrior(int,int,T_List &)=0;
        virtual T_Resource GetResource(T_Resource)=0;
        virtual void AddResource(T_Resource &)=0;
        virtual void AddWarrior(T_Any_Object *)=0;
        virtual char* GetInfo(int);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
