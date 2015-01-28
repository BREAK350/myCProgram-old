//---------------------------------------------------------------------------
#ifndef TbMatrixH
#define TbMatrixH
#include <vcl.h>
//---------------------------------------------------------------------------
template <class Type>
class TbMatrix
{
	public:
		/*
			Поки повертає true дана функція викликається.
		*/
		typedef bool (*FuncForEach)(const int &row, const int &col,
										Type &item);
	private:
		int rowCount;
		int colCount;
		Type **data;
	// method
	private:
		bool createNew(const int &rowCount, const int &colCount)
		{
			if(rowCount > 0 && colCount > 0)
			{
				data = new Type* [rowCount];
				for(int i = 0; i < rowCount; i++)
				{
                    data[i] = new Type [colCount];
				}
				return true;
			}
			return false;
		}
		void createNewEmpty()
		{
        	data = NULL;
			rowCount = 0;
			colCount = 0;
        }
		void remove()
		{
			if(!isEmpty())
			{
				for(int i = 0; i < rowCount; i++)
				{
					delete[] data[i];
				}
				delete[] data;

				createNewEmpty();
			}
		}
	protected:

	public:
		TbMatrix()
		{
			rowCount = 0;
			colCount = 0;
			data = null;
		}
		TbMatrix(const TbMatrix &matrix)
		{
			if(!matrix.isEmpty())
			{
				createNew(matrix.rowCount, matrix.colCount);
				copy(matrix.data, data);

				rowCount = matrix.rowCount;
				colCount = matrix.colCount;
			}
			else
			{
				createNewEmpty();
            }
		}
		TbMatrix(const int &rowCount, const int &colCount)
		{
			if(createNew(rowCount, colCount) == false)
			{
				createNewEmpty();
			}
			else
			{
				this->rowCount = rowCount;
				this->colCount = colCount;
			}
		}
		~TbMatrix()
		{
        	remove();
        }
		operator [](const int &row)const
		{
			return data[row];
		}
		/*
			Метод для кожного елемента матриці викликає функцію f і
			якщо функція поверне true - переходить до наступного
			елемента матриці, інакше - відбувається вихід з методу.

			Для першого елемента виклик функції f відбувається завжди.
		*/
		void forEachDo(FuncForEach f)
		{
			if(data != NULL)
			{
				bool goNext = false;
				int i = 0;
				do
				{
					int j = 0;
					do
					{
						goNext = f(i, j, data[i][j]);
						j++;
					}
					while(j < colCount && goNext);
					i++;
				}
				while(i < rowCount && goNext);
			}
		}
		bool isEmpty()const
		{
            return data == NULL;
		}
		int getRowCount()const
		{
			return rowCount;
		}
		int getColCount()const
		{
            return colCount;
        }
	// static
	private:
		static void copy(const Type **from, Type **to,
			const int &rowCount, const int &colCount)
		{
			for(int i = 0; i < rowCount; i++)
			{
				for(int j = 0; j < colCount; j++)
				{
                	to[i][j] = from[i][j];
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
//---------------------------------------------------------------------------
#endif
