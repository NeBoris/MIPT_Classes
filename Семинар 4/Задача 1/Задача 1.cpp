#include <iostream>
#include <vector>
#include <string>

struct Book {
	Book(const std::string & new_name, const std::string & new_author = "No author", const int & new_year = 0) :
		name(new_name), author(new_author), year_of_manufacture(new_year)
	{
		//i do not know what to output
	}

	void change_owner(const std::string& new_owner) {
		owners.push_back(new_owner);
	}

	void all_owners() {
		for (const auto c : owners) {
			std::cout << c << std::endl;
		}
	}

	~Book(){
		//i do not know what to output
	}

	std::vector<std::string> owners;
	std::string name;
	std::string author;
	int year_of_manufacture;
};

enum class Commands {
	BOOK_LIST,
	ADD,
	TAKE,
	OWNERS_LIST,
	QUIT,
	SOMETHING_WRONG
};

int main() {
	std::vector<Book> library;
	std::string name;
	Commands command;
	int comm;

	std::cout << "Welcome to the library!\n"
		<< "Here you can:\n"
		<< "1 - Look at the list of our books\n"
		<< "2 - Add new book\n"
		<< "3 - Take one of the books we have\n"
		<< "4 - See the previous owners of that book\n"
		<< "5 - Quit\n"
		<< "Just write the number of one of points above \n and the name of a book (use \"_\" if there is more than one word in the name)\n";


	while (true) {

		std::cin >> comm;
		if (comm != 5 && comm != 1) {
			std::cin >> name;
		}

		Book new_book(name);
		std::string owner_name;
		bool quit = true;

		command = static_cast<Commands> (comm - 1);

		auto i = 0U;
		for (auto& c : library) {
			if (c.name == name) {
				quit = false;
				break;
			}
			++i;
		}

		if (comm != 1 && comm != 2 && comm != 5 && quit == true) {
			command = Commands::SOMETHING_WRONG;
		}
		quit = true;


		switch (command) {
		case Commands::BOOK_LIST:
			if (library.empty()) {
				std::cout << "No book yet" << std::endl;
				break;
			}

			for (const auto& c : library) {
				std::cout << c.name << "     ";
			}
			std::cout << std::endl;
			break;
		case Commands::ADD:
			std::cout << "Please, write the author, the year of manufacture and your name: ";
			std::cin >> new_book.author >> new_book.year_of_manufacture >> owner_name;
			new_book.owners.push_back(owner_name);
			
			std::cout << "New book \"" << name << "\" has been added." << std::endl;
			
			library.push_back(new_book);
			
			break;
		case Commands::TAKE:
			std::cout << "Please, write your name: ";
			std::cin >> owner_name;
			
			library[i].owners.push_back(owner_name);
			
			break;
		case Commands::OWNERS_LIST:
			library[i].all_owners();
			
			break;
		case Commands::QUIT:
			quit = false;
			
			break;
		default:
			std::cout << "Wrong command or book name" << std::endl;
			
			break;
		}

		if (quit == false) {
			break;
		}

	}

	return 0;
}