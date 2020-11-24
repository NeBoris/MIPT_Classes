#include <iostream>
#include <array>


template < int N>
constexpr int prime()
{
	std::array<int, N> arr = {};
	arr[0] = 2;

	for(auto k = 3; arr[arr.size() - 1] == 0; ++k)
	{
		unsigned int i = 0U;
		for (; (arr[i] != 0) && (i < arr.size()) && (k % arr[i] != 0) ; ++i){}

		if (arr[i] == 0)
		{
			arr[i] = k;
		}
	}


	return arr[N - 1];
}


int main()
{
	constexpr int a1 = prime<3>();
	constexpr int a2 = prime<4>();
	constexpr int a3 = prime<7>();
	constexpr int a4 = prime<13>();
	constexpr int a5 = prime<23>();
	constexpr int a6 = prime<25>();
	constexpr int a7 = prime<50>();
	

	std::cout << "3(5): " << a1 << std::endl;
	std::cout << "4(7): " << a2 << std::endl;
	std::cout << "7(17): " << a3 << std::endl;
	std::cout << "13(41): " << a4 << std::endl;
	std::cout << "23(83): " << a5 << std::endl;
	std::cout << "25(97): " << a6 << std::endl;
	std::cout << "50(229): " << a7 << std::endl;

	return 0;
}