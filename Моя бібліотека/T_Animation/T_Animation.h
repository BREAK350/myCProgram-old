//---------------------------------------------------------------------------
#ifndef T_AnimationH
#define T_AnimationH
#include <vcl.h>
//---------------------------------------------------------------------------
struct T_AnimationLink
{
    int x1,y1,x2,y2;
    T_AnimationLink() { x1=y1=x2=y2=0; }
    T_AnimationLink(const int &x1,const int &y1,const int &x2,const int &y2)
    {
        this->x1=x1;
        this->y1=y1;
        this->x2=x2;
        this->y2=y2;
    }
    T_AnimationLink(const T_AnimationLink &al)
    {
        x1=al.x1;
        y1=al.y1;
        x2=al.x2;
        y2=al.y2;
    }
    int Width() { return abs(x1-x2); }
    int Height() { return abs(y1-y2); }
    operator TRect() { return TRect(x1,y1,x2,y2); }
    T_AnimationLink& operator = (const T_AnimationLink &al)
    {
        x1=al.x1;
        y1=al.y1;
        x2=al.x2;
        y2=al.y2;
        return *this;
    }
};
//---------------------------------------------------------------------------
enum Anim_Type
{
    Anim_POINTER,
    Anim_OBJECT
};
//---------------------------------------------------------------------------
class T_Animation
{
    private:
        Graphics::TBitmap *Picture;
        int AmountLink;
        T_AnimationLink *Links;
        Anim_Type Type;
    public:
        T_Animation();
        T_Animation(const T_Animation &);
        T_Animation(const Anim_Type &,Graphics::TBitmap *,const int &,const T_AnimationLink *);
        ~T_Animation();
        T_Animation& operator = (const T_Animation &);
        void Draw(const int &,const TPoint &,TCanvas *)const;
        void Draw(const int &,const TPoint &,TCanvas *,const TColor &)const;
        void SetLink(const int &,const T_AnimationLink &);
        void SetPictureLink(Graphics::TBitmap *);
        void LoadPicture(const char *);
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
#endif
 