#ifndef STACK_H
#define STACK_H

#include "list.h"

class Stack
{
public:
    typedef int         ValueT;
    typedef unsigned    SizeT;

    SizeT Size() const;

    void Push(ValueT value);

    ValueT &Top();

    const ValueT &Top() const;

    void Pop();
};

#endif // STACK_H