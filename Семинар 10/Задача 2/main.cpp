#include <iostream>
#include <string>


template <typename T>
T* make_f(T arg)
{
	return new T(arg);
}

int main()
{
	std::string* pr = make_f(static_cast<std::string>("hello"));
	int* pr1 = make_f(1);

	std::cout << *pr << std::endl;

	std::cout << *pr1;

	delete pr;
	delete pr1;


	return 0;
}