#include "array.h"

// TODO
Array::Array(SizeT size)
{
}

// TODO
Array::Array(SizeT size, ValueT initVal)
{
}

// TODO
Array::~Array()
{
}

// TODO
SizeT Array::Size() const
{
}

// TODO
const ValueT &Array::operator [](SizeT index) const
{
}

ValueT &Array::operator [](SizeT index)
{
	return const_cast<ValueT &>(
			static_cast<const Array>(*this)[index]
		);
}

void Array::Resize(SizeT newSize)
{
}
