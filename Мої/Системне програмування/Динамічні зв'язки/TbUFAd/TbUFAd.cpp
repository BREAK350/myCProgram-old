//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbUFAd.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbUFAdLink::TbUFAdLink(const String &Symbols,TbUFAdState *State)
    :Symbols(Symbols)
{
    this->State=State;
    Distance=0;
}
//---------------------------------------------------------------------------
TbUFAdFinalState::TbUFAdFinalState(TbUFAdState *State)
{
    this->State=State;
}
//---------------------------------------------------------------------------
TbUFAdState::TbUFAdState(const int &Number,const TbVector2d &Location)
    :Location(Location),LocationFuture(Location),Center(Location)
{
    this->Number=Number;
}
//---------------------------------------------------------------------------
TbUFAdState::TbUFAdState(const int &Number,const TbVector2d &Location,
    const TbVector2d &LocationFuture)
    :Location(Location),LocationFuture(LocationFuture),Center(Location)
{
    this->Number=Number;
}
//---------------------------------------------------------------------------
TbUFAdState::TbUFAdState(const int &Number,const TbVector2d &Location,
    const TbVector2d &LocationFuture,const TbVector2d &Center)
    :Location(Location),LocationFuture(LocationFuture),Center(Center)
{
    this->Number=Number;
}
//---------------------------------------------------------------------------
bool TbUFAdLink::Draw(TCanvas *Canvas,TbUFAdState *Begin,const TbVector2d &Center)
{
    bool Execute=false;
    TbVector2d Edge=State->Location-Begin->Location;
    if(State->Number!=Begin->Number)
    {
        if(Distance+Speed<Edge.GetLength())
        {
            Distance+=Speed;
            Execute=true;
        }
        else
        {
            Distance=Edge.GetLength();
        }
        if(Distance-Radius>0)
        {
            Edge.SetLength(Distance-Radius);
            Begin->Location.MoveTo(Canvas);
            (Begin->Location+Edge).LineTo(Canvas);
            TbVector2d v=Edge;
            v.Reverse();
            v.SetLength(10);
            v.Rotate(30*M_PI/180);
            (Begin->Location+Edge).MoveTo(Canvas);
            (Begin->Location+Edge+v).LineTo(Canvas);
            v.Rotate(-60*M_PI/180);
            (Begin->Location+Edge).MoveTo(Canvas);
            (Begin->Location+Edge+v).LineTo(Canvas);
        }
    }
    else
    {   // петля
        if((Begin->Location-Center).GetSquareLength()>1)
        {
            Edge=Begin->Location-Center;
        }
        else
        {
            Edge.Init(0,-100);
        }
        Edge.SetLength(4*Radius);
        Edge.Rotate(30*M_PI/180);
        Begin->Location.MoveTo(Canvas);
        (Begin->Location+Edge).LineTo(Canvas);
        TbVector2d b=Edge;
        b.Rotate(-120*M_PI/180);
        (Begin->Location+Edge).MoveTo(Canvas);
        (Begin->Location+Edge+b).LineTo(Canvas);
        b.SetLength(2*Radius);
        TbVector2d v=Begin->Location+Edge+b;
        Canvas->TextOutA(v.X-Canvas->TextWidth(Symbols)/2,
                         v.Y-Canvas->TextHeight(Symbols)/2,Symbols);
        Edge.Rotate(-60*M_PI/180);
        (Begin->Location+Edge).MoveTo(Canvas);
        Edge.SetLength(Radius);
        (Begin->Location+Edge).LineTo(Canvas);

        v=Edge;
        v.SetLength(10);
        v.Rotate(30*M_PI/180);
        (Begin->Location+Edge).MoveTo(Canvas);
        (Begin->Location+Edge+v).LineTo(Canvas);
        v.Rotate(-60*M_PI/180);
        (Begin->Location+Edge).MoveTo(Canvas);
        (Begin->Location+Edge+v).LineTo(Canvas);

    }
    return Execute;
}
//---------------------------------------------------------------------------
int TbUFAdState::Draw(TCanvas *Canvas)
{
    int Execute=0;
    TbList2Iterator <TbUFAdLink> i(Links);
    while(i.Correct())
    {
        Execute+=i.Get().Draw(Canvas,this,Center);
        i.SetNext();
    }
    if(Location!=LocationFuture)
    {
        TbVector2d Road=LocationFuture-Location;
        if(Road.GetLength()>=Speed)
        {
            Road.SetLength(Speed);
            Location=Location+Road;
        }
        else
        {
            Location=LocationFuture;
        }
        if(Road.GetLength()>0)
        {
            Execute++;
        }
    }
    Canvas->Ellipse(Location.X-Radius,Location.Y-Radius,Location.X+Radius,Location.Y+Radius);
    Canvas->TextOutA(Location.X-Canvas->TextWidth(Number)/2,
        Location.Y-Canvas->TextHeight(Number)/2,Number);
    return Execute;
}
//---------------------------------------------------------------------------
void TbUFAdState::WriteName(TCanvas *Canvas)
{
    TbList2Iterator <TbUFAdLink> i(Links);
    while(i.Correct())
    {
        i.Get().WriteName(Canvas,this);
        i.SetNext();
    }
}
//---------------------------------------------------------------------------
void TbUFAdLink::WriteName(TCanvas *Canvas,TbUFAdState *Begin)
{
    if(Distance>2*Canvas->TextHeight(Symbols))
    {
        TbVector2d v=State->Location-Begin->Location;
        v.SetLength(Distance/4.0);
        v=v+Begin->Location;
        Canvas->TextOutA(v.X-Canvas->TextWidth(Symbols)/2,
                         v.Y-Canvas->TextHeight(Symbols)/2,Symbols);
    }
}
//---------------------------------------------------------------------------
TbUFAd::TbUFAd(TCanvas *Canvas)
{
    this->Canvas=Canvas;
}
//---------------------------------------------------------------------------
TbUFAd::TbUFAd(const char *Expression)
{
}
//---------------------------------------------------------------------------
TbUFAd TbUFAd::CreateSimpleAutomaton(const char *Expression,int &Number,TCanvas *Canvas)
{
    TbUFAd SimpleAutomaton(Canvas);
    if(Expression)
    {
        SimpleAutomaton.AllStates.Add(TbUFAdState(Number,BEGIN));
        Number++;

        LocatePointOnCircle(CENTER,SimpleAutomaton.AllStates,MinDistance);
        SimpleAutomaton.Center=CENTER;
        SimpleAutomaton.Draw();

        TbUFAdState *p=NULL;
        if(Expression[0])
        {
            int i=0;
            while(Expression[i])
            {
                if(Expression[i]!='e')
                {
                    SimpleAutomaton.AllStates.Add(TbUFAdState(Number,BEGIN));
                    Number++;
                    SimpleAutomaton.AllStates.CurrSetLast();
                    p=&SimpleAutomaton.AllStates.GetCurr();
                    SimpleAutomaton.AllStates.CurrSetPrev();
                    SimpleAutomaton.AllStates.GetCurr().Links.Add(TbUFAdLink(Expression[i],p));

                    LocatePointOnCircle(CENTER,SimpleAutomaton.AllStates,MinDistance);
                    SimpleAutomaton.Draw();
                }
                i++;
            }
        }
        SimpleAutomaton.AllStates.CurrSetLast();
        p=&SimpleAutomaton.AllStates.GetCurr();
        SimpleAutomaton.FinalStates.Add(TbUFAdFinalState(p));
        SimpleAutomaton.Draw();
    }
    return SimpleAutomaton;
}
//---------------------------------------------------------------------------
TbUFAd::TbUFAd(const TbUFAd &UFAd)
{
    if(UFAd.AllStates.GetCount()>0)
    {
        Canvas=UFAd.Canvas;
        TbList2Iterator <TbUFAdState> st(UFAd.AllStates);
        st.SetFirst();
        while(st.Correct())
        {
            AllStates.Add(TbUFAdState(st.Get().Number,BEGIN));
            st.SetNext();
        }

        st.SetFirst();
        AllStates.CurrSetFirst();
        while(st.Correct())
        {
            if(st.Get().Links.GetCount()>0)
            {
                TbList2Iterator <TbUFAdLink> link(st.Get().Links);
                while(link.Correct())
                {
                    AllStates.GetCurr().Links.Add(
                        TbUFAdLink(link.Get().Symbols,
                        SearchByName(link.Get().State->Number)));
                    link.SetNext();
                }
            }
            st.SetNext();
            AllStates.CurrSetNext();
        }
        TbList2Iterator <TbUFAdFinalState> fst(UFAd.FinalStates);
        while(fst.Correct())
        {
            FinalStates.Add(TbUFAdFinalState(
                SearchByName(fst.Get().State->Number)));
            fst.SetNext();
        }
    }
}
//---------------------------------------------------------------------------
TbUFAd::~TbUFAd()
{
    TbList2Iterator <TbUFAdState> i_st(AllStates);
    while(i_st.Correct())
    {
        i_st.Get().Links.DeleteAll();
        i_st.SetNext();
    }
    AllStates.DeleteAll();
    FinalStates.DeleteAll();
}
//---------------------------------------------------------------------------
TbUFAd& TbUFAd::operator = (const TbUFAd &UFAd)
{
    if(this!=&UFAd)
    {
        Canvas=UFAd.Canvas;
        TbList2Iterator <TbUFAdState> i_st(AllStates);
        while(i_st.Correct())
        {
            i_st.Get().Links.DeleteAll();
            i_st.SetNext();
        }
        AllStates.DeleteAll();
        FinalStates.DeleteAll();

        if(UFAd.AllStates.GetCount()>0)
        {
            TbList2Iterator <TbUFAdState> st(UFAd.AllStates);
            st.SetFirst();
            while(st.Correct())
            {
                AllStates.Add(TbUFAdState(st.Get().Number,BEGIN));
                st.SetNext();
            }

            st.SetFirst();
            AllStates.CurrSetFirst();
            while(st.Correct())
            {
                if(st.Get().Links.GetCount()>0)
                {
                    TbList2Iterator <TbUFAdLink> link(st.Get().Links);
                    while(link.Correct())
                    {
                        AllStates.GetCurr().Links.Add(
                            TbUFAdLink(link.Get().Symbols,
                            SearchByName(link.Get().State->Number)));
                        link.SetNext();
                    }
                }
                st.SetNext();
                AllStates.CurrSetNext();
            }
            TbList2Iterator <TbUFAdFinalState> fst(UFAd.FinalStates);
            while(fst.Correct())
            {
                FinalStates.Add(TbUFAdFinalState(
                    SearchByName(fst.Get().State->Number)));
                fst.SetNext();
            }
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TbUFAdState* TbUFAd::SearchByName(const int &Number)const
{
    TbList2Iterator <TbUFAdState> st(AllStates);
    while(st.Correct() && st.Get().Number!=Number)
    {
        st.SetNext();
    }
    return (st.Correct())?(&st.Get()):(NULL);
}
//---------------------------------------------------------------------------
void TbUFAd::print()const
{
	/*TbList2Iterator <TbUFAdState> st(AllStates);
    while(st.Correct())
    {
        cout<<'['<<st.Get().Number<<']';
        TbList2Iterator <TbUFAdLink> link(st.Get().Links);
        while(link.Correct())
        {
            cout<<"-"<<link.Get().Symbols<<"->["
                     <<link.Get().State->Number<<"];";
            link.SetNext();
        }
        cout<<endl;
        st.SetNext();
    }
    cout<<"Final state: ";
    TbList2Iterator <TbUFAdFinalState> fst(FinalStates);
    while(fst.Correct())
    {
        cout<<"["<<fst.Get().State->Number<<"]";
        fst.SetNext();   
    }
    cout<<endl;*/
}
//---------------------------------------------------------------------------
void TbUFAd::Draw()
{
    int Execute=0;
    do
    {
        Canvas->Rectangle(0,0,1300,700);
        Execute=0;
        TbList2Iterator <TbUFAdFinalState> i_fst(FinalStates);
        while(i_fst.Correct())
        {
            TbVector2d Location=i_fst.Get().State->Location;
            Canvas->Ellipse(Location.X-Radius*1.25,Location.Y-Radius*1.25,
                            Location.X+Radius*1.25,Location.Y+Radius*1.25);
            i_fst.SetNext();
        }
        TbList2Iterator <TbUFAdState> i_st(AllStates);
        Canvas->Brush->Color=clYellow;
        Execute+=i_st.Get().Draw(Canvas);
        i_st.SetNext();
        Canvas->Brush->Color=clWhite;
        while(i_st.Correct())
        {
            Execute+=i_st.Get().Draw(Canvas);
            i_st.SetNext();
        }
        i_st.SetFirst();
        while(i_st.Correct())
        {
            i_st.Get().WriteName(Canvas);
            i_st.SetNext();
        }
        FormAnimation->Canvas->Draw(0,0,bmp);
        Sleep(Interval);
    }
    while(Execute>0);
}
//---------------------------------------------------------------------------
void TbUFAd::LocatePointOnCircle(const TbVector2d &Center,TbList2 <TbUFAdState> &L,
    const double &MinDistance)
{
    if(L.GetCount()>1)
    {
        double Angle=360.0/L.GetCount();
        TbVector2d v(0,100);
        v.SetLength(MinDistance/(2*sin(M_PI/L.GetCount())));
        TbList2Iterator <TbUFAdState> i(L);
        while(i.Correct())
        {
            i.Get().LocationFuture=v+Center;
            i.Get().Center=Center;
            v.Rotate(Angle*M_PI/180);
            i.SetNext();
        }
    }
    else
    {
        if(L.GetCount()==1)
        {
            TbList2Iterator <TbUFAdState> i(L);
            i.Get().LocationFuture=Center;
            i.Get().Center=Center;
        }
    }
}
//---------------------------------------------------------------------------
String Union(const String &s1,const String &s2)
{
    String res=s1;
    for(int i=0;i<s2.Length();i++)
    {
        int j=0;
        while(j<res.Length() && s2[i+1]!=res[j+1])
        {
            j++;
        }
        if(j>=res.Length())
        {
            res=res+s2[i+1];
        }
    }
    return res;
}
//---------------------------------------------------------------------------
void TbUFAd::AddLink(TbList2 <TbUFAdLink> &Links,const String &Symbols,const int &Number)
{
    TbList2Iterator <TbUFAdLink> link(Links);
    while(link.Correct() && link.Get().State->Number!=Number)
    {
        link.SetNext();
    }
    if(link.Correct())
    {
        link.Get().Symbols=Union(link.Get().Symbols,Symbols);
    }
    else
    {
        Links.Add(TbUFAdLink(Symbols,SearchByName(Number)));
    }
}
//---------------------------------------------------------------------------
TbUFAd TbUFAd::Iteration(int &Number)const
{
    TbUFAd UFA(*this);

    LocatePointOnCircle(CENTER,UFA.AllStates,MinDistance);
    UFA.Center=CENTER;
    UFA.Draw();

    UFA.AllStates.AddFirst(TbUFAdState(Number,BEGIN));
    Number++;
    TbList2Iterator <TbUFAdState> st(UFA.AllStates);
    st.SetNext();
    TbList2Iterator <TbUFAdLink> link(st.Get().Links);
    UFA.AllStates.CurrSetFirst();
    if(st.Get().Links.GetCount()>0)
    {
        while(link.Correct())
        {
            UFA.AddLink(UFA.AllStates.GetCurr().Links,link.Get().Symbols,
                link.Get().State->Number);
            link.SetNext();
        }
    }
    LocatePointOnCircle(CENTER,UFA.AllStates,MinDistance);
    UFA.Center=CENTER;
    UFA.Draw();
    TbList2Iterator <TbUFAdFinalState> fst(UFA.FinalStates);
    while(fst.Correct())
    {
        link.SetFirst();
        while(link.Correct())
        {
            UFA.AddLink(fst.Get().State->Links,link.Get().Symbols,link.Get().State->Number);
            link.SetNext();
        }
        fst.SetNext();
    }
    UFA.AllStates.CurrSetFirst();
    UFA.FinalStates.Add(TbUFAdFinalState(&UFA.AllStates.GetCurr()));
    UFA.Draw();
    return UFA;
}
//---------------------------------------------------------------------------
TbUFAd TbUFAd::Alternative(const TbUFAd &UFA,int &Number)const
{
    TbUFAd Left(*this),Right(UFA);
    LocatePointOnCircle(LEFT,Left.AllStates,MinDistance);

    LocatePointOnCircle(RIGHT,Right.AllStates,MinDistance);

    TbList2Iterator <TbUFAdState> rst(Right.AllStates);
    TbList2Iterator <TbUFAdState> lst(Left.AllStates);
    lst.SetLast();
    rst.SetFirst();
    while(rst.Correct())
    {
        Left.AllStates.Add(TbUFAdState(rst.Get().Number,BEGIN,
            rst.Get().LocationFuture,rst.Get().Center));
        rst.SetNext();
    }

    rst.SetFirst();
    lst.SetNext();
    while(rst.Correct())
    {
        if(rst.Get().Links.GetCount()>0)
        {
            TbList2Iterator <TbUFAdLink> link(rst.Get().Links);
            while(link.Correct())
            {
                Left.AddLink(lst.Get().Links,link.Get().Symbols,
                    link.Get().State->Number);
                link.SetNext();
            }
        }
        rst.SetNext();
        lst.SetNext();
    }
    TbList2Iterator <TbUFAdFinalState> fst(Right.FinalStates);
    while(fst.Correct())
    {
        Left.FinalStates.Add(TbUFAdFinalState(
            Left.SearchByName(fst.Get().State->Number)));
        fst.SetNext();
    }

    Left.Draw();

    Left.AllStates.AddFirst(TbUFAdState(Number,BEGIN,CENTER));
    Number++;
    Left.Draw();

    lst.SetFirst();
    lst.SetNext();
    rst.SetFirst();
    Left.AllStates.CurrSetFirst();
    bool RightFirstIsEndl=false;
    TbList2Iterator <TbUFAdLink> rlink(rst.Get().Links);
    while(rlink.Correct())
    {
        Left.AddLink(Left.AllStates.GetCurr().Links,rlink.Get().Symbols,
            rlink.Get().State->Number);
        if(rst.Get().Number==rlink.Get().State->Number)
        {
            RightFirstIsEndl=true;
        }
        rlink.SetNext();
    }
    TbList2Iterator <TbUFAdLink> llink(lst.Get().Links);
    while(llink.Correct())
    {
        Left.AddLink(Left.AllStates.GetCurr().Links,llink.Get().Symbols,
            llink.Get().State->Number);
        if(lst.Get().Number==llink.Get().State->Number)
        {
            RightFirstIsEndl=true;
        }
        llink.SetNext();
    }
    if(RightFirstIsEndl)
    {
        Left.AllStates.CurrSetFirst();
        Left.FinalStates.Add(TbUFAdFinalState(&Left.AllStates.GetCurr()));
    }

    Left.Draw();
    LocatePointOnCircle(CENTER,Left.AllStates,MinDistance);
    Left.Center=CENTER;
    Left.Draw();
    return Left;
}
//---------------------------------------------------------------------------
TbUFAd TbUFAd::Concatenation(const TbUFAd &UFA,int &Number)const
{
    TbUFAd Left(*this),Right(UFA);
    LocatePointOnCircle(LEFT,Left.AllStates,MinDistance);

    LocatePointOnCircle(RIGHT,Right.AllStates,MinDistance);

    TbList2Iterator <TbUFAdState> rst(Right.AllStates);
    TbList2Iterator <TbUFAdState> lst(Left.AllStates);
    lst.SetLast();
    rst.SetFirst();
    while(rst.Correct())
    {
        Left.AllStates.Add(TbUFAdState(rst.Get().Number,BEGIN,
            rst.Get().LocationFuture,rst.Get().Center));
        rst.SetNext();
    }

    rst.SetFirst();
    lst.SetNext();
    while(rst.Correct())
    {
        if(rst.Get().Links.GetCount()>0)
        {
            TbList2Iterator <TbUFAdLink> link(rst.Get().Links);
            while(link.Correct())
            {
                Left.AddLink(lst.Get().Links,link.Get().Symbols,
                    link.Get().State->Number);
                link.SetNext();
            }
        }
        rst.SetNext();
        lst.SetNext();
    }

    Left.Draw();
    TbList2Iterator <TbUFAdFinalState> lfst(Left.FinalStates);
    rst.SetFirst();
    while(lfst.Correct())
    {
        TbList2Iterator <TbUFAdLink> rlink(rst.Get().Links);
        while(rlink.Correct())
        {
            Left.AddLink(lfst.Get().State->Links,rlink.Get().Symbols,
                rlink.Get().State->Number);
            rlink.SetNext();
        }
        lfst.SetNext();
    }

    bool RightFirstIsEndl=false;
    Right.AllStates.CurrSetFirst();

    TbList2Iterator <TbUFAdFinalState> fst(Right.FinalStates);
    while(fst.Correct())
    {
        if(Right.AllStates.GetCurr().Number==fst.Get().State->Number)
        {
            RightFirstIsEndl=true;
        }
        fst.SetNext();
    }
    if(RightFirstIsEndl==false)
    {
        Left.FinalStates.DeleteAll();
    }
    fst.SetFirst();
    while(fst.Correct())
    {
        Left.FinalStates.Add(TbUFAdFinalState(
            Left.SearchByName(fst.Get().State->Number)));
        fst.SetNext();
    }

    Left.Draw();
    LocatePointOnCircle(CENTER,Left.AllStates,MinDistance);
    Left.Center=CENTER;
    Left.Draw();
    return Left;
}
//---------------------------------------------------------------------------
void TbUFAd::Create(const char *Expression,TCanvas *Canvas,int &Number)
{
    *this=Create(Expression,0,strlen(Expression),Canvas,Number);
}
//---------------------------------------------------------------------------
void WriteRegularExpression(const int &iBegin,const int &iEnd)
{
    FormAnimation->EditRegularExpression->SelStart=iBegin;
    FormAnimation->EditRegularExpression->SelLength=iEnd-iBegin;
}
//---------------------------------------------------------------------------
TbUFAd TbUFAd::Create(const char *Expression,const int &iBegin,const int &iEnd,
    TCanvas *Canvas,int &Number)const
{
    TbUFAd res(Canvas);
    int i=iBegin,d=0;
    if(iBegin>=iEnd)
    {
        WriteRegularExpression(iBegin,iEnd);
        res=CreateSimpleAutomaton("",Number,Canvas);
        Sleep(IntervalEndOperation);
    }
    else
    {
        while(i<iEnd && (Expression[i]!='|' || d>0))
        {
            if(Expression[i]=='(')
            {
                d++;
            }
            else
            if(Expression[i]==')')
            {
                d--;
            }
            i++;
        }
        if(i<iEnd)
        {
            WriteRegularExpression(iBegin,iEnd);
            res=Create(Expression,iBegin,i,Canvas,Number);
            Sleep(IntervalEndOperation);
            WriteRegularExpression(iBegin,iEnd);
            TbUFAd Right=Create(Expression,i+1,iEnd,Canvas,Number);
            Sleep(IntervalEndOperation);
            WriteRegularExpression(iBegin,iEnd);
            res=res.Alternative(Right,Number);
            Sleep(IntervalEndOperation);
        }
        else
        {
            i=iBegin;
            if(Expression[iBegin]=='(')
            {
                d=1;
                i++;
                while(i<iEnd && d>0)
                {
                    if(Expression[i]=='(')
                    {
                        d++;
                    }
                    else
                    if(Expression[i]==')')
                    {
                        d--;
                    }
                    i++;
                }
                int r=i-1; // закрита дужка
                while(i<iEnd && Expression[i]=='*')
                {
                    i++;
                }
                WriteRegularExpression(iBegin,iEnd);
                res=Create(Expression,iBegin+1,r,Canvas,Number);
                Sleep(IntervalEndOperation);
                if(r!=i-1)
                {
                    WriteRegularExpression(iBegin,iEnd);
                    res=res.Iteration(Number);
                    Sleep(IntervalEndOperation);
                }
                if(i<iEnd)
                {
                    WriteRegularExpression(iBegin,iEnd);
                    res=res.Concatenation(Create(Expression,i,iEnd,Canvas,Number),Number);
                    Sleep(IntervalEndOperation);
                }
            }
            else
            {
                while(i<iEnd && Expression[i]!='(')
                {
                    i++;
                }
                if(i<iEnd)
                {
                    WriteRegularExpression(iBegin,iEnd);
                    res=Create(Expression,iBegin,i,Canvas,Number);
                    Sleep(IntervalEndOperation);
                    WriteRegularExpression(iBegin,iEnd);
                    TbUFAd Right=Create(Expression,i,iEnd,Canvas,Number);
                    Sleep(IntervalEndOperation);
                    WriteRegularExpression(iBegin,iEnd);
                    res=res.Concatenation(Right,Number);
                    Sleep(IntervalEndOperation);
                }
                else
                {
                    i=iBegin;
                    while(i<iEnd && Expression[i]!='*')
                    {
                        i++;
                    }
                    if(i<iEnd)
                    {
                        if(i-iBegin>1)
                        {
                            char *str=new char [i-iBegin];
                            strncpy(str,&Expression[iBegin],i-iBegin-1);
                            str[i-iBegin-1]=0;
                            WriteRegularExpression(iBegin,iEnd);
                            res=CreateSimpleAutomaton(str,Number,Canvas);
                            Sleep(IntervalEndOperation);
                            str[0]=Expression[i-1];
                            str[1]=0;
                            if(str[0]!='e')
                            {
                                TbUFAd buf(Canvas);
                                WriteRegularExpression(iBegin,iEnd);
                                buf=CreateSimpleAutomaton(str,Number,Canvas);
                                Sleep(IntervalEndOperation);
                                WriteRegularExpression(iBegin,iEnd);
                                buf=buf.Iteration(Number);
                                Sleep(IntervalEndOperation);
                                WriteRegularExpression(iBegin,iEnd);
                                res=res.Concatenation(buf,Number);
                                Sleep(IntervalEndOperation);
                            }
                            WriteRegularExpression(iBegin,iEnd);
                            TbUFAd Right=Create(Expression,i+1,iEnd,Canvas,Number);
                            Sleep(IntervalEndOperation);
                            WriteRegularExpression(iBegin,iEnd);
                            res=res.Concatenation(Right,Number);
                            Sleep(IntervalEndOperation);
                            delete str;
                        }
                        else
                        {
                            char str[2];
                            str[0]=Expression[i-1];
                            str[1]=0;
                            if(str[0]!='e')
                            {
                                WriteRegularExpression(iBegin,iEnd);
                                res=CreateSimpleAutomaton(str,Number,Canvas);
                                Sleep(IntervalEndOperation);
                                WriteRegularExpression(iBegin,iEnd);
                                res=res.Iteration(Number);
                                Sleep(IntervalEndOperation);
                            }
                            else
                            {
                                WriteRegularExpression(iBegin,iEnd);
                                res=CreateSimpleAutomaton("",Number,Canvas);
                                Sleep(IntervalEndOperation);
                            }
                            WriteRegularExpression(iBegin,iEnd);
                            res=res.Concatenation(Create(Expression,i+1,iEnd,Canvas,Number),Number);
                            Sleep(IntervalEndOperation);
                        }
                    }
                    else
                    {
                        char *str=new char [iEnd-iBegin+1];
                        strncpy(str,&Expression[iBegin],iEnd-iBegin);
                        str[iEnd-iBegin]=0;
                        WriteRegularExpression(iBegin,iEnd);
                        if(iEnd-iBegin==1 && str[0]=='e')
                        {
                            res=CreateSimpleAutomaton("",Number,Canvas);
                        }
                        else
                        {
                            res=CreateSimpleAutomaton(str,Number,Canvas);
                        }
                        Sleep(IntervalEndOperation);
                        delete str;
                    }
                }
            }
        }
    }
    return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 