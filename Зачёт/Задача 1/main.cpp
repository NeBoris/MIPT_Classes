#include <iostream>
#include "complex.hpp"


int main()
{

	try
	{
		Compl::Complex C;
		Compl::Complex B(34, 5);

		std::cin >> C;

		std::cout << '\n' << C;
		std::cout << '\n' << C.Re();
		std::cout << '\n' << C.Im();
		std::cout << '\n' << C + B;
		std::cout << '\n' << C - B;
		std::cout << '\n' << C * B;
		std::cout << '\n' << C / B;


		C += B;
		std::cout << '\n' << C;
		C -= B;
		std::cout << '\n' << C;

		C *= B;
		std::cout << '\n' << C;
		C /= B;
		std::cout << '\n' << C;


		std::cout << '\n' << C.sopr();
		std::cout << '\n' << C.abs();
		std::cout << '\n' << (C == B);
		std::cout << '\n' << (C != B);

		std::cout << '\n' << C;

	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}





	return 0;
}