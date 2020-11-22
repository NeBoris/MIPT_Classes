#include <iostream>


template <int arg1, int arg2>
struct bin_coeff
{
	static const int value = bin_coeff<arg1 - 1, arg2 - 1>::value + bin_coeff<arg1 - 1, arg2>::value;
};

template <int arg>
struct bin_coeff<arg, arg>
{
	static const int value = 1;
};

template <int arg>
struct bin_coeff<arg, 0>
{
	static const int value = 1;
};


int main()
{
	int g = bin_coeff<15, 2>::value;

	std::cout << g;

	return 0;
}