//---------------------------------------------------------------------------
#pragma hdrstop
#include "TbMatrix_d.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
TbMatrix_d::TbMatrix_d()
{
    RowCount=0;
    ColCount=0;
    Element=NULL;
}
//---------------------------------------------------------------------------
TbMatrix_d::TbMatrix_d(const int &RowCount,const int &ColCount)
{
    this->RowCount=(RowCount>0)?(RowCount):(0);
    this->ColCount=(ColCount>0)?(ColCount):(0);
    if(this->RowCount>0 && this->ColCount>0)
    {
        Element=new double* [this->RowCount];
        for(int i=0;i<this->RowCount;i++)
        {
			Element[i]=new double [this->ColCount];
			for(int j=0;j<this->ColCount;j++)
			{
                Element[i][j]=0;
            }
        }
    }
    else
    {
        this->RowCount=0;
        this->ColCount=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
TbMatrix_d::TbMatrix_d(const TbMatrix_d &Matrix)
{
    RowCount=Matrix.RowCount;
    ColCount=Matrix.ColCount;
    if(RowCount>0 && ColCount>0)
    {
        Element=new double* [RowCount];
        for(int i=0;i<RowCount;i++)
        {
            int j;
            Element[i]=new double [ColCount];
            for(j=0;j<ColCount;j++)
            {
                Element[i][j]=Matrix.Element[i][j];
            }
        }
    }
    else
    {
        RowCount=0;
        ColCount=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
TbMatrix_d::~TbMatrix_d()
{
    if(RowCount>0 && ColCount>0)
    {
        for(int i=0;i<RowCount;i++)
        {
            delete[] Element[i];
        }
        delete[] Element;
        RowCount=0;
        ColCount=0;
        Element=NULL;
    }
}
//---------------------------------------------------------------------------
TbMatrix_d& TbMatrix_d::operator = (const TbMatrix_d &Matrix)
{
    if(this!=&Matrix)
    {
        if(RowCount>0 && ColCount>0)
        {
            for(int i=0;i<RowCount;i++)
            {
                delete[] Element[i];
            }
            delete[] Element;
        }
        RowCount=Matrix.RowCount;
        ColCount=Matrix.ColCount;
        if(RowCount>0 && ColCount>0)
        {
            Element=new double* [RowCount];
            for(int i=0;i<RowCount;i++)
            {
                int j;
                Element[i]=new double [ColCount];
                for(j=0;j<ColCount;j++)
                {
                    Element[i][j]=Matrix.Element[i][j];
                }
            }
        }
        else
        {
            RowCount=0;
            ColCount=0;
            Element=NULL;
        }
    }
    return *this;
}
//---------------------------------------------------------------------------
TbMatrix_d TbMatrix_d::operator + (const TbMatrix_d &Matrix)const
{
    TbMatrix_d R;
    if(RowCount==Matrix.RowCount && ColCount==Matrix.ColCount)
    {
        R.Element=new double* [RowCount];
        for(int i=0;i<RowCount;i++)
        {
            int j;
            R.Element[i]=new double [ColCount];
            for(j=0;j<ColCount;j++)
            {
                R.Element[i][j]=Element[i][j]+Matrix.Element[i][j];
            }
		}
		R.RowCount=RowCount;
		R.ColCount=ColCount;
    }
    return R;
}
//---------------------------------------------------------------------------
TbMatrix_d TbMatrix_d::operator - (const TbMatrix_d &Matrix)const
{
    TbMatrix_d R;
    if(RowCount==Matrix.RowCount && ColCount==Matrix.ColCount)
    {
        R.Element=new double* [RowCount];
        for(int i=0;i<RowCount;i++)
        {
            int j;
            R.Element[i]=new double [ColCount];
            for(j=0;j<ColCount;j++)
            {
                R.Element[i][j]=Element[i][j]-Matrix.Element[i][j];
            }
		}
		R.RowCount=RowCount;
		R.ColCount=ColCount;
    }
    return R;
}
//---------------------------------------------------------------------------
TbMatrix_d& TbMatrix_d::operator += (const TbMatrix_d &Matrix)
{
    *this=*this+Matrix;
    return *this;
}
//---------------------------------------------------------------------------
TbMatrix_d& TbMatrix_d::operator -= (const TbMatrix_d &Matrix)
{
    *this=*this-Matrix;
    return *this;
}
//---------------------------------------------------------------------------
TbMatrix_d TbMatrix_d::operator * (const TbMatrix_d &Matrix)const
{
    TbMatrix_d R;
    if(ColCount==Matrix.RowCount)
    {
        R.Element=new double* [RowCount];
        for(int i=0;i<RowCount;i++)
        {
            R.Element[i]=new double [Matrix.ColCount];
            for(int j=0;j<Matrix.ColCount;j++)
			{
                R.Element[i][j]=0;
                for(int k=0;k<ColCount;k++)
                {
                    R.Element[i][j]+=Element[i][k]*Matrix.Element[k][j];
                }
            }
		}
		R.RowCount=RowCount;
		R.ColCount=Matrix.ColCount;
    }
    return R;
}
//---------------------------------------------------------------------------
TbMatrix_d& TbMatrix_d::operator *= (const TbMatrix_d &Matrix)
{
    *this=*this*Matrix;
    return *this;
}
//---------------------------------------------------------------------------
double TbMatrix_d::GetElement(const int &irow,const int &icol)const
{
	double el=0;
	if(isCorrect(irow,icol))
	{
		el=Element[irow][icol];
	}
	return el;
}
//---------------------------------------------------------------------------
bool TbMatrix_d::isCorrect(const int &irow,const int &icol)const
{
	return irow>=0 && irow<GetRowCount() && icol>=0 && icol<GetColCount();
}
//---------------------------------------------------------------------------
void TbMatrix_d::proSetElement(const int &irow,const int &icol,
	const double &Value)
{
	Element[irow][icol]=Value;
}
//---------------------------------------------------------------------------
double TbMatrix_d::proGetElement(const int &irow,const int &icol)const
{
	return Element[irow][icol];
}
//---------------------------------------------------------------------------
void TbMatrix_d::SetElement(const int &irow,const int &icol,const double &Value)
{
    if(isCorrect(irow,icol))
    {
        proSetElement(irow,icol,Value);
    }
}
//---------------------------------------------------------------------------
TbMatrix_d TbMatrix_d::operator * (const double &value)const
{
    TbMatrix_d res(GetRowCount(),GetColCount());
    for(int irow=0;irow<GetRowCount();irow++)
    {
        for(int icol=0;icol<GetColCount();icol++)
        {
            double newElement=value*proGetElement(irow,icol);
            res.proSetElement(irow,icol,newElement);
        }
    }
    return res;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
