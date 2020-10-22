#pragma once
#include <vector>
#include <iostream>

namespace test_class {
	class Temp {

	public:
		//constructor #0
		Temp();
		//constructor #1
		Temp(int* a, int lenght);
		//constructor #2
		Temp(const std::vector<int>& v);

		~Temp() = default;

		friend std::ostream& operator<<(std::ostream& stream, const Temp& t);
		friend std::istream& operator>>(std::istream& stream, Temp& t);

		//copy
		Temp& operator=(const Temp& t);

		//move
		Temp& operator=(Temp&& t);

		bool operator==(const Temp& t);

		Temp&& operator+(const Temp& t);
		Temp&& operator-(const Temp& t);
	private:
		int* m_a;;
		std::size_t m_lenght;
		std::vector<int> m_v;
	};
}