#include <iostream>
#include <vector>
#include <functional>

double calculate(double x, double y, const std::function<double(double, double)>& f) {
	return f(x, y);
}

int main() {
	std::vector<std::function<double(double, double)>> v;

	v.push_back([](double x, double y) {return x + y; });
	v.push_back([](double x, double y) {return x * y; });
	v.push_back([](double x, double y) {return x / y; });
	v.push_back([](double x, double y) {return pow(x, y); });

	for (auto& c : v) {
		double result = calculate(4, 2, c);
		std::cout << result << "\n";

	}
	
	return EXIT_SUCCESS;
}