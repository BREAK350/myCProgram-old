//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
#include "T_Vector2d.h"
#include "TbList2.h"
//---------------------------------------------------------------------------
template <class TLink>
class TbView
{
    protected:
        struct TItem
        {
            double Angle,Value,Distance;
            TLink *Link;
            TItem() {}
            TItem(const double &Angle,const double &Value,
                const double &Distance,TLink *Link)
            {
                this->Angle=Angle;
                this->Value=Value;
                this->Distance=Distance;
                this->Link=Link;
            }
        };
    protected:
        T_Vector2d View;
        double Angle;
        TbList2 < TItem > Angles; // від більших до менших ( від + до -)

        void AddMinMax(const double &MinAngle,const double &MaxAngle,
            const double &Value,const double &Distance,TLink *Link)
        {
            TItem MinItem(MinAngle,Value,Distance,Link),
                  MaxItem(MaxAngle,Value,Distance,Link),Prev;

            Angles.CurrSetFirst();
            while(Angles.CurrCorrect() && MinAngle>Angles.GetCurr().Angle)
            {
                Angles.CurrSetNext();
            }
            if(Angles.CurrCorrect())
            {
                if(MinAngle<Angles.GetCurr().Angle)
                {
                    Angles.CurrSetPrev();
                    if(Angles.CurrCorrect())
                    {
                        Prev=Angles.GetCurr();
                        if(Distance<Angles.GetCurr().Distance)
                        {
                            Angles.AddCurrNext(MinItem);
                            Angles.CurrSetNext();
                        }
                        Angles.CurrSetNext();
                    }
                    else
                    {
                        Angles.CurrSetFirst();
                    }
                }
                else
                {
                    if(Distance<Angles.GetCurr().Distance)
                    {
                        Angles.GetCurr()=MinItem;
                        Angles.CurrSetNext();
                    }
                }
            }
            while(Angles.CurrCorrect() && MaxAngle>=Angles.GetCurr().Angle)
            {
                Prev=Angles.GetCurr();
                if(Distance<Angles.GetCurr().Distance)
                {
                    if(Angles.CurrIsFirst())
                    {
                        Angles.GetCurr().Value=Value;
                        Angles.GetCurr().Distance=Distance;
                        Angles.GetCurr().Link=Link;
                        Angles.CurrSetNext();
                    }
                    else
                    {
                        Angles.DeleteCurr();
                    }
                }
                else
                {
                    Angles.CurrSetNext();
                }
            }
            if(Angles.CurrCorrect())
            {
                Angles.CurrSetPrev();
                if(Angles.CurrCorrect())
                {
                    Prev.Angle=MaxAngle;
                    Angles.AddCurrNext(Prev);
                }
            }
        }
    public:
        TbView(const T_Vector2d &_View,const double &Angle,const double &MaxDistance)
            :View(_View)
        {
            this->Angle=fabs(Angle);
            TItem MinItem(-this->Angle,0,MaxDistance,NULL),
                  MaxItem(this->Angle,0,0,NULL);
            Angles.Add(MinItem);
            Angles.Add(MaxItem);
        }

        void Add(const double &Angle1,const double &Angle2,
            const double &Value,const double &Distance,TLink *Link)
        {
            if(Link && Distance>0 && (fabs(Angle1)<Angle || fabs(Angle2)<Angle))
            {
                if(Angle1>Angle2)
                {
                    AddMinMax(Angle2,Angle1,Value,Distance,Link);
                }
                else
                {
                    if(Angle2>Angle1)
                    {
                        AddMinMax(Angle1,Angle2,Value,Distance,Link);
                    }
                }
            }
        }

        void Print(TMemo *Memo)
        {
            Memo->Lines->Clear();
            Angles.CurrSetFirst();
            while(Angles.CurrCorrect())
            {
                Memo->Lines->Add(FloatToStr(Angles.GetCurr().Angle)+", "+
                                 FloatToStr(Angles.GetCurr().Distance));
                Angles.CurrSetNext();
            }
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
//---------------------------------------------------------------------------
#endif
 