#ifndef LIST_H
#define LIST_H

#include <iterator>

typedef int      ValueT;
typedef unsigned SizeT;

struct Node
{
	Node(ValueT initValue, Node *initPrev, Node *initNext)
		: value(initValue), prev(initPrev), next(initNext) {}

	ValueT value;
	Node *prev;
	Node *next;
};

template <class ValueType>
struct ListIterator : std::iterator<std::bidirectional_iterator_tag, ValueType>
{
	ListIterator(const ListIterator &other) : cur(other.cur) {}

	ListIterator &operator =(const ListIterator &other)
	{ cur = other.cur; return *this; }
	
	~ListIterator() {}

	ValueType &operator *() const
	{ return cur->value; }

	friend bool operator !=(const ListIterator &lhs, const ListIterator &rhs)
	{ return lhs.cur != rhs.cur; }
	
	friend bool operator ==(const ListIterator &lhs, const ListIterator &rhs)
	{ return lhs.cur == rhs.cur; }

	ListIterator operator ++()
	{ cur = cur->next; return *this; }

	ListIterator operator ++(int)
	{ ListIterator copy(*this); cur = cur->next; return copy; }

	ListIterator operator --()
	{ cur = cur->prev; return *this; }

	ListIterator operator --(int)
	{ ListIterator copy(*this); cur = cur->prev; return copy; }

	ValueType *operator ->() const
	{ return &(cur->value); }

private:
	ListIterator(Node *init) : cur(init) {}

	Node *cur;

	friend class List;
};

class List
{
public:
	typedef ListIterator<ValueT> 		Iterator;
	typedef ListIterator<const ValueT>	ConstIterator;

	List() : head(0L), tail(0L), size(0) {}
	~List();

	SizeT Size() const
	{ return size; }

	ValueT &Front()
	{ return const_cast<ValueT &>( static_cast<const List *>(this)->Front() ); }

	const ValueT &Front() const
	{ return head->value; }

	ValueT &Back()
	{ return const_cast<ValueT &>( static_cast<const List *>(this)->Back() ); }

	const ValueT &Back() const
	{ return tail->value; }

	void PushBack(ValueT value)
	{ Insert(End(), value); }

	void PopBack()
	{ Erase(--End()); }

	void PushFront(ValueT value)
	{ Insert(Begin(), value); }

	void PopFront()
	{ Erase(Begin()); }

	void Insert(Iterator it, ValueT value);
	void Erase(Iterator it);

	Iterator Begin()
	{ Iterator begin(head); return begin; }

	Iterator End()
	{ Iterator end(0L); return end; }

	Iterator RBegin()
	{ Iterator rbegin(tail); return rbegin; }

	Iterator REnd()
	{ Iterator rend(0L); return rend; }

	ConstIterator CBegin()
	{ ConstIterator cbegin(head); return cbegin; }

	ConstIterator CEnd()
	{ ConstIterator cend(0L); return cend; }

	ConstIterator CRBegin()
	{ ConstIterator crbegin(tail); return crbegin; }

	ConstIterator CREnd()
	{ ConstIterator crend(0L); return crend; }

private:
	Node *head;
	Node *tail;
	SizeT size;
};

#endif // LIST_H
