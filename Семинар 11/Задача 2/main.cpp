#include <iostream>



template <typename _Ty>
struct add_const
{
	using type = const _Ty;
};

template <typename _Ty>
using add_const_t = typename add_const<_Ty>::type;




template <typename _Ty>
struct remove_const
{
	using type = _Ty;
};

template <typename _Ty>
struct remove_const<const _Ty>
{
	using type = _Ty;
};

template <typename _Ty>
using remove_const_t = typename remove_const<_Ty>::type;


class MY_class
{
public:
	MY_class(const int& a)
	{
		std::cout << "const" << std::endl;
	}

	MY_class(int& a)
	{
		std::cout << "no const" << std::endl;
	}

	/*void mr(int a)
	{
		std::cout << "Ok";
	}*/
};

int main()
{
	int x = 5;


	MY_class example = x;

	MY_class example2 = add_const_t<int>(x);
	

	const int y = 5;

	MY_class example3 = y;
	
	std::cout << std::is_const_v< remove_const_t<const int> > << std::endl;;


	MY_class example4 = remove_const_t<const int>(y); // I don't know why it doesn't works


	return 0;
}