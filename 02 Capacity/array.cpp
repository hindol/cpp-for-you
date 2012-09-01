#include "array.h"

// Portions of the code needs to be copied from last exercise.

Array::Array(SizeT size /* = 0 */)
{
}

Array::Array(SizeT size, ValueT initVal)
{
}

Array::~Array()
{
}

// TODO
SizeT Capacity() const
{
}

SizeT Array::Size() const
{
}

const ValueT &Array::operator [](SizeT index) const
{
}

ValueT &Array::operator [](SizeT index)
{
    return const_cast<ValueT &>(
            static_cast<const Array>(*this)[index]
        );
}

// TODO
void Array::Reserve(SizeT newCapacity)
{
	// Note that Reserve() can only *increase* the capacity.
	// If newCapacity < Capacity() it does nothing.
	if (newCapacity > Capacity())
	{
		// Do reallocation
	}
}

void Array::Resize(SizeT newSize)
{
	if (newSize > Capacity())
	{
		Reserve(newSize * 2);
	}

	// Set size = newSize
}
