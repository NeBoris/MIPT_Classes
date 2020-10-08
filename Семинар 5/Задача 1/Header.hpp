#pragma once
#include <iostream>
#include <vector>

class Book {
public:
	Book(const std::string & new_name) :
		m_name(new_name), m_is_avaliable(true){}

	std::vector<std::string> pr_ow() const;

	//setter
	void take();
	void return_book();
	void add_owner(std::string name);

	//getters
	bool check_avaliability() const;
	std::string get_name() const;


private:
	std::string m_name;
	std::vector<std::string> m_previous_owners;
	bool m_is_avaliable;
};

class Library {
public:
	Library() {
		std::cout << "Welcome to our library!" << std::endl;
	}

	void add_book(const std::string& book_name);

	void take_book(const std::string& book_name, const std::string& owner_name);

	void return_book(const std::string& book_name);

	void get_previous_owners(const std::string& book_name) const;

	int book_exists(const std::string& book_name) const;

	void get_list() const;

private:
	std::vector<Book> m_books;

};

