//---------------------------------------------------------------------------
#ifndef T_MineryH
#define T_MineryH
#include "T_StationaryObject.h"
//---------------------------------------------------------------------------
class T_Minery:public T_StationaryObject
{
    protected:
        T_Resource Resource;
    public:
        virtual void SaveToFile(FILE *);
        virtual int nSaveToFile(FILE *);
        virtual void LoadFromFile(FILE *);
    public:
            T_Minery();
            T_Minery(const T_Minery &);
            T_Minery(char *,T_Poligon *,TPoint,T_Life,T_Protection,T_Resource);
        T_Minery& operator = (const T_Minery &);
        virtual     ~T_Minery(){}
        virtual T_Any_Object* GetWarrior(int,int,T_List &){return NULL;}
        virtual T_Bang CreateBang(T_Point){return T_Bang();}
        virtual T_Resource GetResource();
        virtual T_Resource GetResource(T_Resource){return GetResource();}
        virtual void AddResource(T_Resource &){}
        virtual void MoveTo(T_Point){}
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
 