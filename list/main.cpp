#include <iostream>
#include <iomanip>


int main() {
	std::string name;
	int price, temperature;
	bool cash_back;


	//name
	std::cout << "Product's name: ";
	std::cin >> name;
	//price
	std::cout << "\nProduct's price: ";
	std::cin >> price;
	//cash_back
	std::cout << "\nIs cash-back available for this product? (true/false) ";
	std::cin >> std::boolalpha >> cash_back;
	//temperature
	std::cout << "\nMaximum storing temperature: ";
	std::cin >> temperature;

	//line consists 25 symbols

	std::cout << name << std::fixed <<  std::setprecision(5) << std::setfill('.')
			<< std::uppercase << std::hex << std::endl;
	std::cout << std::setw(17) << std::left << "Price:";
	std::cout << std::right << std::setfill('0') << std::setw(8) << price << std::endl;

	std::cout << "Has cash-back:" << std::setfill('.') << std::setw(11)
	<< std::boolalpha << cash_back << std::endl;

	std::cout << "Max temperature:" << std::setfill('.') << std::setw(9) <<
		 std::dec <<	std::showpos << temperature << std::endl;


	return 0;
}




