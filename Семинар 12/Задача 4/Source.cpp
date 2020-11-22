#include <iostream>

constexpr bool check_is_prime(int a, int k)
{
	return (k > 1 ? ((a % k == 0 ? false : true) && check_is_prime(a, k - 1)) : true);
}

constexpr bool is_prime(int a)
{
	return check_is_prime(a, a / 2);
}

constexpr int prime(int a)
{
	int value = 1;

	while (a != 0)
	{
		value++;
		if (is_prime(value))
			--a;
	}

	return value;
}


int main()
{
	constexpr int a1 = prime(3);
	constexpr int a2 = prime(4);
	constexpr int a3 = prime(7);
	constexpr int a4 = prime(13);
	constexpr int a5 = prime(23);
	constexpr int a6 = prime(25);
	constexpr int a7 = prime(50);
	

	std::cout << "3(5): " << a1 << std::endl;
	std::cout << "4(7): " << a2 << std::endl;
	std::cout << "7(17): " << a3 << std::endl;
	std::cout << "13(41): " << a4 << std::endl;
	std::cout << "23(83): " << a5 << std::endl;
	std::cout << "25(97): " << a6 << std::endl;
	std::cout << "50(229): " << a7 << std::endl;

	return 0;
}