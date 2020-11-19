#include <iostream>

template <typename _Ty>
struct decay
{
	using type = _Ty;
};

template <typename _Ty>
struct decay<_Ty&>
{
	using type = _Ty;
};

template <typename _Ty>
struct decay<_Ty&&>
{
	using type = _Ty;
};

template <typename _Ty>
struct decay<_Ty()>
{
	using type = _Ty*();
};

template <typename _Ty>
struct decay<_Ty[]>
{
	using type = _Ty*;
};

template <typename _Ty, std::size_t N>
struct decay<_Ty[N]>
{
	using type = _Ty*;
};

template <typename _Ty>
using decay_t = typename decay<_Ty>::type;

int main()
{
	std::cout << std::is_same_v<int, decay_t<int&>> << std::endl;
	std::cout << std::is_same_v<int&, decay_t<int&>> << std::endl;
	std::cout << std::is_same_v<int, decay_t<int&&>> << std::endl;
	std::cout << std::is_same_v<int&, decay_t<int&&>> << std::endl;
	std::cout << std::is_same_v<int&&, decay_t<int&&>> << std::endl;
	std::cout << std::is_same_v<int*(), decay_t<int()>> << std::endl;
	std::cout << std::is_same_v<int*, decay_t<int[]>> << std::endl;
	std::cout << std::is_same_v<int*, decay_t<int[5]>> << std::endl;

	return 0;
}