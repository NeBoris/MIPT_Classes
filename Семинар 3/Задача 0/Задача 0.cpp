#include <iostream>
#include <functional>
#include <vector>
#include <list>

void f(const std::vector<int> &v) {
	for (auto c : v) {
		std::cout << c << " ";
	}
}
void f(const std::list<int> l) {
	for (auto c : l) {
		std::cout << c << " ";
	}
}

void g(const float c) {
	std::cout << c;
}

void g(const double c) {
	std::cout << c;
}

void u(int x, std::function<double(double)> m) {
	std::cout << m(x);
}

void u(int x, std::function<double(float)> m) {
	std::cout << m(x);
}

int main() {
	f({ 1,2,3,4,5 });
	g(34);
	u(5, [](int x) {return x * x; });
	return 0;
}