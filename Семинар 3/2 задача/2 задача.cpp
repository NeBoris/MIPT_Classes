#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::size_t N;


	std::cout << "Here you can sort your sequence in different ways. \n\nNow enter the number of elements: ";
	std::cin >> N;
	
	std::vector<double> s(N);

	std::cout << "\nEnter the array: ";
	for (auto& c : s) {
		std::cin >> c;
	}

	std::cout << "Choose the way to sort your array: \n"
		<< "1. In ascending order\n"
		<< "2. In descending order\n";

	std::cin >> N;

	switch (N) {
	case 1:
		std::sort(s.begin(), s.end(), [](auto lhs, auto rhs) {
			return lhs < rhs;
			});
		break;
	case 2:
		std::sort(s.begin(), s.end(), [](auto lhs, auto rhs) {
			return lhs > rhs;
			});
		break;
	
	}

	for (auto c : s) {
		std::cout << c << " ";
	}

	return 0;
}