//---------------------------------------------------------------------------
#ifndef TbTagHTMLH
#define TbTagHTMLH
#include <vcl.h>
#include <vector.h>
//---------------------------------------------------------------------------
class TbContentsHTML
{
	public:
		virtual String toString() = 0;
};
//---------------------------------------------------------------------------
class TbTextHTML: public TbContentsHTML
{
	String text;
	public:
		TbTextHTML();
		TbTextHTML(const String &text);
		String toString();
};
//---------------------------------------------------------------------------
class TbParamTagHTML: public TbContentsHTML
{
	public:
		String toString();
};
//---------------------------------------------------------------------------
class TbTagHTML: public TbContentsHTML
{
	private:
		String name;
		bool single;
		TbContentsHTML *params;
		TbContentsHTML *contents;
	public:
		TbTagHTML(const String &name, const bool &single);
		TbTagHTML(const String &name, const bool &single,
			TbContentsHTML *params, TbContentsHTML *contents);

		String toString();

		void setParams(TbContentsHTML *params);
		void setContents(TbContentsHTML *contents);
};
//---------------------------------------------------------------------------
class TbContainerHTML: public TbContentsHTML
{
	public:
		class TbItem: public TbContentsHTML
		{
			protected:
				TbContentsHTML *contents;

				TbContainerHTML *container;
				TbItem *next;
				TbItem *prev;
			protected:

			public:
				TbItem(TbContentsHTML *contents, TbContainerHTML *container);
				TbItem* addNext(TbContentsHTML *contents);
				TbItem* addPrev(TbContentsHTML *contents);
				TbItem* addNext(TbItem *item);
				TbItem* addPrev(TbItem *item);

				void setNext(TbItem *item);
				void setPrev(TbItem *item);

				String toString();
				TbItem* getNext();
				TbItem* getPrev();
		};
	private:
		TbItem *first;
		TbItem *last;
	public:
		TbContainerHTML();
		TbItem* add(TbContentsHTML *contents);
		TbItem* addLast(TbContentsHTML *contents);
		TbItem* addFirst(TbContentsHTML *contents);
		TbItem* addLast(TbItem *item);
		TbItem* addFirst(TbItem *item);
		bool isFirst(TbItem *item);
		bool isLast(TbItem *item);

		String toString();
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
