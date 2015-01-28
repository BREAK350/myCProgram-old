//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_List.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
int T_List::Add(const float &angle1,const float &angle2,const int &value)
    // angle1!=angle2 , angle1,angle2>=0, від angle1 до angle2
{
    int v=0;
    Add(angle1);
    Add(angle2);
    T_ListItem *p=First;
    while(p->Angle!=angle1)
    {
        p=p->Next;
    }
    v=p->Value;
    while(p->Angle!=angle2)
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
void T_List::Add(const float &angle)
{
    T_ListItem *p=First;
    while(p->Next!=First && angle>p->Next->Angle)
    {
        p=p->Next;
    }
    if(p->Next->Angle!=angle)
    {
        T_ListItem *d=new T_ListItem(angle,p->Value);
        d->Next=p->Next;
        p->Next=d;
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
T_List::~T_List()
{
    T_ListItem *t=First;
    while(t->Next!=First)
    {
        t=t->Next;
    }
    t->Next=NULL;
    Delete(First);
}
//---------------------------------------------------------------------------
T_List::T_List()
{
    First=new T_ListItem(0,0);
    First->Next=First;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 