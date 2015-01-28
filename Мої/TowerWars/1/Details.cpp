//---------------------------------------------------------------------------
#pragma hdrstop
#include "Details.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
T_Object::T_Object(const T_Point &p,const T_Animation &anim):
    XY(p),Anim(anim)
{
    Status=STAND;
}
//---------------------------------------------------------------------------
T_Object::T_Object(const T_Object &obj):XY(obj.XY),Anim(obj.Anim)
{
    Status=STAND;
}
//---------------------------------------------------------------------------
T_Object::~T_Object()
{

}
//---------------------------------------------------------------------------
T_Object& T_Object::operator = (const T_Object &obj)
{
    if(this!=&obj)
    {
        XY=obj.XY;
        Anim=obj.Anim;
        Status=STAND;
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior(const T_Warrior &w):T_Object(w)
{
    int i;
    Speed=w.Speed;
    Life=w.Life;
    AmountPoint=w.AmountPoint;
    CurrentPoint=w.CurrentPoint;
    if(AmountPoint>0)
    {
        Road=new T_Point[AmountPoint];
        for(i=0;i<AmountPoint;i++)
        {
            Road[i]=w.Road[i];
        }
    }
    else
    {
        AmountPoint=0;
        Road=NULL;
    }
}
//---------------------------------------------------------------------------
T_Warrior::~T_Warrior()
{
    delete Road;
    Road=NULL;
    Speed=0;
    Life=0;
    AmountPoint=0;
    CurrentPoint=0;
}
//---------------------------------------------------------------------------
T_Warrior& T_Warrior::operator = (const T_Warrior &w)
{
    int i;
    if(this!=&w)
    {
        T_Object::operator = (w);
        Speed=w.Speed;
        Life=w.Life;
        AmountPoint=w.AmountPoint;
        CurrentPoint=w.CurrentPoint;
        Road=new T_Point[AmountPoint];
        for(i=0;i<AmountPoint;i++)
        {
            Road[i]=w.Road[i];
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
T_Gun::T_Gun(const T_Gun &g):T_Object(g)
{
    Attack=g.Attack;
    AttackPower=g.AttackPower;
    Power=g.Power;
    Radius=g.Radius;
}
//---------------------------------------------------------------------------
T_Gun::~T_Gun()
{
    Attack=0;
    AttackPower=0;
    Power=0;
    Radius=0;
}
//---------------------------------------------------------------------------
T_Gun& T_Gun::operator = (const T_Gun &g)
{
    if(this!=&g)
    {
        T_Object::operator = (g);
        Attack=g.Attack;
        AttackPower=g.AttackPower;
        Power=g.Power;
        Radius=g.Radius;
    }
    return *this;
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
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void T_Object::Draw(TCanvas *Canvas)const
{
    Draw(0,0,Canvas);
}
//---------------------------------------------------------------------------
void T_Warrior::Move(const int &Where)
{
    if(Speed>0)
    {
        switch(Where)
        {
            case GO_UP:
                XY.SetY(XY.GetY()-1.0/Speed);
                break;
            case GO_DOWN:
                XY.SetY(XY.GetY()+1.0/Speed);
                break;
            case GO_RIGHT:
                XY.SetX(XY.GetX()+1.0/Speed);
                break;
            case GO_LEFT:
                XY.SetX(XY.GetX()-1.0/Speed);
                break;
        }
        Status=Where;
    }
}
//---------------------------------------------------------------------------
T_Warrior::T_Warrior(const T_Point &p,const T_Animation &anim,const int &speed,const float &life):
    T_Object(p,anim)
{
    Speed=speed;
    AmountPoint=0;
    CurrentPoint=0;
    Road=NULL;
    Life=life;
}
//---------------------------------------------------------------------------
T_Gun::T_Gun(const T_Point &p,const T_Animation &anim,const int &power,const float &attack,const float &r):
    T_Object(p,anim)
{
    Attack=attack;
    AttackPower=power;
    Radius=r;
}
//---------------------------------------------------------------------------
void T_Gun::LoadPower()
{
    if(Power<AttackPower)
    {
        Power++;
    }
}
//---------------------------------------------------------------------------
T_Map::T_Map(const int &h,const int &w,const T_Animation &aCursor,const T_Animation &Map,
    const int &n,const int &life):
    Cursor(T_Point(0,0),aCursor,1,0),End(h-1,w-1),Begin(0,0)
{
    int i,j;
    int sw=0;
    Height=h;
    Width=w;
    if(Height<=0)
    {
        Height=1;
    }
    if(Width<=0)
    {
        Width=1;
    }
    BackGround=new Graphics::TBitmap();
    Buf=new Graphics::TBitmap();
    BackGround->Height=Height*SizePicture;
    BackGround->Width=Width*SizePicture;
    Buf->Height=(Height+2)*SizePicture;
    Buf->Width=(Width+2)*SizePicture;
    for(i=0;i<Height;i++)
    {
        for(j=0;j<Width;j++)
        {
            switch(sw)
            {
                case 0:
                    Map.Draw(0,TPoint(j*SizePicture,i*SizePicture),BackGround->Canvas);
                    break;
            }
        }
    }
    Gun=new T_Gun**[Height];
    for(i=0;i<Height;i++)
    {
        Gun[i]=new T_Gun*[Width];
        for(j=0;j<Width;j++)
        {
            Gun[i][j]=NULL;
        }
    }
    AmountWarrior=n;
    if(AmountWarrior<=0)
    {
        AmountWarrior=1;
    }
    Warrior=new T_Warrior*[AmountWarrior];
    for(i=0;i<AmountWarrior;i++)
    {
        Warrior[i]=NULL;
    }
    Interval=0;
    AddW=NULL;
    Life=life;
}
//---------------------------------------------------------------------------
void T_Map::Draw(const int &x,const int &y,TCanvas *Canvas)
{
    CreatePicture();
    Canvas->Draw(-Cursor.GetXY()->GetX()*SizePicture+x,
                 -Cursor.GetXY()->GetY()*SizePicture+y,this->Buf);
}
//---------------------------------------------------------------------------
void T_Map::CreatePicture()
{
    int i,j,n;
    char *sort;
    Buf->Canvas->Draw(SizePicture,SizePicture,this->BackGround);
    sort=SortY(n);
    for(i=0;i<n;i++)
    {
        Warrior[sort[i]]->Draw(SizePicture,SizePicture,Buf->Canvas);
    }
    delete sort;
    for(i=0;i<Height;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(Gun[i][j])
            {
                Gun[i][j]->Draw(SizePicture,0,Buf->Canvas);
            }
        }
    }
    Cursor.Draw(SizePicture,SizePicture,Buf->Canvas);
}
//---------------------------------------------------------------------------
void T_Map::Cursor_UP()
{
    if(Cursor.GetXY()->GetY()>0)
    {
        Cursor.GetXY()->SetY(Cursor.GetXY()->GetY()-1);
    }
}
//---------------------------------------------------------------------------
void T_Map::Cursor_DOWN()
{
    if(Cursor.GetXY()->GetY()<Height-1)
    {
        Cursor.GetXY()->SetY(Cursor.GetXY()->GetY()+1);
    }
}
//---------------------------------------------------------------------------
void T_Map::Cursor_LEFT()
{
    if(Cursor.GetXY()->GetX()>0)
    {
        Cursor.GetXY()->SetX(Cursor.GetXY()->GetX()-1);
    }
}
//---------------------------------------------------------------------------
void T_Map::Cursor_RIGHT()
{
    if(Cursor.GetXY()->GetX()<Width-1)
    {
        Cursor.GetXY()->SetX(Cursor.GetXY()->GetX()+1);
    }
}
//---------------------------------------------------------------------------
void T_Object::Draw(const int &x,const int &y,TCanvas *Canvas)const
{
    Anim.Draw(Status,TPoint(SizePicture*XY.GetX()+x,SizePicture*XY.GetY()+y),
        Canvas,clWhite);
}
//---------------------------------------------------------------------------
void T_Map::AddGun(const int &i,const int &j,const T_Gun &gun)
{
    if(Gun[i][j]==NULL)
    {
        Gun[i][j]=new T_Gun(gun);
        Gun[i][j]->GetXY()->SetX(j);
        Gun[i][j]->GetXY()->SetY(i);
    }
    else
    {
        delete Gun[i][j];
        Gun[i][j]=NULL;
    }
    NewRoad();
}
//---------------------------------------------------------------------------
void T_Map::AddGun(const T_Gun &gun)
{
    AddGun(Cursor.GetXY()->GetY(),Cursor.GetXY()->GetX(),gun);
}
//---------------------------------------------------------------------------
int T_Map::NextStep()
{
    int i,j,k;
    for(i=0;i<Height;i++)
    {
        for(j=0;j<Width;j++)
        {
            if(Gun[i][j])
            {
                for(k=0;k<AmountWarrior;k++)
                {
                    if(Gun[i][j]->doAttack(Warrior[k]))
                    {
                        break;
                    }
                }
                Gun[i][j]->LoadPower();
            }
        }
    }
    for(i=0;i<AmountWarrior;i++)
    {
        if(Warrior[i])
        {
            if(Warrior[i]->Move(*this)==0)
            {
                Life--;
                delete Warrior[i];
                Warrior[i]=NULL;
            }
        }
    }
    if(AddW)
    {
        AddWarrior();
    }
    //CheckRoad();
    return Life;
}
//---------------------------------------------------------------------------
bool T_Gun::doAttack(T_Warrior *&w)
{
    if(Power<AttackPower)
    {
        Status=STAND;
        return false;
    }
    if(!w)
    {
        return false;
    }
    if(XY.Distance(*w->GetXY())<=Radius)
    {
        Power=0;
        w->Life-=Attack;
        Status=SHOOT;
        if(w->Life<=0)
        {
            delete w;
            w=NULL;
        }
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
int T_Map::AddWarrior()
{
    if(!AddW)
    {
        return 0;
    }
    if(Interval<In)
    {
        Interval++;
        return -1;
    }
    if(caw>=AmountWarrior)
    {
        delete AddW;
        AddW=NULL;
        In=0;
    }
    else
    {
        Interval=0;
        Warrior[caw]=new T_Warrior(*AddW);
        caw++;
        return 1;
    }
    return 0;
}
//---------------------------------------------------------------------------
int T_Warrior::Move(const T_Map &Map)
{
    T_Vector dxy(XY);
    if(!Road && !(NewRoad(Map)))
    {
        return 0;
    }
    if(XY.Distance(Road[CurrentPoint])<=1.0/Speed)
    {
        CurrentPoint++;
        if(CurrentPoint>=AmountPoint)
        {
            delete[] Road;
            Road=NULL;
            AmountPoint=0;
            CurrentPoint=0;
            return 0;
        }
    }
    dxy=dxy-Road[CurrentPoint];
    dxy.SetLength(-1.0/Speed);
    if(fabs(dxy.GetX())>fabs(dxy.GetY()))
    {
        if(dxy.GetX()>0)
        {
            Status=GO_RIGHT;
        }
        else
        {
            Status=GO_LEFT;
        }
    }
    else
    {
        if(dxy.GetY()>0)
        {
            Status=GO_DOWN;
        }
        else
        {
            Status=GO_UP;
        }
    }
    XY=dxy+XY;
    return 1;
}
//---------------------------------------------------------------------------
T_Point* T_Map::CreateRoad(const T_Point &b,int &n)const
{
    T_Point *p=NULL;
    int i,j,k;
    int **M=new int*[Height];
    for(i=0;i<Height;i++)
    {
        M[i]=new int[Width];
        for(j=0;j<Width;j++)
        {
            if(Gun[i][j])
            {
                M[i][j]=-1;
            }
            else
            {
                M[i][j]=0;
            }
        }
    }
    i=b.GetY();
    j=b.GetX();
    M[i][j]=1;
    CreateRoadNext(i,j,M,1);
    i=Height-1;
    j=Width-1;
    n=M[i][j];
    if(n>0)
    {
        p=new T_Point[n];
        GetPoints(p,i,j,M);
    }
    else
    {
        n=0;
        p=NULL;
    }
    for(i=0;i<Height;i++)
    {
        delete M[i];
    }
    delete M;
    M=NULL;
    return p;
}
//---------------------------------------------------------------------------
void T_Map::AddWarrior(const T_Warrior &w,const int &in)
{
    In=in;
    if(!AddW)
    {
        AddW=new T_Warrior(w);
        caw=0;
    }
}
//---------------------------------------------------------------------------
void T_Map::GetPoints(T_Point *p,int i,int j,int **M)const
{
    p[M[i][j]-1]=T_Point(j,i);
    if(M[i][j]<=1)
    {
        return;
    }
    if(j+1<Width && M[i][j+1]==M[i][j]-1)
    {
        return GetPoints(p,i,j+1,M);
    }
    if(i+1<Height && M[i+1][j]==M[i][j]-1)
    {
        return GetPoints(p,i+1,j,M);
    }
    if(j-1>=0 && M[i][j-1]==M[i][j]-1)
    {
        return GetPoints(p,i,j-1,M);
    }
    if(i-1>=0 && M[i-1][j]==M[i][j]-1)
    {
        return GetPoints(p,i-1,j,M);
    }
}
//---------------------------------------------------------------------------
void T_Map::CreateRoadNext(const int &i,const int &j,int **M,int &b)const
{
    if(b>0 && i>=0 && i<Height && j>=0 && j<Width && M[i][j]>=0)
    {
        b=0;
        if(j+1<Width)
        {
            if(M[i][j+1]==0 || M[i][j]<=M[i][j+1])
            {
                if(M[i][j+1]!=M[i][j]+1)
                {
                    M[i][j+1]=M[i][j]+1;
                    b++;
                    CreateRoadNext(i,j+1,M,b);
                }
            }
        }
        if(i+1<Height)
        {
            if(M[i+1][j]==0 || M[i][j]<=M[i+1][j])
            {
                if(M[i+1][j]!=M[i][j]+1)
                {
                    M[i+1][j]=M[i][j]+1;
                    b++;
                    CreateRoadNext(i+1,j,M,b);
                }
            }
        }
        if(j-1>=0)
        {
            if(M[i][j-1]==0 || M[i][j]<=M[i][j-1])
            {
                if(M[i][j-1]!=M[i][j]+1)
                {
                    M[i][j-1]=M[i][j]+1;
                    b++;
                    CreateRoadNext(i,j-1,M,b);
                }
            }
        }
        if(i-1>=0)
        {
            if(M[i-1][j]==0 || M[i][j]<=M[i-1][j])
            {
                if(M[i-1][j]!=M[i][j]+1)
                {
                    M[i-1][j]=M[i][j]+1;
                    b++;
                    CreateRoadNext(i-1,j,M,b);
                }
            }
        }
    }
}
//---------------------------------------------------------------------------
T_Point* T_Warrior::NewRoad(const T_Map &Map)
{
    delete[] Road;
    Road=NULL;
    Road=Map.CreateRoad(XY,AmountPoint);
    CurrentPoint=0;
    return Road;
}
//---------------------------------------------------------------------------
void T_Map::NewRoad()
{
    int i;
    for(i=0;i<AmountWarrior;i++)
    {
        if(Warrior[i])
        {
            Warrior[i]->NewRoad(*this);
        }
    }
}
//---------------------------------------------------------------------------
void T_Map::ShowRoad(char *fname)
{
    T_Gun road();
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
char* T_Map::SortY(int &s)
{
    int i,j,r;
    char *sort=new char[AmountWarrior];
    s=0;
    i=0;
    while(i<AmountWarrior && Warrior[i]==NULL)
    {
        i++;
    }
    if(i<AmountWarrior)
    {
        sort[s]=i;
        s++;
        i++;
        for(;i<AmountWarrior;i++)
        {
            if(Warrior[i])
            {
                j=0;
                while(j<s && Warrior[i]->GetXY()->GetY()>Warrior[sort[j]]->GetXY()->GetY())
                {
                    j++;
                }
                if(j>=s)
                {
                    sort[s]=i;
                    s++;
                }
                else
                {
                    for(r=AmountWarrior-1;r>j;r--)
                    {
                        sort[r]=sort[r-1];
                    }
                    sort[r]=i;
                    s++;
                }
            }
        }
    }
    return sort;
}
//---------------------------------------------------------------------------
float T_Warrior::GetLengthRoad()
{
    int i;
    float s=0;
    for(i=0;i<AmountPoint-1;i++)
    {
        s+=Road[i].Distance(Road[i+1]);
    }
    return s;
}
//---------------------------------------------------------------------------
int T_Map::GetAmountWarrior()
{
    int i,n=0;
    for(i=0;i<AmountWarrior;i++)
    {
        if(Warrior[i])
        {
            n++;
        }
    }
    if(n==0)
    {
        if(AddW)
        {
            n=1;
        }
    }
    return n;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

