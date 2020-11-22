#include <iostream>
#include <iomanip>

constexpr int factorial (int x)
{
	int value = 1;

	for (auto i = x; i >= 1; --i)
	{
		value *= i;
	}

	return value;
}

constexpr double exp(int N)
{
	double value = 0.0;

	for (auto i = 0; i < N; ++i)
	{
		value += 1.0/factorial(i);
	}

	return value;
}


int main()
{
	std::cout << std::fixed << std::setprecision(16) << exp(N) << std::endl;

	return 0;
}

