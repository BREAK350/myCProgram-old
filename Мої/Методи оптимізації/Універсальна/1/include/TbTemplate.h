//---------------------------------------------------------------------------
#ifndef TbTemplateH
#define TbTemplateH
#include <vcl.h>
#include <vector.h>
//---------------------------------------------------------------------------
class TbTemplate
{
	private:
		String text; // text = "i love ${attr1} and ${attr2}!!!"
	protected:
		void replace(const String &what, const String &insert);
	public:
		TbTemplate() {}
		TbTemplate(const String &text);
		virtual String toString()const { return text; }
		void replaceAttribute(const String &attribute, const String &value);

		static String generateAttribute(const String &nameAttribute);
};
//---------------------------------------------------------------------------
class TbTagHTML: public TbTemplate
{
	private:
		vector<TbTemplate> templs;
	public:
		void setBody(const TbTemplate &templ);
		void setBody(const vector<TbTemplate> &templs);
		void add(const TbTemplate &templ);

		String toString()const;
};
//---------------------------------------------------------------------------
class TbHTMLFactory
{

	public:
    	static TbTemplate getBODY();
};
//---------------------------------------------------------------------------
class TbTemplateFactory
{
	public:
		static TbTemplate generateTABLE(const int &rowCount, const int &colCount,
			const String &prefix);
		static TbTemplate generateOL(const int &count, const String &prefix);
};
//---------------------------------------------------------------------------
class TbTag
{
	private:
		String before;
		String after;
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
