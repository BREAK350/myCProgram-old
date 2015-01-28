//---------------------------------------------------------------------------
#ifndef TbSortListFullConnectionH
#define TbSortListFullConnectionH
//---------------------------------------------------------------------------
template <class TData,class TListItem>
void AddNext(TListItem *Item,TData Data)
{
    Item->Next=new TListItem(Data);
}
//---------------------------------------------------------------------------
class G
{
    private:
        struct X;
        struct Obj
        {
            int Data;
            Obj *Next,*Prev;
            X *x;
            Obj(const int &Data) { this->Data=Data; }
        }*ObjFirst,*ObjLast;
        struct X
        {
            int Data;
            X *Next,*Prev;
            Obj *obj;
            X(const int &Data) { this->Data=Data; }
        }*XFirst,*XLast;


        void Add(const int &Data);
};
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#endif
 