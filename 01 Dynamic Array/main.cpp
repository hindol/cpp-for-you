#include "array.h"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[])
{
	Array array(10); // Create a 10 element array
	assert(array.Size() == 10);

	array.Resize(20);
	assert(array.Size() == 20);

	array.Resize(5);
	assert(array.Size() == 5);

	Array array2(10, -1); // Create a 10 element array, each of whose
						  // elements is initialized to -1
	for (int i = 0; i < 10; ++i)
	{
		assert(array2[i] == -1);
	}

	std::cout << "Correct!" << std::endl;

	return 0;
}
