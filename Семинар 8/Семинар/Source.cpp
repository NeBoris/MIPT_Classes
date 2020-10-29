#include <algorithm>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

int f() {
	std::vector<int> a(10,0);
	std::vector<int> b(15,0);

	for (auto i = 0U; i < 10; ++i) {
		a[i] = i;
		b[i + 2] = i;
	}

	if (b[0] == b[1]) {
		throw std::invalid_argument("In f dfkjfghk");
	}

	
	return 1;
}

int g() {
	//throw std::invalid_argument("In g dfkjfghk");

	return 1;
}

int main()
{
	try {
		g();
		f();
	}
	catch (const std::invalid_argument& ia) {
		std::cout << "There is an error. " << ia.what() << std::endl;
	}

	return EXIT_SUCCESS;
}