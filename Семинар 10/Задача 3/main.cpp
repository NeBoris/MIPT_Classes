#include <iostream>


template <typename FUNC, typename ... Types>
void make_function(FUNC f, Types ... args)
{
	f(args...);
}


template <typename ... T>
void print(T ... args)
{
	(std::cout << ... << args);
}

int main()
{
	make_function([](int x, int y, int z) {std::cout << x + 1012 << " " << y << " " << z; }, 1, 2, 3);

	std::cout << std::endl;

	make_function(print<int, int, int>, 1, 2, 3);

	return 0;
}