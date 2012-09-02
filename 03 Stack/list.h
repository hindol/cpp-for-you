#ifndef LIST_H
#define LIST_H

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

#include "list_iterator.h" // Needs definition of Node

class List
{
public:
	typedef ListIterator<ValueT> 				Iterator;
	typedef ListIterator<const ValueT>			ConstIterator;
	typedef ListReverseIterator<ValueT> 		ReverseIterator;
	typedef ListReverseIterator<const ValueT>	ConstReverseIterator;

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

	ReverseIterator RBegin()
	{ ReverseIterator rbegin(tail); return rbegin; }

	ReverseIterator REnd()
	{ ReverseIterator rend(0L); return rend; }

	ConstIterator CBegin()
	{ ConstIterator cbegin(head); return cbegin; }

	ConstIterator CEnd()
	{ ConstIterator cend(0L); return cend; }

	ConstReverseIterator CRBegin()
	{ ConstReverseIterator crbegin(tail); return crbegin; }

	ConstReverseIterator CREnd()
	{ ConstReverseIterator crend(0L); return crend; }

private:
	Node *head;
	Node *tail;
	SizeT size;
};

#endif // LIST_H
