//---------------------------------------------------------------------------
#ifndef methrectH
#define methrectH
#include <vcl.h>
//---------------------------------------------------------------------------
class IntFraction
{
	private:
		int numerator; // чисельник
		int denominator; // знаменник

		void reduce(); // скоротити дріб, якщо можливо
	public:
		IntFraction();
		IntFraction(const int &numerator);
		IntFraction(const int &numerator, const int &denominator);

		operator String ()const;
		//operator double ()const;
		IntFraction operator + (const IntFraction &fract)const;
		IntFraction operator - (const IntFraction &fract)const;
		IntFraction operator * (const IntFraction &fract)const;
		IntFraction operator / (const IntFraction &fract)const;

		bool operator == (const IntFraction &fract)const;
		bool operator != (const IntFraction &fract)const;
		bool operator > (const IntFraction &fract)const;
		bool operator >= (const IntFraction &fract)const;
		bool operator < (const IntFraction &fract)const;
		bool operator <= (const IntFraction &fract)const;
};
//---------------------------------------------------------------------------
IntFraction convertFrom(const String &str);
//---------------------------------------------------------------------------
int nsd(int a,int b);
//---------------------------------------------------------------------------
template <class Type>
class MethRect
{
	private:
		int rows;
		int cols;
		Type **matrix;
	public:
		MethRect()
		{
			rows = 0;
			cols = 0;
		}
		MethRect(const int &rows, const int &cols)
		{
			if(rows > 0 && cols > 0)
			{
				this->rows = rows;
				this->cols = cols;
				matrix = new Type* [rows];
				for(int i = 0; i < rows; i++)
				{
					matrix[i] = new Type[cols];
				}
			}
			else
			{
				this->rows = 0;
				this->cols = 0;
			}
		}
		MethRect(const MethRect &mrect)
		{
			if(mrect.rows > 0)
			{
				this->rows = mrect.rows;
				this->cols = mrect.cols;
				this->matrix = new Type* [rows];
				for(int i = 0; i < rows; i++)
				{
					this->matrix[i] = new Type[cols];
					for(int j = 0; j < cols; j++)
					{
						this->matrix[i][j] = mrect.matrix[i][j];
					}
				}
			}
			else
			{
				this->rows = 0;
				this->cols = 0;
			}
        }
		MethRect(const int &rows, const int &cols, const Type **matrix)
		{
			if(rows > 0 && cols > 0)
			{
				this->rows = rows;
				this->cols = cols;
				this->matrix = new Type* [rows];
				for(int i = 0; i < rows; i++)
				{
					this->matrix[i] = new Type[cols];
					for(int j = 0; j < cols; j++)
					{
						this->matrix[i][j] = matrix[i][j];
					}
				}
			}
			else
			{
				this->rows = 0;
				this->cols = 0;
			}
		}
		~MethRect()
		{
        	clear();
		}
		void clear()
		{
        	if(rows > 0)
			{
				for(int i = 0; i < rows; i++)
				{
					delete[] matrix[i];
				}
				delete[] matrix;
			}
			rows = 0;
			cols = 0;
		}
		void newMatrix(const int &rows, const int &cols)
		{
        	if(rows > 0 && cols > 0)
			{
				clear();
				this->rows = rows;
				this->cols = cols;
				matrix = new Type* [rows];
				for(int i = 0; i < rows; i++)
				{
					matrix[i] = new Type[cols];
				}
			}
			else
			{
				this->rows = 0;
				this->cols = 0;
            }
        }
		operator Type** () { return matrix; }

		void chooseItem(const int &irow, const int &icol)
		{
			if(irow >= 0 && irow < rows && icol >= 0 && icol < cols)
			{
				if(matrix[irow][icol] != Type(0))
				{
					MethRect temp(*this);
					Type central = matrix[irow][icol];
					for(int j = 0; j < cols; j++)
					{
                        matrix[irow][j] = matrix[irow][j] / central;
                    }
					for(int i = 0; i < irow; i++)
					{
						for(int j = 0; j < cols; j++)
						{
							matrix[i][j] = temp[i][j] - temp[irow][j] * temp[i][icol] / central;
						}
					}
					for(int i = irow + 1; i < rows; i++)
					{
						for(int j = 0; j < cols; j++)
						{
							matrix[i][j] = temp[i][j] - temp[irow][j] * temp[i][icol] / central;
						}
					}
                }
            }
        }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
