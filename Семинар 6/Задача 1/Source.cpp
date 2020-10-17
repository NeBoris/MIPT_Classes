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


	Example::Example(std::vector<int> vec) :
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

	bool operator==(const Example& lhs, const Example& rhs) {
		return (lhs.m_vec == rhs.m_vec);
	}
}