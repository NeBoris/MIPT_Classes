#include <iostream>
#include <memory>
#include <iomanip>

template <typename T, typename ... Types>
struct is_function  : std::false_type {};



template <typename T, typename ... Types>
struct is_function <T(Types...)> : std::true_type 
{
	using _Tz = T;
};

template <typename T>
inline constexpr bool is_function_v = is_function < T >::value;

int main() {
	
	std::cout << std::boolalpha <<  is_function_v < int(int) >  << std::endl << is_function_v < int > << std::endl << is_function_v<std::string>;

	return 0;
}