//---------------------------------------------------------------------------
#ifndef DetailsH
#define DetailsH
#include <iostream.h>
#include <vcl.h>
#define FAULT_PROCENT 50.0
#define FAULT ((FAULT_PROCENT+1+random(100-FAULT_PROCENT))/100.0)
//---------------------------------------------------------------------------
class T_Protection;
class T_SuperWeapon;
class T_Life;
class T_Character;
/********************************T_Attack***********************************/
class T_Attack
{
    private:
        float Power;
        T_SuperWeapon *SW;
    public:
        T_Attack();
        T_Attack(const float &,const T_SuperWeapon &);
        T_Attack(const T_Attack &);
        ~T_Attack();
        T_Attack& operator = (const T_Attack &);
        T_Attack Fault(); 
        void Interaction(const T_Protection &);
        friend T_Life;
        friend T_Character;
};
//---------------------------------------------------------------------------
/*******************************T_Character*********************************/
class T_Character
{
    private:
        float Elasticity,  // Гнучкість
              Power,       // Сила
              Felicity,    // Влучність
              Strength,    // Міцність
              Reaction,    // Реакція
              Speed;       // Швидкість
        void Interaction(const T_Character &);
    public:
        T_Character();
        T_Character(const float &,const float &,const float &,const float &,
                    const float &,const float &);
        T_Character(const T_Character &);
        ~T_Character();
        T_Character& operator = (const T_Character &);
        T_Attack GetAttack();
        T_Protection GetProtection();
        void Interaction(const T_Attack &);
};
//---------------------------------------------------------------------------
/*****************************T_SuperWeapon*********************************/
class T_SuperWeapon
{
    private:
        float Power;
        T_Character Type;
    public:
        T_SuperWeapon();
        T_SuperWeapon(const T_SuperWeapon &);
        T_SuperWeapon(const float &,const T_Character &);
        T_SuperWeapon& operator = (const T_SuperWeapon &);
        friend T_Character;
};
//---------------------------------------------------------------------------
/******************************T_Protection*********************************/
class T_Protection
{
    private:
        float Power;
    public:
        T_Protection();
        T_Protection(const T_Protection &);
        T_Protection(const float &);
        T_Protection& operator = (const T_Protection &);
        T_Protection Fault(); 
        friend T_Attack;
};
//---------------------------------------------------------------------------
/*********************************T_Life************************************/
class T_Life
{
    private:
        float Amount;
    public:
        T_Life();
        T_Life(const T_Life &);
        T_Life(const float &);
        T_Life& operator = (const T_Life &);
        void Interaction(const T_Attack &);
};
//---------------------------------------------------------------------------
/********************************T_Stomach**********************************/
class T_Stomach // шлунок
{
    private:
        float Size;
    public:
        T_Stomach();
        T_Stomach(const T_Stomach &);
        T_Stomach(const float &);
        T_Stomach& operator = (const T_Stomach &);
        void Interaction(const T_Attack &);
};
//---------------------------------------------------------------------------
/********************************T_Energy***********************************/
class T_Energy
{
    private:
        float Amount;
    public:
        T_Energy();
        T_Energy(const T_Energy &);
        T_Energy(const float &);
        T_Energy& operator = (const T_Energy &);
        void Interaction(const T_Attack &);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif

