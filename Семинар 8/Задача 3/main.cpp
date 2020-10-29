#include <iostream>
#include "Rational.hpp"
#include <stdexcept>
#include <exception>

int main() {
	try {
		use::Rational R(14, 7);
		std::cout << R << std::endl;

		R += use::Rational(5, 4);
		std::cout << R << std::endl;

	}
	catch (const std::exception& ex) {
		std::cerr << "Error: " << ex.what() << '\n';
	}

	return 0;
}