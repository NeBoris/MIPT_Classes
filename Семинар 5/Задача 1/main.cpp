#include <iostream>
#include <string>
#include "Header.hpp"


int main() {
	std::string name1, name2;
	int command;
	Library lib;
	bool flag = false;

	std::cout << "1 - Add new book to the library\n"
		<< "2 - Take book\n"
		<< "3 - return book\n"
		<< "4 - look at the list with previous owners of that book\n"
		<< "5 - have a list of our books\n"
		<< "6 - quit\n";
	

	while(true){
		std::cin >> command;

		switch (command)
		{
		case 1:
			std::cout << "Please, enter its name: ";
			std::cin >> name1;
			lib.add_book(name1);
			break;
		case 2:
			std::cout << "Please, enter its name and yours: ";
			std::cin >> name1 >> name2;
			lib.take_book(name1, name2);
			break;
		case 3:
			std::cout << "Please, enter its name: ";
			std::cin >> name1;
			lib.return_book(name1);
			break;
		case 4:
			std::cout << "Please, enter its name: ";
			std::cin >> name1;
			lib.get_previous_owners(name1);
			break;
		case 5:
			lib.get_list();
			break;
		case 6:
			flag = true;
			break;
		default:
			break;
		}

		if (flag) {
			break;
		}
	}

	return 0;
}