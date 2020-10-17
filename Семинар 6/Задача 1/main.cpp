#include <iostream>
#include "Header.hpp"

int main() {
	use::Example E({ 1, 2, 3, 4 });
	int* c = new int[5];

	std::cout << E;

	return 0;
}