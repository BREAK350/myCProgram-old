//---------------------------------------------------------------------------
#ifndef TbGraphicControlH
#define TbGraphicControlH
#include "TbOrientation.h"
#include "TbList2.h"
//---------------------------------------------------------------------------
class TbGCItem
{
    public:
        bool Enabled;

        TbGCItem() { Enabled=true; }
        virtual void Draw(TbOrientation &Or) {}
        virtual void Paint(TbOrientation &Or) {}
        virtual void NextPos() {}
};
//---------------------------------------------------------------------------
class TbGraphicControl
{
    public:
        TTimer *Timer;
        TbList2 <TbGCItem*> List;
        TbOrientation Or;
        TbGraphicControl(TTimer *Timer);

        void Draw();
        void NextPos();
        void Execute();
};
//---------------------------------------------------------------------------
class TbText:public TbGCItem
{
    public:
        AnsiString str;
        TPoint p;
        int interval;
        TbText(const char *str,const TPoint &p,const int &interval)
            { this->str=str; this->p=p; this->interval=interval; }

        virtual void Draw(TbOrientation &Or)
        {
            if(interval>0)
            {
                Or.Canvas->TextOut(p.x,p.y,str);
            }
            else
            {
                Enabled=false;
            }
        }
        virtual void NextPos()
        {
            interval--;
            p.x++;
        }
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
#endif
