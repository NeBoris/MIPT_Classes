#include <iostream>

enum class month {
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

int main() {
	int n;

	std::cout << "Choose the month and get number of its days: \n"
		<< "1 - January\n2 - February\n3 - March\n4 - April\n5 - May\n6 - June\n7 - July\n8 - August\n9 - September\n10 - October\n11 - November\n12 - December" << std::endl;

	std::cin >> n;
	month m = static_cast<month>(n - 1);

	switch (m) {
	case month::January:
	case month::March:
	case month::May:
	case month::July:
	case month::August:
	case month::October:
	case month::December:
		std::cout << 31;
		break;
	case month::February:
		std::cout << 28;
		break;
	case month::April:
	case month::June:
	case month::September:
	case month::November:
		std::cout << 30;
		break;
	}

	return 0;
}