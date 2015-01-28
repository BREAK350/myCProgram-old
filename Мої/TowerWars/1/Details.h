//---------------------------------------------------------------------------
#ifndef DetailsH
#define DetailsH
#include <vcl.h>
#include "T_Point.h"
#include "T_Vector.h"
#include "T_Animation.h"
const int SizePicture = 50;
const int REPAINTTIME = 20;
//---------------------------------------------------------------------------
enum Gun
{
    STAND,
    SHOOT
};
//---------------------------------------------------------------------------
enum Warrior
{
    GO_UP,
    GO_DOWN,
    GO_RIGHT,
    GO_LEFT
};
//---------------------------------------------------------------------------
class T_Object
{
    protected:
        T_Animation Anim;
        T_Point XY;
        int Status;
    public:
        T_Object(const T_Point &,const T_Animation &);
        T_Object(const T_Object &);
        ~T_Object();
        T_Object& operator = (const T_Object &);
        void Draw(TCanvas *)const;
        void Draw(const int &,const int &,TCanvas *)const;
        void ShowPicture(const int & x,const int &y,TCanvas *Canvas)const;
            //{ Canvas->Draw(x,y,Picture); }
        T_Point* GetXY() { return &XY; }
        T_Animation* GetAnim() { return &Anim; }
};
//---------------------------------------------------------------------------
class T_Gun;
class T_Map;
class T_Warrior: public T_Object
{
        friend T_Gun;
        friend void Init_Warrior(const int &,T_Warrior **);
    protected:
        int Speed;
        float Life;
        int AmountPoint;
        int CurrentPoint;
        T_Point *Road;
    public:
        T_Warrior(const T_Point &,const T_Animation &,const int &,const float &);
        T_Warrior(const T_Warrior &);
        ~T_Warrior();
        T_Warrior& operator = (const T_Warrior &);
        void Move(const int &);
        int Move(const T_Map &);
        T_Point* NewRoad(const T_Map &);
        T_Point* GetRoad() { return Road; }
        float GetLengthRoad();
        void UpLife(const int &k) { Life=Life*(1+k/100.0); }
};
//---------------------------------------------------------------------------
class T_Gun: public T_Object    // пушка
{
        friend void Init_Gun(const int &,T_Gun **);
    protected:
        float Attack;
        int AttackPower;
        int Power;
        float Radius;
    public:
        T_Gun(const T_Point &,const T_Animation &,const int &,const float &,const float &);
        T_Gun(const T_Gun &);
        ~T_Gun();
        T_Gun& operator = (const T_Gun &);
        void LoadPower();    
        bool doAttack(T_Warrior *&);
};
//---------------------------------------------------------------------------
class T_Map
{
    protected:
        int Height,Width;
        Graphics::TBitmap *BackGround,*Buf;
        T_Gun ***Gun;
        int AmountWarrior;
        T_Warrior **Warrior; // впорядкований від найближчого до найдальшого відносно кристала
        T_Warrior Cursor;
        void CreatePicture();
        int Interval; // накопичення
        T_Warrior *AddW;
        int In;
        int AddWarrior();
        int Life;
        void CreateRoadNext(const int &,const int &,int **,int &)const;
        void GetPoints(T_Point *,int,int,int **)const;
        T_Point Begin,End;
        void NewRoad();
        char* SortY(int &);
        int caw;
    public:
        T_Map(const int &,const int &,const T_Animation &,const T_Animation &,
            const int &,const int &);
        void Draw(const int &,const int &,TCanvas *);
        void Cursor_UP();
        void Cursor_DOWN();
        void Cursor_RIGHT();
        void Cursor_LEFT();
        void AddGun(const int &,const int &,const T_Gun &);
        void AddGun(const T_Gun &);
        void AddWarrior(const T_Warrior &,const int &);
        int NextStep();
        T_Point* CreateRoad(const T_Point &,int &)const;
        void ShowRoad(char *);
        int GetAmountWarrior();
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
