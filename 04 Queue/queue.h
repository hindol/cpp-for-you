#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
public:
	typedef int         ValueT;
    typedef unsigned    SizeT;

    SizeT Size() const;

	void Enqueue(ValueT newValue);
	void Dequeue();

	ValueT &Front();
	const ValueT &Front() const;

	ValueT &Back();
	const ValueT &Back() const;
};

#endif // QUEUE_H