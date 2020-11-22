#include <iostream>
#include <iomanip>

constexpr double factorial (int x)
{
	double value = 1;

	for (auto i = x; i >= 1; --i)
	{
		value *= i;
	}

	return value;
}

constexpr double exp()
{
	double value = 0;

	for (auto i = 0U; i < 20; ++i)
	{
		value += 1/factorial(i);
	}

	return value;
}


int main()
{
	std::cout << std::fixed << std::setprecision(16) << exp() << std::endl;

	return 0;
}

