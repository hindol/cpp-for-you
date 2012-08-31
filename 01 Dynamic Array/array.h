#ifndef ARRAY_H
#define ARRAY_H

typedef int             ValueT; // Change this to float if you need Array of floats etc.
typedef unsigned int    SizeT;  // Since array size cannot be negative, it is common
                                // practice to use unsigned int here.

class Array
{
public:
    Array(SizeT size);

    Array(SizeT size, ValueT initVal);
    
    ~Array();

    /*
    The const at the end means this method does not modify the class
    instance on which it is called. Any attempt to do so raises a
    compiler error.
    */

    SizeT Size() const;

    /*
    Array array(n);
    array[i]; // Calls the non-const version of operator []();

    const Array(n);
    array[i]; // Calls the const version of operator []();

    But since both the const and non-const version do a very similar
    thing, the non-const version is internally using the const version
    (with some neat C++ tricks). You only need to implement the const
    version.
    */

    // Accessor, e.g. ValueT var = array[i], trying to assign raises
    // compiler error. E.g. array[i] = var2 // ERROR
    const ValueT &operator [](SizeT index) const;

    // Accessor + Modifier, e.g. ValueT var = array[i], array[i] = var2
    ValueT &operator [](SizeT index);

    void Resize(SizeT newSize);

private:
    // TODO: Place member variables here
};

#endif // ARRAY_H