#include <iostream>
#include <thread>

template <typename FUNC>
void make_function(FUNC f){}

template <typename FUNC, typename T, typename ... Types>
void make_function(FUNC f, T arg, Types ... args)
{
	f(arg);
	make_function(f, args...);
}



void print(int arg)
{
	std::cout << arg << " ";
}

int main()
{
	make_function([](int x) {std::cout << x + 1012 << " "; }, 1, 2, 3);

	std::cout << std::endl;

	make_function(print, 1, 2, 3);

	return 0;
}