#include <iostream>

struct Er {
	union {
		unsigned int error;
		int result;
	} ret;
	bool info = true;
};


Er&& foo(int a) {
	Er obj1;

	if (a == 1) {
		obj1.ret.result = 1456;
	}
	else if (a < 1) {
		obj1.ret.error = 4;
		obj1.info = false;
	}
	else {
		obj1.ret.error = 1;
		obj1.info = false;
	}

	return std::move(obj1);
}

int main() {
	int a;
	std::cin >> a;
	if (foo(a).info == false) {
		std::cout << "Error: " << foo(a).ret.error;
	}
	else {
		std::cout << foo(a).ret.result;
	}

	return 0;
}