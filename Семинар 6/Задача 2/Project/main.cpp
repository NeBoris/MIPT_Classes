#include <iostream>
#include "Rational.hpp"

int main() {
	use::Rational R(7,14);
	std::cout << R << std::endl;

	use::Rational B;

	std::cin >> B;
	std::cout << B << std::endl;

	std::cout << R + B << std::endl;
	std::cout << R - B << std::endl;
	std::cout << R * B << std::endl;
	std::cout << R / B << std::endl;

	std::cout << (B+R).get_double() << std::endl;



	return 0;
}