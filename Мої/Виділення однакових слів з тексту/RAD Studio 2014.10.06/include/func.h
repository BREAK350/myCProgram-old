//---------------------------------------------------------------------------
#ifndef funcH
#define funcH
#include <vcl.h>
#include <set>
#include <vector>
#include <fstream.h>
#include <ctype.h>
//---------------------------------------------------------------------------
typedef std::set<String> StringSet;
typedef std::vector<String> StringVector;
//---------------------------------------------------------------------------
class TWords
{
	private:
		StringSet words;
	protected:
	public:
		TWords();
		TWords(const StringVector &words);

		bool contains(const String &word);
		bool add(const String &word);
		int add(const StringVector &words);

		void remove(const String &word);
		void remove(const StringVector &words);

		StringVector toStringVector(); // краще, щоб повертався вказівник на створений StringVector
};
//---------------------------------------------------------------------------
StringVector loadWordsFromFile(const char *fileName);
StringVector readWordsFrom(const char *text);
void removeWrongSymbols(char *line);
bool isCorrectSymbol(const char &symbol);
StringVector readWordsFrom(const String &text);
//---------------------------------------------------------------------------
class TMetaWord
{
	private:
		String word;
		int firstPosition;
	public:
		TMetaWord();
		TMetaWord(const String &word,const int &firstPosition);
		String getWord()const;
		int getFirstPosition()const;

		void setFirstPosition(const int &newPosition);
};
//---------------------------------------------------------------------------
struct TWordsTreeItem
{
	TMetaWord value;
	int count;
	TWordsTreeItem *left, *right;
	TWordsTreeItem(const TMetaWord &value);
	TWordsTreeItem(const TMetaWord &value,TWordsTreeItem *left,
		TWordsTreeItem *right);
};
//---------------------------------------------------------------------------
class TpWordTree
{
	private:
		TWordsTreeItem *treeItem;
	public:
		TpWordTree(TWordsTreeItem *treeItem);
		String getWord()const;
		int getFirstPosition()const;
		int getCount()const;
};
//---------------------------------------------------------------------------
typedef std::vector<TpWordTree> TpWordTreeVector;
//---------------------------------------------------------------------------
class TWordsTree
{
	private:
		TWordsTreeItem *root;
	private:
		void add(TWordsTreeItem *item,const TMetaWord &metaWord);
	public:
		TWordsTree();
		void add(const TMetaWord &metaWord);
		TpWordTreeVector getVector();
};
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
#endif
