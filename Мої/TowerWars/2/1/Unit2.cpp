//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void TbTWObject::Draw(TCanvas *Canvas)const
{
    Canvas->Brush->Color=clGray;    
    Canvas->Ellipse(Location.X-R,Location.Y-R,Location.X+R,Location.Y+R);
    SetColor(Canvas);
    T_Vector2d l(0,100),r(0,100);
    l.Rotate(-M_PI*Health/MaxHealth);
    r.Rotate(M_PI*Health/MaxHealth);
    l=l+Location;
    r=r+Location;
    Canvas->Chord(Location.X-R,Location.Y-R,Location.X+R,Location.Y+R,
                r.X,r.Y,l.X,l.Y);
}
//---------------------------------------------------------------------------
void TbTWMainObject::DrawGun(TCanvas *Canvas)const
{
    T_Vector2d g=vGun;
    g.SetLength(LengthGun());
    Canvas->MoveTo(Location.X,Location.Y);
    Canvas->LineTo(g.X+Location.X,g.Y+Location.Y);
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::CheckHealthAll()
{
    CheckHealth(Gun);
    CheckHealth(Enemy);
    CheckHealth(Shell);
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::MoveEnemy()
{
    ::MoveEnemy(Enemy,EnemyTrajectory);
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::MoveShell()
{
    Shell.CurrSetFirst();
    while(Shell.CurrCorrect())
    {
        Shell.GetCurr().Location=Shell.GetCurr().Location+Shell.GetCurr().Speed;
        if(Shell.GetCurr().Location.Length()>2000)
        {
            Shell.GetCurr().Health=0;
        }
        Shell.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::CheckShellShot()
{
    ::CheckShellShot(Shell,Enemy);
    ::CheckShellShot(Shell,Gun);
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::Draw(TCanvas *Canvas)
{
    ::Draw(Canvas,Gun);
    ::Draw(Canvas,Enemy);
    ::Draw(Canvas,Shell);
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::Shot()
{
    ::Shot(Enemy,Gun,Shell);
    ::Shot(Gun,Enemy,Shell);
}
//---------------------------------------------------------------------------
void TbTWGameGunWithEnemy::Recharge()
{
    ::Recharge(Enemy);
    ::Recharge(Gun);
}
//---------------------------------------------------------------------------
bool TbTWGameGunWithEnemy::Click()
{
    CheckHealthAll();
    MoveEnemy();
    MoveShell();
    Recharge();
    Shot();
    CheckShellShot();
    return Enemy.GetCount() && Gun.GetCount();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::CheckHealthAll()
{
    CheckHealth(Enemy1);
    CheckHealth(Enemy2);
    CheckHealth(Shell);
}
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::MoveEnemy()
{
    ::MoveEnemy(Enemy1,Enemy1Trajectory);
    ::MoveEnemy(Enemy2,Enemy2Trajectory);
}
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::MoveShell()
{
    Shell.CurrSetFirst();
    while(Shell.CurrCorrect())
    {
        Shell.GetCurr().Location=Shell.GetCurr().Location+Shell.GetCurr().Speed;
        if(Shell.GetCurr().Location.Length()>2000)
        {
            Shell.GetCurr().Health=0;
        }
        Shell.CurrSetNext();
    }
}
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::CheckShellShot()
{
    ::CheckShellShot(Shell,Enemy1);
    ::CheckShellShot(Shell,Enemy2);
}
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::Draw(TCanvas *Canvas)
{
    ::Draw(Canvas,Enemy1);
    ::Draw(Canvas,Enemy2);
    ::Draw(Canvas,Shell);
}
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::Shot()
{
    ::Shot(Enemy1,Enemy2,Shell);
    ::Shot(Enemy2,Enemy1,Shell);
}
//---------------------------------------------------------------------------
void TbTWGameEnemyWithEnemy::Recharge()
{
    ::Recharge(Enemy1);
    ::Recharge(Enemy2);
}
//---------------------------------------------------------------------------
bool TbTWGameEnemyWithEnemy::Click()
{
    CheckHealthAll();
    MoveEnemy();
    MoveShell();
    Recharge();
    Shot();
    CheckShellShot();
    return Enemy1.GetCount() && Enemy2.GetCount();
}
//---------------------------------------------------------------------------
