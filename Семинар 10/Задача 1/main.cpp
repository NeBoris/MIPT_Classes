#include <iostream>

template <typename ... Types>
std::size_t vol(Types ... args)
{
	return (sizeof(Types) + ...);
}


std::size_t vol_n() { return 0; }

template <typename T, typename ... Types>
std::size_t vol_n(T arg, Types ... args)
{
	std::size_t result = sizeof(arg) + vol_n(args...);
	return result;
}

int main() {
	std::cout << vol_n(12, 'q', 1.23);
	std::cout << vol(12, 'q', 1.23);

	return 0;
}