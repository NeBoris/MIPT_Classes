#include <iostream>
#include <array>


template < int N>
constexpr int prime()
{
	std::array<int, N> arr = {};
	arr[0] = 2;

	for (auto k = 0U; k < arr.size() - 1; ++k)
	{
		for (auto j = arr[k] + 1; ; ++j)
		{



			bool flag = true;
			for (auto i = 0U; i <= k; ++i)
			{
				if (j % arr[i] == 0)
				{
					flag = false;
					break;
				}
			}

			if (flag == true)
			{
				arr[k + 1] = j;
				break;
			}
			



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