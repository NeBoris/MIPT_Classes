#include <iostream>

template <bool Condition, typename _Ty = void>
struct enable_if
{
	using value = void*;
};

template <typename _Ty>
struct enable_if<std::true_type::value, _Ty>
{
	using value = _Ty;
};

template <bool Condition, typename _Ty = void>
using enable_if_t = typename enable_if<Condition, _Ty>::value;



int main()
{
	std::cout << std::is_same_v<int, enable_if_t<std::true_type::value, int>  > << std::endl;
	std::cout << std::is_same_v<int, enable_if_t<std::false_type::value, int>  > << std::endl;


	return 0;
}