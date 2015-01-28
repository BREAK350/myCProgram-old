//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int T_List::Add(const float &angle1,const float &angle2,const int &value)
    // angle1!=angle2 , angle1,angle2>=0
{
    int v=0;
    float amin=(angle1>angle2)?(angle2):(angle1),
          amax=(angle1>angle2)?(angle1):(angle2);
    Add(amin,value);
    Add(amax,value);
    T_ListItem *p=First;
    while(p && p->Angle!=amin)
    {
        p=p->Next;
    }
    v=p->Value;
    while(p && p->Angle<amax)
    {
        if(v>p->Value)
        {
            v=p->Value;
        }
        p->Value+=value;
        p=p->Next;
    }
    return v;
}
//---------------------------------------------------------------------------
void T_List::Add(const float &angle,const int &value)
{
    if(First)
    {
        if(angle<First->Angle)
        {
            T_ListItem *f=new T_ListItem(angle,0);
            f->Next=First;
            First=f;
        }
        else
        {
            if(angle!=First->Angle)
            {
                T_ListItem *p=First;
                while(p->Next && angle>p->Next->Angle)
                {
                    p=p->Next;
                }
                if(p->Next)
                {
                    if(angle!=p->Next->Angle)
                    {
                        T_ListItem *t=new T_ListItem(angle,p->Value);
                        t->Next=p->Next;
                        p->Next=t;
                    }
                }
                else
                {
                    p->Next=new T_ListItem(angle,p->Value);
                }
            }
        }
    }
    else
    {
        First=new T_ListItem(angle,0);
    }
}
//---------------------------------------------------------------------------
void T_List::Delete(T_ListItem *&Item)
{
    if(Item)
    {
        Delete(Item->Next);
        delete Item;
        Item=NULL;
    }
}
//---------------------------------------------------------------------------
float GetAngle(const float &Ax,const float &Ay,const float &Bx,const float &By)
{
    float angle=0;
    if(Ax==Bx)
    {
        if(By>Ay)
        {
            angle=90;
        }
        else
        if(By<Ay)
        {
            angle=270;
        }
    }
    else
    {
        angle=atan((By-Ay)/(Bx-Ax))*180/M_PI;
        if(Bx>Ax)
        {
            if(By<Ay)
            {
                angle+=360;
            }
        }
        else
        {
            angle+=180;
        }
    }
    return angle;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 