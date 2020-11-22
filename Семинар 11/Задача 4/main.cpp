#include <iostream>

template <bool Condition, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T>
{
	using type = T;
};

template <bool Condition, typename T = void>
using enable_if_t = typename enable_if<Condition, T>::type;



#include <string>
#include <utility>

class Person
{
public:

	template < typename STR, typename Enable =
		enable_if_t < std::is_convertible_v < STR, std::string > > >
		explicit Person(STR&& str) : m_name(std::forward < STR >(str))
	{
		std::cout << "forward Person '" << m_name << "'\n";
	}

	Person(const Person& person) :
		m_name(person.m_name)
	{
		std::cout << "COPY-CTOR Person '" << m_name << "'\n";
	}

	Person(Person&& p) :
		m_name(std::move(p.m_name))
	{
		std::cout << "MOVE-CTOR Person '" << m_name << "'\n";
	}

	~Person() noexcept = default;

private:

	std::string m_name;
};


int main(int argc, char** argv)
{
	
	std::pair < int, double > p;

	std::string s = "Ivan";

	Person p1(s);
	Person p2("tmp");
	Person p3(p1);
	Person p4(std::move(p1));

	system("pause");

	return EXIT_SUCCESS;
}
