#include <iostream>

template <typename T>
struct decay
{
	using type = T&&;
};

int main()
{
	std::cout << std::is_same_v<int, decay<int&>> << std::endl;
}
