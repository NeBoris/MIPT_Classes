#include <iostream>
#include <iomanip>

int main(){
	std::string name;
	int price, temperature;
	bool cash_back;

	std::cout << "Product's name: ";
	std::cin >> name;

	std::cout << "Product's price: ";
	std::cin >> price;

	std::cout << "Product's cash-back: ";
	std::cin >> std::boolalpha >> cash_back;

	std::cout << "Temperature: ";
	std::cin >> temperature;


	std::cout << name << "\n";
	std::cout << std::setw(17) << std::left << std::setfill('.') << "Price:";


	return 0;
}

