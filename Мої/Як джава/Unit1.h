//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
#include <iostream.h>
//---------------------------------------------------------------------------
#define null NULL
//---------------------------------------------------------------------------
class Reference;
class RefObject;
//---------------------------------------------------------------------------
class List
{
	private:
		Reference *first;
	public:
		List();
		~List();
		void add(Reference *reference);
		void remove(Reference *reference);
};
//---------------------------------------------------------------------------
class Values
{
	private:
		List list;
		RefObject* forRemove[4];
		int top;

		void remove();
	public:
		Values();
		~Values();
		Reference* add(RefObject *refObject);
		/*
			Видалення: є масив обмеженої незмінної довжини. Як тільки
			цей масив заповниться, запускається очищення з списку.
		*/
		void remove(RefObject *refObject);
};
//---------------------------------------------------------------------------
class RefObject
{
	private:
		Reference *reference;
	protected:

	public:
		static Values values;
		RefObject();
		~RefObject();
        Reference* getReference();
};
Values RefObject::values;
//---------------------------------------------------------------------------
class Reference
{
	private:
		RefObject *refObj;
	public:
		Reference();
		Reference(Reference *prev, Reference *next);
		void setRefObj(RefObject *refObj);
		void remove();
		Reference *prev, *next;
};
//---------------------------------------------------------------------------
class RefString:public RefObject
{
	public:
		RefString();
		~RefString();
		RefString* toString();
};
//---------------------------------------------------------------------------
class Test
{
	private:
		RefObject *obj;
	public:
		Test(RefObject *obj)
		{
            this->obj = obj;
        }
		~Test()
		{
			delete obj;
			cout<<"~Test("<<this<<")\n";
		}
		RefObject* get()
		{
            return obj;
        }
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
