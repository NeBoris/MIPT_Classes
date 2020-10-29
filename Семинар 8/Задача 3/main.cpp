#include <iostream>
#include "Rational.hpp"

int main() {
	use::Rational R(14, 7);
	std::cout << R << std::endl;

	R += use::Rational(5, 4);
	std::cout << R << std::endl;



	return 0;
}