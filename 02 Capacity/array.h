#ifndef ARRAY_H
#define ARRAY_H

// Portions of the code needs to be copied from last exercise.

typedef int             ValueT; // Change this to float if you need Array of floats etc.
typedef unsigned int    SizeT;  // Since array size cannot be negative, it is common
                                // practice to use unsigned int here.

class Array
{
public:
    Array(SizeT size = 0 /* If size is unspecified, assume 0. */);

    Array(SizeT size, ValueT initVal);
    
    ~Array();

    SizeT Capacity() const;

    SizeT Size() const;

    const ValueT &operator [](SizeT index) const;

    ValueT &operator [](SizeT index);

    /*
    Without Capacity() and Reserve(), the time-cost of one insertion
    into the array is O(n). To improve the time complexity, we
    introduce the notion of capacity. With capacity, the amortized
    time complexity of one insertion becomes O(1).

    "The size of a vector is the number of elements that it contains,
    which is directly controlled by how many elements you put into the vector.

    "Capacity is the amount of space allocated to the array. This is always
    equal to or larger than the size. The difference between them is the
    number of elements that you can add to the array before the array needs
    to reallocate."

    [Quoted portion taken from StackOverflow: http://stackoverflow.com/a/6296980]
    */

    void Reserve(SizeT newCapacity);

    void Resize(SizeT newSize);

private:
    // TODO: Place member variables here
};

#endif // ARRAY_H