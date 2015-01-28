//---------------------------------------------------------------------------
#pragma hdrstop
#include "T_Animation.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Animation::T_Animation()
{
    Picture=NULL;
    AmountLink=0;
    Links=NULL;
    Type=Anim_POINTER;
}
//---------------------------------------------------------------------------
T_Animation::T_Animation(const T_Animation &a)
{
    int i;
    Type=Anim_POINTER;
    Picture=a.Picture;
    AmountLink=a.AmountLink;
    Links=new T_AnimationLink[AmountLink];
    for(i=0;i<AmountLink;i++)
    {
        Links[i]=a.Links[i];
    }
}
//---------------------------------------------------------------------------
T_Animation::T_Animation(const Anim_Type &t,Graphics::TBitmap *p,const int &n,
    const T_AnimationLink *l)
{
    int i;
    Type=t;
    if(Type==Anim_POINTER || p==NULL)
    {
        Picture=p;
    }
    if(Type==Anim_OBJECT)
    {
        Picture=new Graphics::TBitmap;
        Picture->Height=p->Height;
        Picture->Width=p->Width;
        Picture->Canvas->Draw(0,0,p);
    }
    AmountLink=n;
    Links=new T_AnimationLink[AmountLink];
    for(i=0;i<AmountLink;i++)
    {
        Links[i]=l[i];
    }
}
//---------------------------------------------------------------------------
T_Animation::~T_Animation()
{
    if(Type==Anim_OBJECT)
    {
        delete Picture;
    }
    Picture=NULL;
    AmountLink=0;
    delete[] Links;
    Links=NULL;
}
//---------------------------------------------------------------------------
T_Animation& T_Animation::operator = (const T_Animation &a)
{
    int i;
    if(this!=&a)
    {
        if(Type==Anim_OBJECT)
        {
            delete Picture;
        }
        Type=Anim_POINTER;
        Picture=a.Picture;
        AmountLink=a.AmountLink;
        delete[] Links;
        Links=new T_AnimationLink[AmountLink];
        for(i=0;i<AmountLink;i++)
        {
            Links[i]=a.Links[i];
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
void T_Animation::Draw(const int &k,const TPoint &p,TCanvas *Canvas)const
{
    if(k>=0 && k<AmountLink && Canvas && Picture)
    {
        Canvas->CopyMode=cmSrcCopy;
        Canvas->CopyRect(TRect(p.x,p.y,p.x+Links[k].Width(),p.y+Links[k].Height()),
            Picture->Canvas,Links[k]);
    }
}
//---------------------------------------------------------------------------
void T_Animation::Draw(const int &k,const TPoint &p,TCanvas *Canvas,
    const TColor &cl)const
{
    if(k>=0 && k<AmountLink)
    {
        Graphics::TBitmap *buf=new Graphics::TBitmap;
        buf->Height=(int)Links[k].Height();
        buf->Width=(int)Links[k].Width();
        Draw(k,TPoint(0,0),buf->Canvas);
        buf->Transparent=true;
        buf->TransparentMode=tmFixed;
        buf->TransparentColor=cl;
        Canvas->Draw(p.x,p.y,buf);
        delete buf;
        buf=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Animation::SetLink(const int &k,const T_AnimationLink &al)
{
    if(k>=0 && k<AmountLink)
    {
        Links[k]=al;
    }
    else
    {
        int i;
        T_AnimationLink *buf=new T_AnimationLink[AmountLink];
        for(i=0;i<AmountLink;i++)
        {
            buf[i]=Links[i];
        }
        delete[] Links;
        Links=new T_AnimationLink[AmountLink+1];
        if(k<0)
        {
            Links[0]=al;
            for(i=0;i<AmountLink;i++)
            {
                Links[i+1]=buf[i];
            }
        }
        else
        {
            for(i=0;i<AmountLink;i++)
            {
                Links[i]=buf[i];
            }
            Links[i]=al;
        }
        AmountLink++;
        delete[] buf;
        buf=NULL;
    }
}
//---------------------------------------------------------------------------
void T_Animation::SetPictureLink(Graphics::TBitmap *p)
{
    Picture=p;
}
//---------------------------------------------------------------------------
void T_Animation::LoadPicture(const char *fname)
{
    if(Type==Anim_OBJECT)
    {
        delete Picture;
    }
    Picture=new Graphics::TBitmap;
    Picture->LoadFromFile(fname);
    Type=Anim_OBJECT;
}
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
 