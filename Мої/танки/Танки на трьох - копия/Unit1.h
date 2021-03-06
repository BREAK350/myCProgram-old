//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TbGraphicControl.h"
#include <ExtCtrls.hpp>
#include "T_Trajectory.h"
#include <Menus.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1;
class TbMoveObj:public TbGCItem
{
    public:
        TForm1 *Form;
        TbMoveObj(TForm1 *Form,const double &R,const double &Health);
        T_Vector2d Location;
        double R;
        double Health,MaxHealth;
        virtual void Draw(TbOrientation &Or);
        virtual void SetColor(TCanvas *Canvas) { Canvas->Brush->Color=clYellow; }
};
//---------------------------------------------------------------------------
class TbTank;
class TbShell:public TbMoveObj
{
    protected:
        T_Vector2d Speed;
    public:
        TbShell(TForm1 *Form,const T_Vector2d &Speed);
        void Move();
        virtual void NextPos();
        virtual void Draw(TbOrientation &Or);
        void Check();
};
//---------------------------------------------------------------------------
class TbTank:public TbMoveObj
{
    public:
        double Last_t;
        int CurrTimeShoot,MaxTimeShoot;
        T_Vector2d Direction;

        T_Vector2d Gun;
        TColor Color;
        int Button;
        double GunRotate;
    public:
        TbTank(TForm1 *Form,const double &Speed,const double &R,
            const int &MaxTimeShoot); // Trajectory!=NULL
        virtual void NextPos();
        void Move(T_Trajectory *Trajectory);
        virtual void Draw(TbOrientation &Or);
        virtual void SetColor(TCanvas *Canvas) { Canvas->Brush->Color=Color; }
        TbShell* DoShoot();
};
//---------------------------------------------------------------------------
class TbAvtoTank:public TbTank
{
    public:
        TbAvtoTank(TForm1 *Form,const double &Speed,const double &R,
            const int &MaxTimeShoot):TbTank(Form,Speed,R,MaxTimeShoot) {}
        TbShell* AvtoShoot();
        virtual void NextPos();
};
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TTimer *Timer1;
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TPanel *Panel1;
    TLabel *Label1;
    TLabel *Label2;
    TEdit *Edit1;
    TLabel *Label3;
    TEdit *Edit2;
    TLabel *Label4;
    TEdit *Edit3;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *Edit4;
    TLabel *Label7;
    TLabel *Label8;
    TEdit *Edit5;
    TLabel *Label9;
    TEdit *Edit6;
    TButton *Button1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N181;
    TMenuItem *N141;
    TMenuItem *N121;
    TMenuItem *N111;
    TMenuItem *N22;
    TMenuItem *N32;
    TMenuItem *N4;
    TMenuItem *N5;
    TMenuItem *N6;
    TPanel *Panel2;
    TComboBox *ComboBox1;
    TLabel *Label10;
    TComboBox *ComboBox2;
    TButton *Button2;
    TMediaPlayer *MediaPlayer1;
    TMediaPlayer *MediaPlayer2;
    TMediaPlayer *MediaPlayer3;
    TMediaPlayer *MediaPlayer4;
    TMediaPlayer *MediaPlayer5;
    TMenuItem *N7;
    TLabel *Label11;
    TEdit *Edit7;
    TMenuItem *N8;
    void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall N111Click(TObject *Sender);
    void __fastcall N121Click(TObject *Sender);
    void __fastcall N141Click(TObject *Sender);
    void __fastcall N181Click(TObject *Sender);
    void __fastcall N22Click(TObject *Sender);
    void __fastcall N32Click(TObject *Sender);
    void __fastcall N5Click(TObject *Sender);
    void __fastcall N6Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N7Click(TObject *Sender);
    void __fastcall N8Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    TbGraphicControl GC;
    T_Trajectory Trajectory;
    TbList2 <TbTank *> Tank;
    double GunRotate;
    int MPCur;
    int TankCount,TankEnemyCount;

    void MPlay();
    void NewGame();
    void ReadData();

    double TankHealth,TankSpeed;
    int TankSpeedShoot;
    double ShellMinPower,ShellMaxPower,ShellSpeed;
    void Pause() { Timer1->Enabled=false; }
    void Play() { Timer1->Enabled=true; }
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
T_Vector2d VectorShoot(const T_Vector2d &Enemy,const T_Vector2d &LookAtMe,
    const double &Distance);
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
