//---------------------------------------------------------------------------
#pragma hdrstop
#include "Unit2.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
void T_Player::SaveToFile(FILE *File,const int &CountTypeArmy)
{
    fwrite(&Money,sizeof(int),1,File);
    fwrite(&AddMoney,sizeof(int),1,File);

    fwrite(Life,sizeof(double),CountTypeArmy,File);
    for(int i=0;i<CountTypeArmy;i++)
    {
        fwrite(Attack[i],sizeof(double),CountTypeArmy,File);
    }
    for(int i=0;i<CountTypeArmy;i++)
    {
        fwrite(Protection[i],sizeof(double),CountTypeArmy,File);
    }
}
//---------------------------------------------------------------------------
void T_Player::LoadFromFile(FILE *File,const int &CountTypeArmy)
{
    Delete(CountTypeArmy);

    Life=new double [CountTypeArmy];
    Attack=new double* [CountTypeArmy];
    Protection=new double* [CountTypeArmy];
    for(int i=0;i<CountTypeArmy;i++)
    {
        Attack[i]=new double [CountTypeArmy];
        Protection[i]=new double [CountTypeArmy];
    }

    fread(&Money,sizeof(int),1,File);
    fread(&AddMoney,sizeof(int),1,File);

    fread(Life,sizeof(double),CountTypeArmy,File);
    for(int i=0;i<CountTypeArmy;i++)
    {
        fread(Attack[i],sizeof(double),CountTypeArmy,File);
    }
    for(int i=0;i<CountTypeArmy;i++)
    {
        fread(Protection[i],sizeof(double),CountTypeArmy,File);
    }
}
//---------------------------------------------------------------------------
void T_Player::Delete(const int &CountTypeArmy)
{
    if(Life)
    {
        delete Life;
        for(int i=0;i<CountTypeArmy;i++)
        {
            delete Attack[i];
            delete Protection[i];
        }
        delete Attack;
        delete Protection;
        Life=NULL;
        Attack=NULL;
        Protection=NULL;
    }
}
//---------------------------------------------------------------------------
void T_City::LoadFromFile(FILE *File,const int &CountTypeArmy)
{
    Delete();
    CountArmy=new int [CountTypeArmy];
    AddArmy=new int [CountTypeArmy];

    fread(&Location,sizeof(TPoint),1,File);
    fread(&PlayerNumber,sizeof(int),1,File);
    fread(CountArmy,sizeof(int),CountTypeArmy,File);
    fread(AddArmy,sizeof(int),CountTypeArmy,File);
}
//---------------------------------------------------------------------------
void T_City::SaveToFile(FILE *File,const int &CountTypeArmy)
{
    fwrite(&Location,sizeof(TPoint),1,File);
    fwrite(&PlayerNumber,sizeof(int),1,File);
    fwrite(CountArmy,sizeof(int),CountTypeArmy,File);
    fwrite(AddArmy,sizeof(int),CountTypeArmy,File);
}
//---------------------------------------------------------------------------
void T_City::Delete()
{
    delete CountArmy;
    delete AddArmy;
    CountArmy=NULL;
    AddArmy=NULL;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
T_Game::T_Game()
{
    CountTypeArmy=0;
    CountPlayer=0;
    CountCity=0;
    CurrPlayer=0;
    Player=NULL;
    City=NULL;
    CityLink=NULL;
}
//---------------------------------------------------------------------------
void T_Game::SaveToFile(FILE *File)
{
    fwrite(&CountPlayer,sizeof(int),1,File);
    fwrite(&CurrPlayer,sizeof(int),1,File);
    fwrite(&CountTypeArmy,sizeof(int),1,File);
    fwrite(&CountCity,sizeof(int),1,File);
    fwrite(&CurrCity,sizeof(int),1,File);
    for(int i=0;i<CountPlayer;i++)
    {
        Player[i].SaveToFile(File,CountTypeArmy);
    }
    fwrite(CostArmy,sizeof(int),CountTypeArmy,File);
    for(int i=0;i<CountCity;i++)
    {
        City[i].SaveToFile(File,CountTypeArmy);
    }
    for(int i=0;i<CountCity;i++)
    {
        fwrite(CityLink[i],sizeof(char),CountCity,File);
    }
}
//---------------------------------------------------------------------------
void T_Game::LoadFromFile(FILE *File)
{
    Delete();

    fread(&CountPlayer,sizeof(int),1,File);
    fread(&CurrPlayer,sizeof(int),1,File);
    fread(&CountTypeArmy,sizeof(int),1,File);
    fread(&CountCity,sizeof(int),1,File);
    fread(&CurrCity,sizeof(int),1,File);

    Player=new T_Player [CountPlayer];
    CostArmy=new int [CountTypeArmy];
    City=new T_City [CountCity];
    CityLink=new char* [CountCity];
    for(int i=0;i<CountCity;i++)
    {
        CityLink[i]=new char [CountCity];
    }

    for(int i=0;i<CountPlayer;i++)
    {
        Player[i].LoadFromFile(File,CountTypeArmy);
    }
    fread(CostArmy,sizeof(int),CountTypeArmy,File);
    for(int i=0;i<CountCity;i++)
    {
        City[i].LoadFromFile(File,CountTypeArmy);
    }
    for(int i=0;i<CountCity;i++)
    {
        fread(CityLink[i],sizeof(char),CountCity,File);
    }
}
//---------------------------------------------------------------------------
void T_Game::Delete()
{
    for(int i=0;i<CountPlayer;i++)
    {
        Player[i].Delete(CountTypeArmy);
    }
    delete Player;
    delete CostArmy;
    for(int i=0;i<CountCity;i++)
    {
        City[i].Delete();
    }
    delete City;
    for(int i=0;i<CountCity;i++)
    {
        delete CityLink[i];
    }
    delete CityLink;
    Player=NULL;
    CostArmy=NULL;
    City=NULL;
    CityLink=NULL;
}
//---------------------------------------------------------------------------
int T_Game::BuyArmy(const int &TypeArmy,const int &Count)
{
    int buy=0;
    if(CountPlayer)
    {
        if(City[CurrCity].PlayerNumber==CurrPlayer)
        {
            int cost=CostArmy[TypeArmy]*Count;
            if(Player[CurrPlayer].Money>=cost)
            {
                Player[CurrPlayer].Money-=cost;
                City[CurrCity].CountArmy[TypeArmy]+=Count;
                buy=Count;
            }
        }
    }
    return buy;
}
//---------------------------------------------------------------------------
int T_Game::MovingArmy(int *CountArmy,const int &CityTo)
{
    int move=0;
    if(CountPlayer)
    {
        if(City[CurrCity].PlayerNumber==CurrPlayer &&
           (City[CityTo].PlayerNumber==CurrPlayer || City[CityTo].PlayerNumber==-1) &&
            CityLink[CurrCity][CityTo]==1)
        {
            for(int i=0;i<CountTypeArmy;i++)
            {
                CountArmy[i]=(CountArmy[i]<City[CurrCity].CountArmy[i])?(CountArmy[i]):(City[CurrCity].CountArmy[i]);
                City[CurrCity].CountArmy[i]-=CountArmy[i];
                City[CityTo].CountArmy[i]+=CountArmy[i];
            }
            City[CityTo].PlayerNumber=CurrPlayer;
            move=1;
        }
    }
    return move;
}
//---------------------------------------------------------------------------
int T_Game::ChooseCity(const TPoint &Location)
{
    if(CountPlayer)
    {
        int i=0;
        while(i<CountCity && City[i].Location!=Location)
        {
            i++;
        }
        if(i<CountCity)
        {
            CurrCity=i;
        }
    }
    return CurrCity;
}
//---------------------------------------------------------------------------
void Sort(const double *s,int *ind,const int &n)
{
    for(int i=0;i<n;i++)
    {
        ind[i]=i;
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            if(s[ind[i]]<s[ind[j]])
            {
                int x=ind[i];
                ind[i]=ind[j];
                ind[j]=x;
            }
        }
    }
}
//---------------------------------------------------------------------------
void AttackArmy(const int &CountMyArmy,const double &MyAttack,
    int &CountEnemyArmy,const double &EnemyProtection,const double &EnemyLife)
{
    double Attack=CountMyArmy*MyAttack;
    double Protection=CountEnemyArmy*EnemyProtection;
    Attack=(Attack>Protection)?(Attack=Protection):(0);
    CountEnemyArmy=(CountEnemyArmy*EnemyLife-Attack)/EnemyLife;
}
//---------------------------------------------------------------------------
int T_Game::Attack(int *CountArmy,const int &CityTo)
{
    int attack=0;
    if(CountPlayer)
    {
        if(City[CurrCity].PlayerNumber==CurrPlayer)
        {
            if(City[CityTo].PlayerNumber!=CurrPlayer && City[CityTo].PlayerNumber!=-1)
            {
                for(int i=0;i<CountTypeArmy;i++)
                {
                    CountArmy[i]=(CountArmy[i]<=City[CurrCity].CountArmy[i])?(CountArmy[i]):(City[CurrCity].CountArmy[i]);
                    City[CurrCity].CountArmy[i]-=CountArmy[i];
                }
                int **Link=new int* [CountTypeArmy];
                for(int i=0;i<CountTypeArmy;i++)
                {
                    Link[i]=new int [CountTypeArmy];
                    Sort(Player[CurrPlayer].Attack[i],Link[i],CountTypeArmy);
                }
                for(int j=0;j<CountTypeArmy;j++)
                {
                    for(int i=0;i<CountTypeArmy;i++)
                    {
                        AttackArmy(CountArmy[i],Player[CurrPlayer].Attack[i][Link[i][j]],
                            City[CityTo].CountArmy[Link[i][j]],Player[City[CityTo].PlayerNumber].Protection[Link[i][j]][i],
                            Player[City[CityTo].PlayerNumber].Life[Link[i][j]]);
                        AttackArmy(City[CityTo].CountArmy[Link[i][j]],Player[City[CityTo].PlayerNumber].Attack[Link[i][j]][i],
                            CountArmy[i],Player[CurrPlayer].Protection[i][Link[i][j]],Player[CurrPlayer].Life[i]);
                    }
                }
                for(int i=0;i<CountTypeArmy;i++)
                {
                    City[CurrCity].CountArmy[i]+=CountArmy[i];
                }
                for(int i=0;i<CountTypeArmy;i++)
                {
                    delete Link[i];
                }
                delete Link;
                attack=1;
            }
        }
    }
    return attack;
}
//---------------------------------------------------------------------------
T_CityInf3 T_Game::GetCityInf3()const
{
    T_CityInf3 CityInf3;
    CityInf3.CityNumber=CurrCity;
    CityInf3.PlayerNumber=City[CurrCity].PlayerNumber;
    CityInf3.Location=City[CurrCity].Location;
    if(AccessCity())
    {
        CityInf3.CountArmy[0]=City[CurrCity].CountArmy[0];
        CityInf3.CountArmy[1]=City[CurrCity].CountArmy[1];
        CityInf3.CountArmy[2]=City[CurrCity].CountArmy[2];
    }
    else
    {
        CityInf3.CountArmy[0]=-1;
        CityInf3.CountArmy[1]=-1;
        CityInf3.CountArmy[2]=-1;
    }
    return CityInf3;
}
//---------------------------------------------------------------------------
int T_Game::AccessCity()const
{
    int q=0;
    if(City[CurrCity].PlayerNumber==CurrPlayer)
    {
        q=1;
    }
    else
    {
        if(City[CurrCity].PlayerNumber!=-1)
        {
            int i=0;
            while(i<CountPlayer && q==0)
            {
                if(CityLink[CurrCity][i] && City[i].PlayerNumber==CurrPlayer)
                {
                    q=1;
                }
                i++;
            }
        }
    }
    return q;
}
//---------------------------------------------------------------------------
void T_Game::Draw(TbOrientation &Or)const
{
    for(int i=0;i<CountCity;i++)
    {
        for(int j=i;j<CountCity;j++)
        {
            if(CityLink[i][j])
            {
                Or.MoveTo(City[i].Location.x+0.5,City[i].Location.y+0.5);
                Or.LineTo(City[j].Location.x+0.5,City[j].Location.y+0.5);
            }
        }
    }
    for(int i=0;i<CountCity;i++)
    {
        if(City[i].PlayerNumber==-1)
        {
            Or.Canvas->Brush->Color=clYellow;
        }
        else
        if(City[i].PlayerNumber==CurrPlayer)
        {
            Or.Canvas->Brush->Color=clBlue;
        }
        else
        {
            Or.Canvas->Brush->Color=clRed;
        }
        Or.Rectangle(City[i].Location.x,City[i].Location.y,City[i].Location.x+1,City[i].Location.y+1);
    }
}
//---------------------------------------------------------------------------
void T_Game::Init1()
{
    CountPlayer=2;
    CountTypeArmy=3;
    CountCity=5;
    Player=new T_Player[CountPlayer];
    for(int i=0;i<CountPlayer;i++)
    {
        Player[i].Money=1000;
        Player[i].AddMoney=100;
        Player[i].Life=new double [CountTypeArmy];
        for(int j=0;j<CountTypeArmy;j++)
        {
            Player[i].Life[j]=100;
        }
        Player[i].Attack=new double* [CountTypeArmy];
        Player[i].Protection=new double* [CountTypeArmy];
        for(int j=0;j<CountTypeArmy;j++)
        {
            Player[i].Attack[j]=new double [CountTypeArmy];
            Player[i].Protection[j]=new double [CountTypeArmy];
            for(int k=0;k<CountTypeArmy;k++)
            {
                Player[i].Attack[j][k]=random(20)+10;
                Player[i].Protection[j][k]=random(5)+4;
            }
        }
    }
    CostArmy=new int [CountTypeArmy];
    for(int i=0;i<CountTypeArmy;i++)
    {
        CostArmy[i]=random(15)+10;
    }
    City=new T_City [CountCity];
    for(int i=0;i<CountCity;i++)
    {
        City[i].PlayerNumber=-1;
        City[i].Location.x=random(9)+1;
        City[i].Location.y=random(9)+1;
        City[i].CountArmy=new int [CountTypeArmy];
        City[i].AddArmy=new int [CountTypeArmy];
        for(int j=0;j<CountTypeArmy;j++)
        {
            City[i].CountArmy[j]=random(100);
            City[i].AddArmy[j]=random(10);
        }
    }
    CityLink=new char* [CountCity];
    for(int i=0;i<CountCity;i++)
    {
        CityLink[i]=new char [CountCity];
    }
    for(int i=0;i<CountCity;i++)
    {
        for(int j=i;j<CountCity;j++)
        {
            CityLink[i][j]=random(2);
            CityLink[j][i]=CityLink[i][j];
        }
    }
    City[0].PlayerNumber=0;
    City[1].PlayerNumber=1;
}
//---------------------------------------------------------------------------
int T_Game::isAttack()const //повертає номер міста, якщо можна атакувати, інакше -1
{
    int n=-1;
    if(CountPlayer)
    {
        if(City[CurrCity].PlayerNumber!=-1 && City[CurrCity].PlayerNumber!=CurrPlayer)
        {
            int i=0;
            while(n==-1 && i<CountCity)
            {
                if(CityLink[CurrCity][i] && City[i].PlayerNumber==CurrPlayer)
                {
                    n=CurrCity;
                }
                i++;
            }
        }
    }
    return n;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
