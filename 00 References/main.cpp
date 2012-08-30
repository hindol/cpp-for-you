#include <cassert>
#include <iostream>

// Uncomment the following to complete this exercise.
/*
void Swap(int &x, int &y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}
*/

int main(int argc, char *argv[])
{
	int x = 5;
	int y = 10;

	Swap(x, y);

	assert(x == 10);
	assert(y == 5);

	std::cout << "Correct!" << std::endl;
	return 0;
}