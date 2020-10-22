#include <iostream>
#include "Header.hpp"

int main() {
	use::Example E({ 1, 2, 3, 4 });
	int* c = new int[5];
	for (int i = 0; i < 5; ++i) {
		c[i] = i;
	}
	E += c;
	E += 5;

	std::cout << "E:\n" << E << std::endl;

	use::Example A(E);
	std::cout << "A:\n" << A << std::endl;

	use::Example B;
	B = A;
	std::cout << "B:\n" << B << std::endl;

	B += A;
	std::cout << "B:\n" << B << std::endl;
	std::cout << "A:\n" << A << std::endl;

	A = std::move(B);
	std::cout << "A:\n" << A << std::endl;
	std::cout << "B:\n" << B << std::endl;

	A += {6, 7, 8, 9};
	std::cout << "A:\n" << A << std::endl;

	return 0;
}
