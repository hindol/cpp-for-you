#include "array.h"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[])
{
    Array array; // Create a 0 element array
    assert(array.Size() == 0);
    assert(array.Capacity() == 0);

    array.Resize(10);
    assert(array.Size() == 10);
    assert(array.Capacity() == 20);

    std::cout << "Correct!" << std::endl;

    return 0;
}
