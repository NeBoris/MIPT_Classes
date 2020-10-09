#include <iostream>
#include <string>
#include "Header.hpp"

enum class Command{
	Add,
	Take,
	Ret,
	Owners_List,
	Books,
	Quit
}

int main() {
	std::string name1, name2;
	Command command;
	int b;
	Library lib;
	bool flag = false;

	std::cout << "1 - Add new book to the library\n"
		<< "2 - Take book\n"
		<< "3 - return book\n"
		<< "4 - look at the list with previous owners of that book\n"
		<< "5 - have a list of our books\n"
		<< "6 - quit\n";
	

	while(true){
		std::cin >> b;
		command = static_cast<Command> (b);
		
		switch (command)
		{
		case Command::Add:
			std::cout << "Please, enter its name: ";
			std::cin >> name1;
			lib.add_book(name1);
			break;
		case Command::Take:
			std::cout << "Please, enter its name and yours: ";
			std::cin >> name1 >> name2;
			lib.take_book(name1, name2);
			break;
		case Command::Ret:
			std::cout << "Please, enter its name: ";
			std::cin >> name1;
			lib.return_book(name1);
			break;
		case Command::Owners_List:
			std::cout << "Please, enter its name: ";
			std::cin >> name1;
			lib.get_previous_owners(name1);
			break;
		case Command::Books:
			lib.get_list();
			break;
		case Command::Quit:
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
