#include <iostream>
#include <vector>
#include <algorithm>
#include "Header.hpp"


//Book

const std::vector<std::string>& Book::pr_ow() const {
	return m_previous_owners;
}

//setter
void Book::take() {
	m_is_avaliable = false;
}
void Book::return_book() {
	m_is_avaliable = true;
}
void Book::add_owner(std::string name) {
	m_previous_owners.push_back(name);
}

//getters
bool Book::check_avaliability() const{
	return m_is_avaliable;
}
const std::string Book::get_name()& const {
	return m_name;
}



//Library

int Library::book_exists(const std::string& book_name) const {
	for (auto i = 0U; i < m_books.size(); ++i) {
		if (m_books[i].get_name() == book_name) {
			return i;
		}
	}
	return -1;
}

void Library::add_book(const std::string& book_name) {
	if (this->book_exists(book_name) == -1) {
		Book b(book_name);
		m_books.push_back(b);
		std::cout << "Book " << book_name << " added to the library!" << std::endl;
	}
	else {
		std::cout << "Book with this name already exists" << std::endl;
	}
}

void Library::take_book(const std::string& book_name, const std::string& owner_name) {
	int i = this->book_exists(book_name);
	if (i != -1 && m_books[i].check_avaliability()) {
		m_books[i].take();
		m_books[i].add_owner(owner_name);
		std::cout << "Here you are." << std::endl;
	}else{
		std::cout << "Book with this name doesn't exist or is already taken" << std::endl;	
	}
}

void Library::get_previous_owners(const std::string& book_name) const {
	int i = this->book_exists(book_name);
	if (i != -1) {
		for (const auto& g : m_books[i].pr_ow()) {
			std::cout << g << " ";
		}
		std::cout << std::endl;
	}else{
		std::cout << "Book with this name doesn't exist." << std::endl;
	}
}

void Library::return_book(const std::string& book_name) {
	int i = this->book_exists(book_name);
	if (i != -1) {
		m_books[i].return_book();
		std::cout << "Thank you!" << std::endl;
	}else{
		std::cout << "There was no book whith this name in our library." << std::endl;
	}
}

void Library::get_list() const {
	for (const auto& c : m_books) {
		if (c.check_avaliability()) {
			std::cout << c.get_name() << " ";
		}
	}
	std::cout << std::endl;
}
