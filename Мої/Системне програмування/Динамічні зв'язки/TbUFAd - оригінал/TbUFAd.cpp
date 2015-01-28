//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbUFAd.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbUFAd::TbUFAd()
{
    AllStates=NULL;
    FinalStates=NULL;
}
//---------------------------------------------------------------------------
TbUFAd::TbUFAd(const char *Expression)
{
    AllStates=NULL;
    FinalStates=NULL;
}
//---------------------------------------------------------------------------
TbUFAd TbUFAd::CreateSimpleAutomaton(const char *Expression,int &Name)
{
    TbUFAd SimpleAutomaton;
    if(Expression)
    {
        SimpleAutomaton.AllStates=new TbUFAdState;
        SimpleAutomaton.AllStates->Prev=NULL;
        SimpleAutomaton.AllStates->Next=NULL;
        SimpleAutomaton.AllStates->Links=NULL;
        SimpleAutomaton.AllStates->Name=Name;
        Name++;
        TbUFAdState *p=SimpleAutomaton.AllStates;
        if(Expression[0])
        {
            int i=0;
            while(Expression[i])
            {
                if(Expression[i]!='e')
                {
                    p->Next=new TbUFAdState;
                    p->Next->Prev=p;
                    p->Next->Next=NULL;
                    p->Next->Links=NULL;
                    p->Next->Name=Name;
                    Name++;
                    p->Links=new TbUFAdLink;
                    p->Links->Next=NULL;
                    p->Links->Prev=NULL;
                    p->Links->Symbol=Expression[i];
                    p->Links->State=p->Next;
                    p=p->Next;
                }
                i++;
            }
        }
        if(p==NULL)
        {
            p=SimpleAutomaton.AllStates;
        }
        SimpleAutomaton.FinalStates=new TbUFAdFinalState;
        SimpleAutomaton.FinalStates->Next=NULL;
        SimpleAutomaton.FinalStates->Prev=NULL;
        SimpleAutomaton.FinalStates->State=p;
    }
    return SimpleAutomaton;
}
//---------------------------------------------------------------------------
TbUFAd::TbUFAd(const TbUFAd &UFAd)
{
    if(UFAd.AllStates==NULL)
    {
        AllStates=NULL;
        FinalStates=NULL;
    }
    else
    {
        AllStates=new TbUFAdState;
        TbUFAdState *pState=UFAd.AllStates,*thisState=AllStates,*Prev=NULL;
        while(pState->Next)
        {
            thisState->Name=pState->Name;
            thisState->Next=new TbUFAdState;
            thisState->Prev=Prev;
            thisState->Links=NULL;
            Prev=thisState;
            thisState=thisState->Next;
            pState=pState->Next;
        }
        thisState->Name=pState->Name;
        thisState->Next=NULL;
        thisState->Prev=Prev;
        thisState->Links=NULL;

        pState=UFAd.AllStates;
        thisState=AllStates;
        while(thisState)
        {
            if(pState->Links)
            {
                thisState->Links=new TbUFAdLink;
                TbUFAdLink *pLink=pState->Links,*thisLink=thisState->Links,*LinkPrev=NULL;
                while(pLink->Next)
                {
                    thisLink->Symbol=pLink->Symbol;
                    thisLink->Prev=LinkPrev;
                    thisLink->Next=new TbUFAdLink;
                    thisLink->State=SearchByName(pLink->State->Name);

                    LinkPrev=thisLink;
                    thisLink=thisLink->Next;
                    pLink=pLink->Next;
                }
                thisLink->Symbol=pLink->Symbol;
                thisLink->Prev=LinkPrev;
                thisLink->Next=NULL;
                thisLink->State=SearchByName(pLink->State->Name);
            }
            thisState=thisState->Next;
            pState=pState->Next;
        }
        FinalStates=new TbUFAdFinalState;
        TbUFAdFinalState *pFinalState=UFAd.FinalStates,*thisFinalState=FinalStates,
            *FinalPrev=NULL;
        while(pFinalState->Next)
        {
            thisFinalState->State=SearchByName(pFinalState->State->Name);
            thisFinalState->Next=new TbUFAdFinalState;
            thisFinalState->Prev=FinalPrev;
            FinalPrev=thisFinalState;
            thisFinalState=thisFinalState->Next;
            pFinalState=pFinalState->Next;
        }
        thisFinalState->State=SearchByName(pFinalState->State->Name);
        thisFinalState->Next=NULL;
        thisFinalState->Prev=FinalPrev;
    }
}
//---------------------------------------------------------------------------
TbUFAdState* TbUFAd::SearchByName(const int &Name)const
{
    TbUFAdState *Search=AllStates;
    while(Search && Search->Name!=Name)
    {
        Search=Search->Next;
    }
    return Search;
}
//---------------------------------------------------------------------------
void TbUFAd::print()const
{
    TbUFAdState *pState=AllStates;
    while(pState)
    {
        cout<<'['<<pState->Name<<']';
        TbUFAdLink *pLink=pState->Links;
        while(pLink)
        {
            cout<<"-"<<(char)pLink->Symbol<<"->["<<pLink->State->Name<<"];";
            pLink=pLink->Next;
        }
        cout<<endl;
        pState=pState->Next;
    }
    cout<<"Final state: ";
    TbUFAdFinalState *pFinalState=FinalStates;
    while(pFinalState)
    {
        cout<<"["<<pFinalState->State->Name<<"]";
        pFinalState=pFinalState->Next;
    }
    cout<<endl;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
 