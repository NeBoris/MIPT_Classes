<<<<<<< HEAD
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

=======
#include <iostream>
#include "Header.hpp"

namespace use {
	Example::Example() :
		m_arr(nullptr), m_size(0), m_vec(0){}


	Example::Example(int a) :
		m_arr(&a), m_size(1), m_vec(0){}


	Example::Example(int* array, int its_size) :
		m_size(its_size), m_vec(0) {
		if (array)
		{
			m_arr = new int[m_size];
			for (auto i = 0U; i < m_size; ++i)
				m_arr[i] = array[i];
		}
		else {
			m_size = 0;
			m_arr = nullptr;
		}
	}


	Example::Example(const std::vector<int>& vec) :
		m_vec(vec), m_arr(nullptr), m_size(0){}


	Example::Example(const Example& other) :
		m_vec(other.m_vec), m_size(other.m_size) {
		m_arr = new int[m_size];
		for (auto i = 0U; i < m_size; ++i)
			m_arr[i] = other.m_arr[i];
	}


	Example::Example(Example&& other) :
		m_size(other.m_size), m_vec(other.m_vec), m_arr(other.m_arr) {
		

		other.m_arr = nullptr;
		other.m_size = 0;
		other.m_vec.clear();
	}

	std::ostream& operator<<(std::ostream& stream, const Example& a) {
		for (auto i = 0U; i < a.m_size; ++i) {
			stream << a.m_arr[i] << " ";
		}
		stream << '\n';
		for (auto& c : a.m_vec) {
			stream << c << " ";
		}

		return stream;
	}

	Example& Example::operator=(const Example& other) {
		if (this == &other) return *this;

		if (m_arr != nullptr)
			delete[] m_arr;

		m_size = other.m_size;
		m_vec = other.m_vec;
		if (other.m_arr)
		{
			m_arr = new int[m_size];
			for (auto i = 0U; i < m_size; ++i)
				m_arr[i] = other.m_arr[i];
		}
		else {
			m_size = 0;
			m_arr = nullptr;
		}

		return *this;
	}
	Example& Example::operator=(Example&& other) {
		if (this == &other) return *this;

		if (m_arr != nullptr)
			delete[] m_arr;

		m_size = other.m_size;
		m_vec = other.m_vec;
		if (other.m_arr)
		{
			m_arr = new int[m_size];
			for (auto i = 0U; i < m_size; ++i)
				m_arr[i] = other.m_arr[i];
		}
		else {
			m_size = 0;
			m_arr = nullptr;
		}

		other.m_arr = nullptr;
		other.m_size = 0;
		other.m_vec.clear();

		return *this;
	}

	Example& Example::operator+=(const Example& other) {
		for (const auto& c : other.m_vec) {
			m_vec.push_back(c);
		}
		return *this;
	}
	Example& Example::operator+=(int* a) {
		m_arr = a;
		return *this;
	}
	Example& Example::operator+=(int size) {
		m_size = size;
		return *this;
	}
	Example& Example::operator+=(const std::vector<int>& vec) {
		for (const auto& c : vec) {
			m_vec.push_back(c);
		}
		return *this;
	}

	bool operator==(const Example& lhs, const Example& rhs) {
		return (lhs.m_vec == rhs.m_vec);
	}
>>>>>>> d6953e1dbe85584ecf302f53660b871210421273
}