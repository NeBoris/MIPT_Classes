#include <iostream>


template <std::size_t N>
struct Fibonachi
{
	static const std::size_t value = Fibonachi<N - 1>::value + Fibonachi<N - 2>::value;
};

template <>
struct Fibonachi<0>
{
	static const std::size_t value = 0;
};

template <>
struct Fibonachi<1>
{
	static const std::size_t value = 1;
};

int main()
{
	int g1 = Fibonachi<0>::value;
	int g2 = Fibonachi<1>::value;
	int g3 = Fibonachi<2>::value;
	int g4 = Fibonachi<7>::value;

	std::cout << g1 << " " << g2 << " " << g3 << " " << g4 << std::endl;


	return 0;
}