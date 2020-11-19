#include <iostream>
#include <string>

class Ex
{
public:
	Ex(int n, double s) :
		m(n), m_s(s) {}
	void text()
	{
		std::cout << "Hello!";
	}
private:
	int m;
	double m_s;
};

template <typename RT, typename T, typename ... Types>
RT* make_f(T arg, Types ... args)
{
	return new RT( arg, ( args , ... ) );
}

int main()
{
	std::string* pr = make_f<std::string>("hello");
	int* pr1 = make_f<int>(1);

	Ex* pr2 = make_f<Ex>(2, 34.46);

	std::cout << *pr << std::endl;

	std::cout << *pr1 << std::endl;
	//(*pr2).text();

	delete pr;
	delete pr1;


	return 0;
}