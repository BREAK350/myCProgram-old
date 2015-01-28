//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "TbList2.h"
#include "T_Trajectory.h"
//---------------------------------------------------------------------------
const TColor clEnemy = clRed;
const TColor clGun   = clBlue;
const TColor clShell = clYellow;
//---------------------------------------------------------------------------
struct TbTWObject
{
    int Health,MaxHealth;
    T_Vector2d Location;
    int R;
    TbTWObject() { MaxHealth=0; Health=0; R=0; }
    TbTWObject(const int &_MaxHealth,const T_Vector2d &_Location,const int &_R)
        :Location(_Location)
    {
        Health=MaxHealth=_MaxHealth;
        R=_R;
    }
    
    virtual void Move() {}
    virtual void Recharge() {}
    virtual void SetColor(TCanvas *Canvas)const {}
    void Draw(TCanvas *Canvas)const;
};
//---------------------------------------------------------------------------
struct TbTWMainObject:public TbTWObject
{
    T_Vector2d vGun;
    int Time,TimeRecharge;
    TbTWMainObject() { Time=0; TimeRecharge=-1; }
    TbTWMainObject(const int &_MaxHealth,const T_Vector2d &_Location,const int &_R,
                   const T_Vector2d &_vGun,const int &_Time,const int &_TimeRecharge)
                   :TbTWObject(_MaxHealth,_Location,_R),vGun(_vGun)
    {
        Time=_Time;
        TimeRecharge=_TimeRecharge;
    }

    void Draw(TCanvas *Canvas)const
    {
        TbTWObject::Draw(Canvas);
        DrawGun(Canvas);
    }
    void DrawGun(TCanvas *Canvas)const;
    virtual double LengthGun()const { return 0; }
    virtual void Recharge()
    {
        if(Time<TimeRecharge)
        {
            Time++;
        }
    }
};
//---------------------------------------------------------------------------
struct TbTWEnemy:public TbTWMainObject
{
    double Last_t;
    T_Trajectory *Road;
    TbTWEnemy() { Last_t; Road=NULL; }
    TbTWEnemy(const int &_MaxHealth,const T_Vector2d &_Location,const int &_R,
              const T_Vector2d &_vGun,const int &_Time,const int &_Recharge,
              const double &_Last_t,T_Trajectory *_Road)
              :TbTWMainObject(_MaxHealth,_Location,_R,_vGun,_Time,_Recharge)
    {
        Last_t=_Last_t;
        Road=_Road;
    }

    virtual void SetColor(TCanvas *Canvas)const
    {
        Canvas->Brush->Color=clEnemy;
    }
    virtual void Move()
    {
        Road->NextPoint_Right(Last_t,Location);
        Last_t=Road->Get_t();
    }
    virtual double LengthGun()const
    {
        return (double)Time/TimeRecharge*R/2+3.0/2*R;
    }
};
//---------------------------------------------------------------------------
struct TbTWGun:public TbTWMainObject
{
    TbTWGun() {}
    TbTWGun(const int &_MaxHealth,const T_Vector2d &_Location,const int &_R,
            const T_Vector2d &_vGun,const int &_Time,const int &_Recharge)
            :TbTWMainObject(_MaxHealth,_Location,_R,_vGun,_Time,_Recharge)
    {
    }

    virtual void SetColor(TCanvas *Canvas)const
    {
        Canvas->Brush->Color=clGun;
    }
    virtual double LengthGun()const
    {
        return (double)Time/TimeRecharge*R/2+3.0/2*R;
    }
};
//---------------------------------------------------------------------------
struct TbTWShell:public TbTWObject
{
    T_Vector2d Speed;
    TbTWShell() {}
    TbTWShell(const int &_MaxHealth,const T_Vector2d &_Location,const int &_R,
              const T_Vector2d &_Speed):TbTWObject(_MaxHealth,_Location,_R),Speed(_Speed) {}

    virtual void SetColor(TCanvas *Canvas)const
    {
        Canvas->Brush->Color=clShell;
    }
    virtual void Move()
    {
        Location=Location+Speed;
        if(Location.Length()>2000)
        {
            Health=0;
        }
    }
};
//---------------------------------------------------------------------------
template <class TList>
void Move(TList &List)
{
    List.CurrSetFirst();
    while(List.CurrCorrect())
    {
        List.GetCurr().Move();
        List.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
template <class TList>
void CheckHealth(TList &L)
{
    L.CurrSetFirst();
    while(L.CurrCorrect())
    {
        if(L.GetCurr().Health<=0)
        {
            L.DeleteCurr();
        }
        else
        {
            L.CurrSetNext();
        }
    }
}
//---------------------------------------------------------------------------
template <class TList>
void Recharge(TList &List)
{
    List.CurrSetFirst();
    while(List.CurrCorrect())
    {
        List.GetCurr().Recharge();
        List.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
template <class TObjectShell,class TListTarget>
void CheckShellShot1(TObjectShell &Shell,TListTarget &Target)
{
    Target.CurrSetFirst();
    while(Shell.Health>0 && Target.CurrCorrect())
    {
        if((Shell.Location-Target.GetCurr().Location).Length()<
            Shell.R+Target.GetCurr().R)
        {
            Target.GetCurr().Health-=Shell.Health;
            Shell.Health=0;
        }
        Target.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
template <class TListShell,class TListL>
void CheckShellShot(TListShell &Shell,TListL &Target)
{
    Shell.CurrSetFirst();
    while(Shell.CurrCorrect())
    {
        CheckShellShot1(Shell.GetCurr(),Target);
        Shell.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
template <class TList>
void Draw(TCanvas *Canvas,TList &List)
{
    List.CurrSetFirst();
    while(List.CurrCorrect())
    {
        List.GetCurr().Draw(Canvas);
        List.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
template <class TShooter,class TTarget,class TListShell>
void CreateShot(TShooter &Shooter,TTarget &Target,TListShell &Shell)
{
    Shooter.vGun=Target.Location-Shooter.Location;
    Shooter.vGun.SetLength(2000);
    Shooter.vGun.Rotate((random(10)-5)*M_PI/180);
    TbTWShell s;
    s.Health=30;
    s.MaxHealth=30;
    s.R=5;
    T_Vector2d v=Shooter.vGun;
    v.SetLength(2*Shooter.R);
    s.Location=Shooter.Location+v;
    v.SetLength(10);
    s.Speed=v;
    Shell.AddLast(s);
}
//---------------------------------------------------------------------------
template <class TListShooter,class TListTarget,class TListShell>
void Shot(TListShooter &Shooter,TListTarget &Target,TListShell &Shell)
{
    if(Target.GetCount()>0)
    {
        Shooter.CurrSetFirst();
        while(Shooter.CurrCorrect())
        {
            if(Shooter.GetCurr().Time==Shooter.GetCurr().TimeRecharge)
            {
                Shooter.GetCurr().Time=0;
                int i=random(Target.GetCount());
                Target.CurrSetFirst();
                while(i>0)
                {
                    Target.CurrSetNext();
                    i--;
                }
                CreateShot(Shooter.GetCurr(),Target.GetCurr(),Shell);
            }
            Shooter.CurrSetNext();
        }
    }
}
//---------------------------------------------------------------------------
template <class TListEnemy,class TTrajectory>
void MoveEnemy(TListEnemy &Enemy,TTrajectory &EnemyTrajectory)
{
    Enemy.CurrSetFirst();
    while(Enemy.CurrCorrect())
    {
        EnemyTrajectory.NextPoint_Right(Enemy.GetCurr().Last_t,Enemy.GetCurr().Location);
        Enemy.GetCurr().Last_t=EnemyTrajectory.Get_t();
        Enemy.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class TbTWGameGunWithEnemy
{
    public:
        TbList2  <TbTWGun>  Gun;
        TbList2 <TbTWEnemy> Enemy;
        TbList2 <TbTWShell> Shell;
        T_Trajectory EnemyTrajectory;
    protected:
        void Shot();
        void CheckHealthAll();
        void MoveEnemy();
        void MoveShell();
        void CheckShellShot();
        void Recharge();
    public:
        void Draw(TCanvas *Canvas);
        bool Click();
};
//---------------------------------------------------------------------------
class TbTWGameEnemyWithEnemy
{
    public:
        TbList2 <TbTWEnemy> Enemy1,Enemy2;
        TbList2 <TbTWShell> Shell;
        T_Trajectory Enemy1Trajectory,Enemy2Trajectory;
    protected:
        void Shot();
        void CheckHealthAll();
        void MoveEnemy();
        void MoveShell();
        void CheckShellShot();
        void Recharge();
    public:
        void Draw(TCanvas *Canvas);
        bool Click();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
