#include "Class.hpp"
#include <iostream>
#include <vector>

namespace test_class {

	//constructor #0
	Temp::Temp() :
		m_a(nullptr), m_lenght(0)
	{}
	//constructor #1
	Temp::Temp(int* a, int lenght) :
		m_a(a), m_lenght(lenght){}
	//constructor #2
	Temp::Temp(const std::vector<int>& v):
		m_v(v), m_a(nullptr), m_lenght(0){}

	Temp::~Temp() = default;

	std::ostream& operator<<(std::ostream& stream, const Temp& t) {
		
	}
	std::istream& operator>>(std::istream& stream, Temp& t) {
		int *c = new int[]
	}

	//copy
	Temp& operator=(const Temp& t);

	//move
	Temp& operator=(Temp&& t);

	bool operator==(const Temp& t);

	Temp&& operator+(const Temp& t);
	Temp&& operator-(const Temp& t);

}