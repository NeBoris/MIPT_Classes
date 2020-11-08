#include <iostream>

template <typename T, typename ... Types>
void print(T arg, Types ... args) 
{
	std::cout << arg << std::endl;
	if (sizeof...(Types) > 0)
		print(args);
}

int main() {

	print(1, 3.123, 's');


	return 0;
}