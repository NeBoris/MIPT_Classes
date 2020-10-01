#include <iostream>
#include <string>

struct Person{
	Person(const std::string& new_name, std::size_t a, int s) :
		name(new_name), age(a), salary(s)
	{}


	std::string name;
	std::size_t age;
	int salary;
};

int main() {
	Person Boris = { "Perfect_Man", 19, 100000000000 };


	return 0;
}