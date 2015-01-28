//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "T_Trajectory.h"
#include "TbOrientation.h"
#include "TbList2.h"
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
struct TbCurveVector
{
    T_Vector2d Point;
    T_Curve *Curve;
};
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
    __published:	// IDE-managed Components
    TMainMenu *MainMenu1;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    TMenuItem *N4;
    TMenuItem *N5;
    TOpenDialog *OpenDialog1;
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TEdit *Edit1;
    TEdit *Edit2;
    TLabel *Label2;
    TEdit *Edit3;
    TEdit *Edit4;
    TCheckBox *CheckBox1;
    TCheckBox *CheckBox2;
    TButton *Button1;
    TGroupBox *gbSegment;
    TEdit *Edit5;
    TEdit *Edit6;
    TEdit *Edit7;
    TEdit *Edit8;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormResize(TObject *Sender);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall FormMouseWheelDown(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseWheelUp(TObject *Sender, TShiftState Shift,
          TPoint &MousePos, bool &Handled);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormClick(TObject *Sender);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    private:	// User declarations
        void ViewCurve(T_Curve *Curve);
        void ReadOr();
        void WriteOr();
    public:		// User declarations
        TbList2 < T_Vector2d* > Points;
        TbList2 < TbCurveVector > CaseCurve;
        T_Vector2d *Curr;
        TbCurveVector *ccCurr;
        T_Trajectory Tr;
        int PointR;
        TPoint Cursor;
        bool MouseDown;
        Graphics::TBitmap *bmp;
        double E,Scale;
        TbOrientation Or;
        void LoadFromFile(const char *FileName);
        void DrawAll();
        void DrawTr();
        void DrawPoints();
        void DrawCurrPoint()const;
        void AddPoint(T_Vector2d *p);
        void SetCurr(const int &x,const int &y);
        void CreateCaseCurve();
        void DrawCaseCurve();
        void OpenPanelAndWriteData(T_Curve *Curve);
        void SavePanelAndReadData(T_Curve *Curve);
        T_Vector2d* SearchF(const T_Vector2d &p);
        T_Vector2d* SearchN(const T_Vector2d &p);
        TbCurveVector* SearchCaseCurveF(const T_Vector2d &p);
        TbCurveVector* SearchCaseCurveN(const T_Vector2d &p);
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
