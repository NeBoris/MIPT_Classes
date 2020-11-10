#include <iostream>
#include <string>


template <typename T>
T g(std::size_t n) { return 0; }

template <typename T, typename ... Types>
T g(std::size_t n, T arg, Types... args)
{
	if(n == 0U)
		return arg;
	
	return g<T>(n - 1, args...);
}

template <typename T, typename ... Types>
T* make_f(Types... args)
{
	T* ret = new T[sizeof...(args)];
	for (auto i = 0U; i < sizeof...(args); ++i)
		ret[i] = g<T>(i, args...);


	return ret;
}

int main()
{
	std::string* pr = make_f<std::string>("hello", "world", "!");
	int* pr1 = make_f<int>(1, 2, 3);

	for(auto i = 0U; i < 3; ++i)
		std::cout << pr[i] << " ";

	std::cout << std::endl;

	for (auto i = 0U; i < 3; ++i)
		std::cout << pr1[i] << " ";

	delete[] pr;


	return 0;
}